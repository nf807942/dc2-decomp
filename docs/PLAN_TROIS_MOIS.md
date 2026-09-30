# Plan de trois mois

Rédigé le 30 septembre 2026. Les chiffres du dépôt se refont par `make etat` ;
ceux de la littérature viennent des sources citées en bas. Ce qui est une
hypothèse est marqué comme tel, et la première semaine sert à la mesurer.

## Ce que dit la mesure : 100 % en trois mois n'est pas atteignable

```
écrit           1 859 fn / 7 840     132 176 o / 2 215 100 o    (23,7 % / 5,97 %)
reste           5 932 fn             2 076 676 o
rythme observé  32,6 fn/jour          2 317 o/jour  (57 jours)
il faudrait     66 fn/jour           23 000 o/jour  (90 jours)  → ×10 en octets
```

Les octets ne sont pas répartis comme les fonctions :

| taille | fonctions | octets | part des octets |
|---|---|---|---|
| ≤ 256 o | 3 993 | 428 520 | 20,6 % |
| 256 – 1 Ko | 1 528 | 749 744 | 36,1 % |
| > 1 Ko | 411 | 898 412 | 43,3 % |

Les 41 fonctions de plus de 4 Ko pèsent à elles seules 11,3 % (jusqu'à
`EditLoop__Fv`, 8 908 o). Les projets publiés s'arrêtent justement là :
« gives up immediately » au-delà de 1 000 instructions (Snowboard Kids 2).

**Scénario médian (hypothèses, à mesurer en semaine 1).** Taux de réussite des
agents à 90 jours : 65 % des fonctions ≤ 256 o, 35 % de 256 o – 1 Ko, 10 % de
plus de 1 Ko. Cela donne environ 630 Ko de plus : **≈ 34 % des octets et ≈ 64 %
des fonctions** en fin de trimestre. Le scénario haut (×1,5 sur chaque taux)
touche 50 % des octets. Aucun ne donne 100 %.

Ce que le trimestre peut viser sans mentir : **doubler ou tripler la part des
octets écrits, finir toutes les fonctions courtes accessibles, et sortir
l'outillage qui rend le dernier tiers traitable.** Le 100 % est une affaire de
neuf à quinze mois à ce régime, ce que `make etat` recalculera à chaque point.

## Ce que font les projets récents

| Projet | Technique | Enseignement pour nous |
|---|---|---|
| Snowboard Kids 2 (N64) | Claude Code / Codex avec outils de compilation et de diff ; file classée par **similarité** (embeddings, distance de Levenshtein sur opcodes) | 25 % → 58 % en un passage, plateau vers 75 %. La similarité bat la complexité comme critère d'ordre ; le permuteur aveugle produit du « strange code » et des boucles sans fin |
| Mizuchi | m2c → compilateur → objdiff → permuter, puis boucle Claude dans un bac à sable qui **soumet** du C sans toucher aux sources | 74 % de 60 fonctions (GBA, N64) ; presque la moitié des succès au premier essai ; après trois échecs la probabilité tombe à ~25 % |
| Dance Central 3 | Orchestrateur MCP autour d'objdiff, Ghidra, m2c, émulation Unicorn ; pool de worktrees | Les références croisées d'un jeu frère (Rock Band, DWARF) résolvent les mises en page de classes |
| DCDecomp (Dark Cloud 1) | Un seul auteur, lots de 17 à 23 fonctions, PR | Voir plus bas : la chaîne se ressemble, l'avance vient du volume de travail humain |

Trois règles reviennent partout et sont adoptées ici :

1. **Limiter les essais par fonction** (12 ici, `--max-essais`), puis passer à
   la suivante. Une fonction a demandé 87 essais dans un projet, au 85ᵉ
   centile 28 : le rendement marginal s'effondre.
2. **Une porte plutôt qu'une consigne.** Les agents contournent une directive
   écrite ; ils ne contournent pas un script qui restitue la source.
3. **Le contexte utile est celui de la fonction**, pas celui que l'agent
   rassemble : dossier, sœur écrite, signatures des appelés.

## Ce qui a été éprouvé ce jour, et démenti ou confirmé

- **État fuité de MWCC entre unités** (piste tirée de DCDecomp, compilateur
  2.3.3). Sonde `scripts/build/etat_fuite_sonde.sh` : les unités de `src/game`
  et `src/mglib` compilées seules, puis toutes dans une invocation de MWCC 3.0
  (011126), rendent des objets **identiques** — aucune différence relevée. Le
  décompte des objets comparés n'a pas été imprimé à cette passe, et une
  seconde n'a pas fini : le résultat vaut pour « pas d'état porté d'une unité
  à l'autre, sur ce qui a été comparé ». Il ne dit rien de la mémoire non
  initialisée que le compilateur lit à l'intérieur d'une unité, et n'explique
  pas la forme des constantes flottantes du constructeur (CLAUDE.md).
- **Ressemblance avec une fonction écrite** (`make similaires`) : seules
  **200 fonctions (5 192 o)** ont une sœur à ≥ 0,9 parmi les 1 096 fonctions
  écrites qui ont un désassemblage de référence ; 389 (22 Ko) à ≥ 0,5. Le
  levier existe mais il est petit : il sert surtout d'exemple (les fonctions
  déjà écrites sont les courtes), non de critère de file pour les grosses.
- **Dark Cloud 1** : 1 100 noms de symboles en commun avec le binaire de Dark
  Chronicle, presque tous du SDK Sony. 17 classes communes, dont `CGamePad`
  (28 méthodes communes sur 44/35), `CRunScript` (18/19), `CWeaponElement`
  (16/16), `ClsMes` (19). Le compilateur diffère, donc les corps ne se
  transposent pas ; leurs noms de champs et leurs mises en page peuvent
  éclairer les nôtres (`PAD_STATUS` a la même taille, 0x4C, des deux côtés).

## Les outils livrés pour ce plan

| Commande | Rôle |
|---|---|
| `make dossier ARGS="<symbole>"` | Tout ce qu'un agent doit lire : jet existant, sœurs écrites avec leur source, appelés et leur état, désassemblage lisible, commandes de vérification |
| `make dossier ARGS="--suivant N --agent a1"` | Tire N fonctions dans la file et les **réserve** (expiration 6 h) : les agents ne se marchent pas dessus. Ordre : jet 85–100 % d'abord, puis sœur ≥ 0,7, puis courtes |
| `make soumettre ARGS="<symbole> essai.cpp"` | La porte : remplace l'`INCLUDE_ASM`, mesure (5 s), garde à 100 % ou rétablit la source. Journal dans `progress/essais.jsonl`, plafond d'essais par fonction |
| `make similaires` | Voisins écrits de chaque fonction restante ; sert aussi à chiffrer le gisement |

`progress/*` est ignoré par git (sauf `journal.jsonl`) : index, réservations et
essais restent locaux.

## Protocole d'une fournée (5 agents au plus, rapport entre deux)

1. L'orchestrateur : `make dossier ARGS="--suivant 12 --agent aN"` pour chacun.
2. Chaque agent, par fonction : lit le dossier, écrit `essai.cpp` hors du
   dépôt, `make soumettre`. Au plus douze essais ; à l'échec, il passe à la
   suivante et l'écrit dans son rapport (cause présumée, écart restant).
3. Un agent ne lance **jamais** `make build` et ne commite pas.
4. L'orchestrateur : `make build`. Si l'image diverge, la fonction fautive se
   retrouve par `nm` contre `config/elf_symbol_addrs.txt` et retourne à sa
   greffe (procédure de la mémoire `dc2-affinage-par-agents`).
5. `make dossier ARGS="--libere aN"`, `make etat`, rapport à l'utilisateur.

## Calendrier

| Semaines | Objet | Point de contrôle |
|---|---|---|
| 1 | **Mesurer.** Trois fournées d'essai sur trois tailles (≤ 256, 256–1 Ko, > 1 Ko), 12 fonctions par agent. Relever, par fonction : essais, jetons, taux. Rien d'autre ne fixe honnêtement les hypothèses ci-dessus | `essais.jsonl` chiffré ; ce document réécrit avec les taux mesurés |
| 2–4 | **Courtes et proches.** Vider les jets 85–100 % (1 490 sous `build/proches/`), puis les ≤ 256 o. Exposer le diff par instruction à l'affinage (ROADMAP, point 2) | ≥ 60 % des ≤ 256 o ; cadence en fn/jour et o/jour |
| 5–8 | **Moyennes.** 256 o – 1 Ko, classées par classe (`make etat --classes`) pour que les en-têtes se complètent d'eux-mêmes ; reprendre les 451 fonctions que m2c ne sait pas traduire (registres non initialisés, instructions 128 bits) | ≥ 30 % des moyennes |
| 9–12 | **Grosses.** Découper à la main le plan des 41 fonctions > 4 Ko en blocs, pour que les agents traitent des tranches ; `mwcc-debug` (capture de l'allocateur) si les plateaux de registres dominent les écarts restants | Décision : continuer ou changer de levier |

Chaque point de contrôle a un critère chiffré : s'il n'est pas atteint, le plan
se corrige, il ne se maintient pas par principe.

## Ce qui n'est pas fait, et pourquoi

- **Adapter `mwcc-debug` à MWCC 3.0.** Le plus lourd (cartographie des adresses
  du compilateur, profil, points d'arrêt sous gdb/wibo) ; il ne se justifie que
  si les écarts de registre dominent les quasi-succès. À décider en semaine 9
  sur `make ecarts`, pas avant.
- **decomp.dev et documentation générée**, à la demande de l'utilisateur.
- **Exemples à ressemblance élevée pour les grosses fonctions** : la mesure
  ci-dessus dit que le gisement est ailleurs.

## Sources

- [The long tail of LLM-assisted decompilation](https://blog.chrislewis.au/the-long-tail-of-llm-assisted-decompilation/)
- [Using Coding Agents to Decompile Nintendo 64 Games](https://blog.chrislewis.au/using-coding-agents-to-decompile-nintendo-64-games/)
- [Can LLMs Really Do Matching Decompilation? 60 functions tested](https://gambiconf.substack.com/p/can-llms-really-do-matching-decompilation)
- [Mizuchi](https://github.com/macabeus/mizuchi)
- [dc3-decomp](https://github.com/freeqaz/dc3-decomp)
- [DCDecomp (Dark Cloud)](https://github.com/Adubbz/DCDecomp)

## Mise à jour du 30 septembre au soir

- **Plafond avec MWCC : 90 % des octets.** Le SDK Sony (861 fonctions, 139 916 o) et le
  runtime Metrowerks (221 fonctions, 80 932 o) sont livrés compilés, absents de `.mwcats` :
  MWCC n'en rend pas les octets. Trois fonctions du SDK/runtime « à 100 % » par fonction ont
  allongé l'image de huit octets chacune. `soumettre` les refuse (`--sdk` pour forcer) et la
  file `dossier` les exclut. Ces 220 848 octets (10 %) sont hors de la chaîne.
- **Débit mesuré sur les fonctions < 32 o** : 290 fonctions sur 300 en cinq vagues de trois
  agents, ≈ 3 800 jetons par fonction. C'est la tranche la plus facile : ne pas extrapoler.
- Voir `docs/METHODE_AGENTS.md` pour les résultats par vague.

## Mise à jour du 1er octobre — ce que la soirée du 30 septembre a mesuré

Une soirée : 1 859 → 2 236 fonctions écrites (+377), 132 176 → 142 980 octets (+10 804,
soit +8,2 %), pour environ 2,7 millions de jetons de sous-agents, dont 0,4 million perdus
(trois pannes de Docker, essais d'agents interrompus).

**Ce qui a changé dans les estimations**

| | avant | mesuré |
|---|---|---|
| Jetons par octet gagné, fonctions < 32 o | — | ≈ 275 (3 800 jetons pour ~14 o) |
| Jetons par octet gagné, fonctions 256–700 o | — | ≈ 100 (échecs compris : 4/6 et 3/6) |
| Débit d'un agent | 8,4 Ko/h | 8,4 Ko/h à 256–700 o (inchangé) |
| Débit de trois agents en parallèle | — | 60 fonctions < 32 o en 5–10 min |
| Jetons pour le reste (≈ 1,85 Mo atteignables) | 380–560 M | **190–350 M** (100 jetons/octet à 256–700 o ; 2–3× plus au-delà de 1 Ko, non mesuré) |

- **Le coût par octet baisse avec la taille**, puis s'aplatit vers 100 jetons/octet : les
  petites fonctions étaient la tranche la plus chère *par octet*, malgré leur 97 % de
  réussite. Elles ont fait monter le compte de fonctions (+377) mais pas les octets : 377
  fonctions ne pèsent que 8 % de ce qui compte. La suite se juge en octets.
- **La réussite des agents tient** : 97 % à < 32 o, 83 % à 256 o, 50 % à 550–700 o. Ce qui
  reste dur est une poignée de cas d'allocation de registres ou d'ordonnancement (2 sur 290
  à < 32 o), pas un mur.
- **L'orchestrateur débloque une fonction sur vingt en changeant une déclaration de
  l'unité** (type d'une globale, ordre, `(...)` typé) : `ClearUndoFlag`, `SetSpectolInfo`,
  `RegisterVillager`, `mgAddVector`. C'est un travail de séquence, non parallélisable.
- **Un 100 % de fonction ne prouve pas l'image** : trois fonctions du SDK/runtime ont allongé
  l'image de 8 octets chacune. `make build` reste le seul verdict ; `soumettre` refuse
  maintenant ces provenances.
- **Le dossier a mûri par les rapports** : appels de queue, signature de la fonction elle-même,
  types à déclarer en avant, déclarations plus loin. Sept défauts d'outillage, dont deux de ma
  main (`\b` devenu retour arrière, regex `jal?`), ont coûté des essais aux agents avant d'être
  vus. Leçon : reproduire le défaut sur l'état d'origine avant de déclarer une correction faite.

**Le plan tient-il ?** Le plafond est 90 % des octets (SDK et runtime hors de portée). À
100 jetons/octet, 190–350 millions de jetons pour le reste : la faisabilité en trois mois
dépend du budget de jetons, non plus du temps (3 agents en parallèle font ≈ 25 Ko/h, soit
≈ 75 h d'horloge à rendement constant, ≈ 150 h si les fonctions > 1 Ko coûtent trois fois
plus de temps). La grande inconnue est inchangée : **les 370 fonctions du jeu de 1 Ko et
plus (819 Ko, 47 % des octets du jeu)**, dont aucune n'a été tentée.

**Prochaine étape recommandée avant de passer à l'échelle** : une fournée d'essai d'un agent
sur trois fonctions de 1 à 2 Ko, avec budget large (40 essais) — c'est la seule mesure qui
fait bouger les estimations — puis les tranches 32–128 o et 128–256 o en vagues de trois
agents. Ajouter à `soumettre` un contrôle de longueur (la taille de l'objet construit contre
celle du commerce) pour que « 100 % » d'une fonction implique l'image.
