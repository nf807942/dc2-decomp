#!/usr/bin/env python3
"""Mesure des formes de Init autour du site d'appel scePadPortOpen.

Le commerce place `addiu a2, a2, %lo(pad_dma_buf2)` dans le créneau du jal,
nous y plaçons le `daddu a1` du slot. Chaque variante change la manière dont
les arguments constants sont fabriqués, pour voir laquelle fait reculer
l'ordonnancement du commerce.
"""
from __future__ import annotations
import re, sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "diff"))
from permute import Scorer  # noqa: E402

SYMBOL = "Init__8CGamePadFv"
scorer = Scorer(SYMBOL)
whole = scorer.source.read_text(encoding="utf-8")
marks = re.compile(r"/\* @@" + re.escape(SYMBOL) + r" \*/\n(.*?)/\* @@fin \*/",
                   re.DOTALL)
found = marks.search(whole)

TAIL = """void CGamePad::Init() {
    int i;
    int j;

    m_unk45C = 0;
    m_muteSecond = 0;
    m_vibration = 1;
    m_vibTime = 0;
    m_unk470 = 0;
    m_unk474 = 0;
    while (sceGsSyncV(0) == 0) {
    }
    scePadInit(0);

    m_unk134[0] = 0;
    m_unk134[1] = 0;
    m_unk134[2] = 0;
    m_unk134[3] = 0;
    for (i = 0; i < 2; i++) {
        m_pad[i].phase = 0;
        m_pad[i].btns = 0;
        m_pad[i].ry = 0;
        m_pad[i].rx = 0;
        m_pad[i].ly = 0;
        m_pad[i].lx = 0;
        /* L'indice du port sert aussi d'indice d'actionneur : pour le port 1,
         * la remise à zéro tombe donc sur le second minuteur et non sur le
         * premier. C'est ce que le binaire fait, et `Step` décompte pourtant
         * les deux. */
        for (j = 0; j < 6; j++) {
            m_pad[i].act[j] = 0;
            m_pad[i].actTime[i] = 0;
        }
        m_stickRange[i] = 0;
        m_repeat[i].down = 0;
        m_repeat[i].repeat = 0;
        for (j = 0; j < 32; j++) {
            m_repeat[i].wait[j] = 0;
            m_repeat[i].count[j] = 0;
            m_repeat[i].period[j] = 0;
        }
    }

"""


def calls(port0, slot0, buf0, port1, slot1, buf1, test="=="):
    """Les deux appels à scePadPortOpen avec les arguments donnés."""
    def cond(call, rhs):
        if test == "==":
            return f"{call} == {rhs}"
        return f"!({call})"
    return (
        f"    if ({cond(f'scePadPortOpen({port0}, {slot0}, {buf0})', '0')}) {{\n"
        "        printf(_248);\n"
        "        return;\n"
        "    }\n"
        "    sceGsSyncV(0);\n"
        "    sceGsSyncV(0);\n"
        f"    if ({cond(f'scePadPortOpen({port1}, {slot1}, {buf1})', '0')}) {{\n"
        "        printf(_248);\n"
        "        return;\n"
        "    }\n"
        "    sceGsSyncV(0);\n"
        "    sceGsSyncV(0);\n"
        "}"
    )


def with_decl(decl, body):
    return decl + body


def port_var():
    return (
        "    int port = 0;\n"
        "    if (scePadPortOpen(port, 0, pad_dma_buf) == 0) {\n"
        "        printf(_248);\n"
        "        return;\n"
        "    }\n"
        "    sceGsSyncV(0);\n"
        "    sceGsSyncV(0);\n"
        "    port = 1;\n"
        "    if (scePadPortOpen(port, 0, pad_dma_buf2) == 0) {\n"
        "        printf(_248);\n"
        "        return;\n"
        "    }\n"
        "    sceGsSyncV(0);\n"
        "    sceGsSyncV(0);\n"
        "}"
    )


def all_vars():
    return (
        "    int port = 0;\n"
        "    int slot = 0;\n"
        "    u8 *buf0 = pad_dma_buf;\n"
        "    if (scePadPortOpen(port, slot, buf0) == 0) {\n"
        "        printf(_248);\n"
        "        return;\n"
        "    }\n"
        "    sceGsSyncV(0);\n"
        "    sceGsSyncV(0);\n"
        "    port = 1;\n"
        "    buf0 = pad_dma_buf2;\n"
        "    if (scePadPortOpen(port, slot, buf0) == 0) {\n"
        "        printf(_248);\n"
        "        return;\n"
        "    }\n"
        "    sceGsSyncV(0);\n"
        "    sceGsSyncV(0);\n"
        "}"
    )


variants = {
    # La forme départ : les littéraux, comme le commerce les écrit.
    "depart": calls("0", "0", "pad_dma_buf", "1", "0", "pad_dma_buf2"),
    # Diagnostic : les deux constantes échangées (faux sémantiquement) —
    # le permuteur a trouvé 97,32 % ici.
    "swap2": calls("0", "0", "pad_dma_buf", "0", "1", "pad_dma_buf2"),
    # Le port en variable, réaffecté à 1 avant le second appel.
    "port_var": port_var(),
    # Le slot en variable, partagé par les deux appels.
    "slot_var": calls("0", "slot", "pad_dma_buf", "1", "slot", "pad_dma_buf2",
                      ).replace("    if (scePadPortOpen(0, slot",
                                "    int slot = 0;\n    if (scePadPortOpen(0, slot"),
    # Le tampon en variable : le pointeur tient dans un registre, et l'appel
    # ne refait pas lui+addiu.
    "buf_var": calls("0", "0", "buf", "1", "0", "pad_dma_buf2",
                     ).replace("    if (scePadPortOpen(0, 0, buf)",
                               "    u8 *buf = pad_dma_buf;\n    if (scePadPortOpen(0, 0, buf)"),
    # Les deux tampons en variables distinctes.
    "buf_vars": calls("0", "0", "buf0", "1", "0", "buf1").replace(
        "    if (scePadPortOpen(0, 0, buf0)",
        "    u8 *buf0 = pad_dma_buf;\n    u8 *buf1 = pad_dma_buf2;\n    if (scePadPortOpen(0, 0, buf0)"),
    # Tout en variables.
    "all_vars": all_vars(),
    # Le résultat pris dans une variable avant le test.
    "ret_var": (
        "    int r = scePadPortOpen(0, 0, pad_dma_buf);\n"
        "    if (r == 0) {\n"
        "        printf(_248);\n"
        "        return;\n"
        "    }\n"
        "    sceGsSyncV(0);\n"
        "    sceGsSyncV(0);\n"
        "    r = scePadPortOpen(1, 0, pad_dma_buf2);\n"
        "    if (r == 0) {\n"
        "        printf(_248);\n"
        "        return;\n"
        "    }\n"
        "    sceGsSyncV(0);\n"
        "    sceGsSyncV(0);\n"
        "}"),
    # Le cast explicite de l'adresse.
    "cast_addr": calls("0", "0", "(u8 *)pad_dma_buf", "1", "0", "(u8 *)pad_dma_buf2"),
    # L'adresse par indice.
    "index_addr": calls("0", "0", "&pad_dma_buf[0]", "1", "0", "&pad_dma_buf2[0]"),
    # La négation du résultat.
    "not_bang": calls("0", "0", "pad_dma_buf", "1", "0", "pad_dma_buf2", test="!"),
    # Le bloc de succès explicite (sinon, les syncs).
    "else_syncs": (
        "    if (scePadPortOpen(0, 0, pad_dma_buf) == 0) {\n"
        "        printf(_248);\n"
        "        return;\n"
        "    } else {\n"
        "        sceGsSyncV(0);\n"
        "        sceGsSyncV(0);\n"
        "    }\n"
        "    if (scePadPortOpen(1, 0, pad_dma_buf2) == 0) {\n"
        "        printf(_248);\n"
        "        return;\n"
        "    } else {\n"
        "        sceGsSyncV(0);\n"
        "        sceGsSyncV(0);\n"
        "    }\n"
        "}"),
    # La condition inversée : succès dans la branche alors.
    "inverted": (
        "    if (scePadPortOpen(0, 0, pad_dma_buf) != 0) {\n"
        "        sceGsSyncV(0);\n"
        "        sceGsSyncV(0);\n"
        "    } else {\n"
        "        printf(_248);\n"
        "        return;\n"
        "    }\n"
        "    if (scePadPortOpen(1, 0, pad_dma_buf2) != 0) {\n"
        "        sceGsSyncV(0);\n"
        "        sceGsSyncV(0);\n"
        "    } else {\n"
        "        printf(_248);\n"
        "        return;\n"
        "    }\n"
        "}"),
    # Le port et le slot en variables, les tampons littéraux.
    "port_slot_vars": (
        "    int port = 0;\n"
        "    int slot = 0;\n"
        "    if (scePadPortOpen(port, slot, pad_dma_buf) == 0) {\n"
        "        printf(_248);\n"
        "        return;\n"
        "    }\n"
        "    sceGsSyncV(0);\n"
        "    sceGsSyncV(0);\n"
        "    port = 1;\n"
        "    if (scePadPortOpen(port, slot, pad_dma_buf2) == 0) {\n"
        "        printf(_248);\n"
        "        return;\n"
        "    }\n"
        "    sceGsSyncV(0);\n"
        "    sceGsSyncV(0);\n"
        "}"),
    # Le slot en variable, et l'adresse du tampon en dépend : MWCC doit
    # l'évaluer après le slot, le créneau lui revient peut-être.
    "slot_indexed": with_decl("    int slot = 0;\n",
        calls("0", "slot", "&pad_dma_buf[slot]", "1", "slot", "&pad_dma_buf2[slot]")),
    # La même, le port dérivé du slot.
    "port_indexed": with_decl("    int slot = 0;\n",
        calls("slot + 1", "slot", "&pad_dma_buf[slot]", "slot + 1", "slot",
              "&pad_dma_buf2[slot]")),
}

for name, body in variants.items():
    scorer.source.write_text(
        whole[:found.start(1)] + TAIL + body + whole[found.end(1):], encoding="utf-8")
    score = scorer.score()
    print(f"{name:16s} {score:6.2f} %", flush=True)

scorer.source.write_text(
    whole[:found.start(1)] + TAIL + variants["depart"] + whole[found.end(1):],
    encoding="utf-8")
print("départ restauré", flush=True)
