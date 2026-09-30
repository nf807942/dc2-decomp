# Méthode : fournées d'agents et boucle d'amélioration de l'outillage

Établie le 30 septembre 2026 sur quatre fournées (voir les chiffres plus bas).
Elle complète `docs/PLAN_TROIS_MOIS.md` ; celui-ci dit *combien*, ce document
dit *comment*, pour qu'une session future la reprenne sans rien redécouvrir.

## Le principe

Deux boucles imbriquées, et la seconde est ce qui fait progresser la première :

1. **Boucle de production** : un orchestrateur réserve des fonctions, un agent
   les reconstruit, l'orchestrateur vérifie l'image.
2. **Boucle d'outillage** : chaque rapport d'agent est lu pour ce qu'il dit
   *de l'outillage* — essais perdus, contexte manquant, idiome nouveau — et
   l'orchestrateur corrige l'outil ou consigne l'idiome **avant** la fournée
   suivante. Un essai perdu deux fois pour la même raison est un défaut d'outil,
   non un défaut d'agent.

## Rôles et limites

- **Orchestrateur** (la session principale) : réserve, lance, vérifie
  (`make build`), consigne, corrige l'outillage. Seul à toucher à `make build`,
  aux en-têtes, aux structures d'unité, à `scripts/` et à la documentation.
- **Agent** : reconstruit ses fonctions par `soumettre.py` seulement. Il
  n'édite aucune source, ne lance ni `make build` ni git.
- **Un seul agent à la fois** tant que l'outillage bouge ; au plus **5** en
  parallèle sinon (limite de crédit de session, mémoire
  `dc2-affinage-par-agents`), avec un rapport entre deux fournées.
- Si Docker tombe, `soumettre.py` sort en code 4 : ne pas relancer d'agent avant
  qu'il réponde.

## Boucle de production, pas à pas

```
make dossier ARGS="--suivant 6 --agent aN --min 256 --max 1024"   # réserve
   → lancer l'agent (prompt ci-dessous)
   → make build                       # verdict : « identique au disque »
   → make dossier ARGS="--libere aN"  # rend les réservations
   → make etat                        # le nouveau compte
```

- La file range : jet 85–100 % d'abord, puis sœur écrite (≥ 0,7), puis courtes.
  Les quasi-succès qui ont épuisé leurs 12 essais reviennent en tête ; les
  garer par une réservation d'un agent fictif (`garde`, heure lointaine dans
  `progress/reservations.json`) pour que l'agent suivant n'y retombe pas.
- Un lot de 6 fonctions de 256 à 268 octets a coûté à un agent 5 à 13 minutes.
- Si `make build` diverge : retrouver la fonction fautive par `nm` contre
  `config/elf_symbol_addrs.txt` et la remettre sous `INCLUDE_ASM`.

## Le prompt de l'agent (gabarit)

À adapter : numéro d'agent, liste de symboles, tailles, chemin du bloc-notes.

> Tu travailles sur la décompilation matching de Dark Chronicle (PS2) dans
> `C:\Users\forge\Documents\Projets\darkcloud2` (lis `CLAUDE.md` à la racine,
> surtout « Ce que MWCC fait d'une forme de C » ; `docs/IDIOMES_MWCC.md` quand
> un écart résiste). Réponds en français. Utilise Bash (Git Bash), pas
> PowerShell.
>
> Ta tâche : reconstruire en C++ les N fonctions que l'orchestrateur t'a
> réservées (agent aN), de X à Y octets : <symboles>.
>
> Méthode, par fonction :
> 1. `python scripts/build/dossier.py <symbole>` : jet existant à corriger,
>    sœurs écrites, appelés, section « déclarations visibles » (ce qu'il faut
>    déclarer dans l'essai, avec un modèle ; seul compte ce qui précède la
>    fonction dans l'unité ; une signature déjà posée est imposée),
>    désassemblage.
> 2. Écris ton essai dans un fichier HORS du dépôt (dossier `scratchpad/aN/`).
>    Il contient la définition de la fonction (nom manglé en `extern "C"` comme
>    les voisines de l'unité) précédée des déclarations qu'elle réclame. Le jet
>    m2c propose parfois des `typedef struct X_infere` : n'en garde que si
>    l'unité ne définit pas déjà X (« redefined » fait échouer l'unité). Donne
>    aux structures de l'essai un nom neuf par fonction.
> 3. `python scripts/build/soumettre.py <symbole> <fichier>` (≈ 5 s,
>    conteneur). À 100 % la fonction est gardée ; sinon la source est rétablie
>    et le diff instruction par instruction t'est rendu : lis-le, nomme la
>    cause (`CLAUDE.md` et `IDIOMES_MWCC.md` en donnent beaucoup : ordre des
>    arguments, pas de pointeur, registres, sorties dupliquées, ordre de
>    déclaration…), corrige, resoumets. Codes de sortie : 4 = conteneur
>    indisponible (arrête-toi et signale-le) ; 5 = déclarations manquantes
>    (rien décompté, complète l'essai) ; 3 = plafond d'essais. Au plus 12
>    essais par fonction ; ensuite passe à la suivante en notant l'écart
>    restant.
>
> Règles strictes : tu ne lances JAMAIS `make build`, ni git
> add/commit/stash/checkout, et n'édites aucune source à la main — seul
> `soumettre.py` touche aux sources. Ne modifie ni `scripts/`, ni `config/`, ni
> `include/`. Une seule commande de conteneur à la fois. N'écris aucun fichier
> dans le dépôt en dehors de ce que `soumettre.py` écrit. Si le crédit ou le
> temps te manque, conclus et rends le rapport de ce qui est fait.
>
> Rapport final (court, en français), par fonction : symbole, nombre d'essais,
> score final, gardée oui/non, et pour les échecs la cause présumée avec
> l'écart restant. Ajoute : ce que le dossier a apporté ou non, ce qui a
> manqué à l'outillage, et les idiomes MWCC nouveaux établis (avec la fonction
> témoin), pour que l'orchestrateur les consigne.

Les deux dernières demandes du rapport nourrissent la boucle d'outillage : sans
elles l'agent ne dit pas ce qui lui a coûté.

## Boucle d'outillage, pas à pas

À chaque rapport :

1. **Extraire** trois listes : idiomes nouveaux, essais perdus (avec leur cause),
   ce qui a manqué.
2. **Idiomes** → `docs/IDIOMES_MWCC.md`, une entrée par idiome avec sa fonction
   témoin et le score avant/après.
3. **Essais perdus** → reproduire le défaut avant de corriger. Le rapport dit un
   symptôme, pas une cause ; deux corrections de cette session n'ont tenu que
   parce que le défaut a été reproduit sur l'état d'origine de l'unité (on
   remet la source d'avant, on lance l'outil, on constate).
4. **Vérifier la correction sur ce même cas**, puis `python -m py_compile` sur
   les scripts touchés.
5. **Blocages de structure** (un type opaque comme `EdEventInfo_keep`) → c'est
   à l'orchestrateur : ajouter le champ réel à la déclaration de l'unité sans
   changer la taille, resoumettre l'essai de l'agent, puis `make build`.

## Ce que les outils font

| Commande | Rôle |
|---|---|
| `make dossier ARGS="<sym>"` | Jet existant, sœurs écrites, appelés, déclarations visibles avant la fonction (signature ou type imposés), désassemblage |
| `make dossier ARGS="--suivant N --agent x [--min a --max b]"` | Réserve N fonctions (expiration 6 h) |
| `make dossier ARGS="--libere x"` / `--file` | Rend les réservations / montre la file |
| `make soumettre ARGS="<sym> essai.cpp"` | Pose, mesure (~5 s), garde à 100 % ou rétablit. Codes 0 gardée, 1 rendue, 2 introuvable, 3 plafond, 4 conteneur, 5 déclarations |
| `soumettre … --table` | Fonction à table de saut : garde dès 99,9 %, `make build` tranche |
| `make similaires` | Sœurs écrites de chaque fonction restante |
| `progress/essais.jsonl` | Journal des essais : symbole, score, gardée (un essai sans mesure n'use pas le plafond) |

## Pièges rencontrés (à ne pas refaire)

- **Un `\b` dans une chaîne Python non brute est un retour arrière (0x08).** Le
  contrôle d'ordre des déclarations n'a jamais fonctionné à cause de lui : la
  regex ne trouvait aucun `INCLUDE_ASM`, la limite restait vide, et le dossier
  annonçait « déclaré » ce qui ne l'était qu'après la fonction. Écrire les
  regex en `r"…"` ou `rf"…"`, et vérifier par `grep -P "\x08"`.
- **Un script Python lu sur l'entrée standard, sous Windows, décode en cp1252** :
  les accents du texte de remplacement se corrompent. Écrire le script dans un
  fichier, ou passer par l'outil d'édition.
- **Ce qu'un rapport d'agent affirme d'un outil se vérifie** : « le contrôle
  a dit déclaré » signalait un vrai défaut, mais celui que j'avais déjà
  « corrigé » ne l'était pas.
- **Un type d'unité opaque bloque un essai** (`pad0[0x1290]`) : aucune forme de
  cast ne rend `lui at, %hi(g+0x20)` / `swc1 …(at)`. Ajouter le champ à
  l'unité.
- **Docker peut tomber** entre deux fournées : `soumettre.py` teste le moteur
  avant de toucher à la source.

## Résultats mesurés

| Fournée | Fonctions | Taille | Gardées | Essais |
|---|---|---|---|---|
| a1 | 8 | 32–40 o | 8/8 | 1 à 2 |
| a2 | 6 | 256–260 o | 4/6 | 3 à 12 |
| a3 | 6 | 260–268 o | 5/6, puis 6/6 après élargissement d'un type | 1 à 6 |
| a4 | 6 | 552–704 o | 3/6 (dont 2 à 99,93 % — nom de table de saut ; image identique) | 1 à 9 |
| b1 ‖ b2 (2 agents en parallèle) | 16 | 52–84 o | 13/16 (b1 5/8, b2 8/8) ; image identique, aucun conflit de verrou | 1 à 10 |
| c1 ‖ c2 ‖ c3 (3 agents, vague 1 des < 32 o) | 60 | 8–28 o | 60/60 ; image identique | 1 à 4 |
| d1 ‖ d2 ‖ d3 (vague 2) | 60 | 8–31 o | 55 gardées, 3 remises en greffe (SDK/runtime +8 o chacune : `sceGifPkInit`, `sceVif1PkInit`, `_cleanup_r`) → 52 | 1 à 5 |
| e1 ‖ e2 ‖ e3 (vague 3) | 60 | 8–31 o | 60/60 ; image identique | 1 à 5 |
| f1 ‖ f2 ‖ f3 (vague 4) | 60 | 8–31 o | 60/60 ; image identique | 1 à 5 |
| g1 ‖ g2 ‖ g3 (vague 5) | 60 | 8–31 o | 57 par les agents + `RegisterVillager` par l'orchestrateur (déclaration `(...)` typée) = 58 | 1 à 7 |

Échantillons de 6 à 8 fonctions, chacune avec un jet compilable : un ordre de
grandeur, pas un taux. À 256 octets, les échecs tiennent à l'allocation de
registres (`_DELETE_CHARA`, 93,12 %) et à la forme de la queue de fonction
(`_SET_CHARA_CONDITION`, 98,98 %), toutes deux encore en greffe.

**Deux agents en parallèle** (b1 et b2, unités disjointes par `--suivant`, verrou
par unité dans `soumettre`) : 13 fonctions gardées en 6,75 minutes de durée réelle
(b1 4,8 min, b2 6,7 min), contre 25 fonctions par heure pour un agent seul — soit
environ 115 fonctions par heure, sur des fonctions de 52 à 84 octets. Les deux
agents ont consommé 167 000 jetons. Aucun verrou restant, image identique.

**Trois agents en parallèle sur les fonctions de moins de 32 octets** (vague 1 sur 5
prévues pour les 282 du jeu) : 60 fonctions gardées sur 60, 10 minutes de bout en
bout, 210 000 jetons (3 500 par fonction). Presque toutes sont des appels en
queue (`j f`). Les essais perdus (7 sur 26 pour c3) venaient de signatures déjà
posées dans l'unité, et de collisions de fichiers temporaires entre agents
(`src/game/tmpXXXX.c`, corrigé dans `lib/project.py`).

**Bilan des cinq vagues de moins de 32 octets** : 290 fonctions gagnées sur les 300
visées (1 893 → 2 183 fonctions écrites, 137 772 → 141 660 octets), environ 1,1 million
de jetons de sous-agents (3 800 par fonction), 5 à 10 minutes de durée réelle par vague de
trois agents. Les défauts d'outillage corrigés entre les vagues sont dans
`CHANGELOG`-à-écrire : appels de queue (`j f`) ignorés du dossier, fichiers
temporaires `tmp*.c` qui faisaient planter les autres agents, ordre des déclarations
(`` devenu retour arrière), signature de la fonction elle-même, SDK/runtime refusés par
`soumettre`, types à déclarer en avant, `--table`, verrou par unité.

## Prochaines fournées

1. Tranche 512 o – 1 Ko : fait une fois (a4, 3/6). Les trois échecs (96,75 à 98,47 %) tiennent à la queue de fonction — `b` vers une fin partagée avec la valeur dans le créneau — et à un registre d'argument ; reprendre `SearchMcType`, `LoadOmakeFile`, `DrawEpisode` avec les sorties dupliquées de `CLAUDE.md`.
2. Reprendre les deux quasi-succès de a2 avec les leviers d'allocation de
   `docs/IDIOMES_MWCC.md` et les règles d'allocation de DCDecomp
   (`docs/MWCC.md` de ce dépôt : déclaration morte, compteur de boucle séparé).
3. Passer à plusieurs agents (≤ 5) seulement quand la fournée à un agent ne
   produit plus de correction d'outillage.
