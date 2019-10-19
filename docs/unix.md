# Système UNIX niveau 1

SUIVI DES VERSIONS DU DOCUMENT

Creation : 1988/01/20

Last changes : 

- 2019/10/07 corrections mineures
- 2018/09/07 passage en markdown

[TOC]



## Préface

### Notations

Durant tout ce cours nous utiliserons les notations suivantes :

Pour indiquer qu'il faut appuyer sur la touche "retour chariot" ou "Enter" nous noterons " &lt;cr&gt; " .

Pour indiquer "control d" : Appui simultané de la touche "Control" et de la touche " d " nous noterons " &lt;Ctrl-d&gt; ".

Pour la description de la syntaxe d'une commande, les termes optionnels seront placés entre crochets :" \[Termes optionnels\] ".

Les noms des fichiers seront mis entre guillemets.

### Avertissement.

Ce cours ne constitue pas un manuel UNIX, nous ne présenterons pas toutes les commandes UNIX, mais uniquement les principales pour démarrer.

Nous ne ferons pas une description exhaustive des commandes, mais donnerons uniquement la syntaxe et les options les plus couramment utilisées.

Pour tout complément d'information, se reporter aux manuels d'Unix fournis avec le matériel.

## Introduction

### Qu'est ce que UNIX

UNIX est un système d'exploitation, multi-taches, multi-utilisateurs. Il se situe entre l'utilisateur et la machine.

  Utilisateur
  Système d'exploitation
  Hardware de la machine

Le système est chargé du partage équitable des ressources de la machine entre chaque utilisateur.

Le système d'exploitation négocie entre les désirs de l'utilisateur et les ressources ou les performances de la machine.

Les demandes :

-   exécuter des commandes.

-   créer des fichiers.

-   entrer dans un réseau.

-   etc ...

Les ressources :

- l'unité centrale,
- la mémoires,
- les Disques,
- le réseau,
- etc...



### Historique

Le système d'exploitation UNIX a été développé par les laboratoires BELL, dépendant de AT&T (American Telephone & Telegraph), l'un des plus grands centres de recherche au monde. Son créateur est KEN THOMPSON, il en a assuré la conception en 1969. Depuis cette date, beaucoup de chercheurs, d'ingénieurs ont contribué à son enrichissement, à son évolution. Le développement du langage C par DENNIS RITCHIE a permis l'écriture d'une version dans ce langage de haut niveau, par conséquent portable à priori sur tout type de machine disposant d'un compilateur C.

\*"SYSTEM 3" est apparu en 1981, et marque la double volonté de AT&T de:

-   Se lancer dans une action commerciale de grande envergure,

-   réagir contre les dérives des différents portages d'UNIX, et conduisant à certaines incompatibilités.

\* La dernière version, "SYSTEM V", est le fruit d'efforts importants durant plusieurs années, entrepris par AT&T et par l'université de BERKELEY, en Californie, principalement. Les domaines concernés sont avant tout la gestion des fichiers et la fiabilité d'Unix.

"SYSTEM V" apparu en 1983, marque la volonté de AT&T d'imposer cette version, tant aux constructeurs d'ordinateurs qu'aux sociétés de logiciels qui se rallient massivement à ce standard, tout en réalisant un certain nombre d'ajouts liés à des équipements particuliers et/ou à des logiciels existants. Ces différences sont validées par AT&T.

Il existe une quarantaine de "versions différentes" du système UNIX... Ce nombre, inquiétant de prime abord lorsque l'on a des soucis de portabilité, de compatibilité, que signifie-t-il au juste? pourquoi toutes ces versions? Qu'est-ce-que cela cache?

Pourquoi toutes ces versions ?

Il convient d'aborder ce point selon deux axes: historique et commercial.

### Avant *Linux*

De nos jours, Unix est plutôt connu via Linux et ses multiples distributions.

UNIX est apparu en 1969. UNIX a évolué dans le temps et les différentes versions de référence (dénommées dans tout ce qui suit AT&T-UNIX), ont marqué les grandes étapes de cette évolution:

-   Version 5 (1973)

-   Version 6 (1975)

-   Version 7 (1979)

-   Système III (1981)

-   Système V (1983)

Chacune de ces versions techniques au-delà de la "Version 7" a donné naissance à des versions commerciales.
<p align="justify">
AT&T, qui est propriétaire de la marque UNIX (UNIX est une marque déposée) passe des contrats avec des constructeurs, des sociétés de développement, qui adaptent AT&T UNIX, en y intégrant souvent tout ou partie des utilitaires développés par l'université de BEKELEY, aux caractéristiques des matériels. Les versions ainsi adaptées doivent obligatoirement avoir un nom commercial différent d'UNIX, d'ou les nombreuses appellations. En voici une liste non exhaustive:
</p>

-   XENIX de MICROSOFT (1)

-   VENIX de VENTURE COM's (1)

-   ZEUS de ZILOG (1)

-   UNIPLUS de UNISOFT SYSTEMS (1)

-   IDRIS de WHITE SMITHS (2)

-   SOL de ADI INRIA ET SYSECA (2)

-   INITY de DIGITAL EQUIPEMENT CORPORATION (3)

-   IS/WB de INTERACTIVE SYSTEMS (3)

\(1) Authentique versions issues de BELL et comportant des variantes adaptées en général, pour tenir compte des différences de matériels.

\(2) Systèmes d'exploitation, de type UNIX, entièrement réécrits et offrant des possibilités identiques ou très proches de celles d'UNIX.

\(3) Systèmes d'exploitation, de type UNIX, fonctionnant sous le contrôle du système d'exploitation de l'ordinateur hôte, offrant un environnement quasi-identique à celui de AT&T UNIX.

### Description générale

UNIX est un système d'exploitation multi-tâche, multi- utilisateur fonctionnant en temps partagé.

Les programmes dont il assure le contrôle peuvent être lancés en mode interactif ou en traitement batch. L'une des caractéristiques principales d'UNIX par rapport au système d'exploitation traditionnel est la gestion de tout périphérique d'entrée-sorties sous la forme d'un fichier.

La gestion de l'ensemble de ces fichiers représente un système de gestion de fichiers hiérarchisés sous la forme d'un arbre. Cette possibilité permet ainsi de rediriger tous les résultats issus d'un programme comme paramètre d'entrée d'un autre programme. De plus UNIX est fourni avec un ensemble d'utilitaires de base ainsi que d'une documentation en ligne.

UNIX est aussi un système de développement, donnant aux utilisateurs tous les outils permettant d'écrire, de mettre au point et de documenter leurs programmes.

Le système UNIX est composé :

-   d'un noyau assurant la gestion de la mémoire et des entrées sorties de bas niveau ainsi que de l'enchaînement des différentes tâches .

-   d'un (ou plusieurs suivant les versions) interpréteur de commandes.

-   d'un système de messageries assez complet (courrier, conversation en temps réel )

-   d'un grand nombre d'utilitaires, dont un compilateur de langage C, un générateur d'analyseur syntaxique lex, un générateur d'analyseur sémantique yakk, etc ...

### Principales caractéristiques du système UNIX

Ses principales caractéristiques sont :

-   Son système de fichiers hiérarchisés (voir Chap 3)

-   L'aspect multi-tâches pour chaque utilisateur.

-   La possibilités d'écrire des applications faisant directement appel au noyau par l'intermédiaire du langage C.

-   Ses langages de commandes qui sont de véritables langages de programmation interprétés, permettant l'écriture de programmes complexes.

-   Son mécanisme de re-directions des entrées sorties. En effet tout processus prend normalement ses données depuis le clavier du terminal par lequel il a été lancé, de même que ses sorties se font normalement sur l'écran, il est possible d'associer aux entrées sorties des fichiers quelconques ( UNIX considérant toutes les entrées-sorties comme des fichiers sur lesquels il peut lire ou écrire ). UNIX allant plus loin puisque les sorties d'un programme peuvent être considérés comme les entrées d'un autre programme.(communication entre processus par l'intermédiaire de tube, "pipe" en anglais).

### Portabilité

Un certain nombre de constructeurs ont porté UNIX sur leurs matériels : Digital, Bull, Hewlett Packard, Thompson, Cray, Apple..., ceci dans une gamme variant du micro-ordinateur au plus gros système.

L'une des facilités de la portabilité d'UNIX est le fait que 95% environ du système est écrit dans un langage de haut niveau : Le langage C, les 5% restant étant écrit en assembleur, ceci pour gérer les drivers d'entrée-sortie dans les couches les plus basses.

Avec l'arrivée de "SYSTEM V", l'utilisateur a pu modifier certains paramètres système auxquels il n'avait pas accès sous "System III". 

Les logiciels serveur sont donc portables sur toutes les machines implémentées avec le système d'exploitation UNIX system V.

## Premier contact avec UNIX

### Session utilisateur

Une session utilisateur commence par un "login" (entrée dans le système) et se termine par un "login off" (sortie du système), entre les deux on peut exécuter des commandes, obtenir des réponses de la part de l'ordinateur.

Une commande étant le seul moyen d'effectuer quelque chose sur l'ordinateur.

Une commande est un programme que l'on utilise pour faire une tâche désirée. La commande est exécutée en entrant son nom au clavier suivi de &lt;cr&gt;.

### Procédure d'entrée sous UNIX

Pour démarrer une session utilisateur il faut posséder un "login id" (id pour identificateur) et éventuellement un mot de passe.

Au message "login:" envoyé par le système, l'utilisateur doit saisir son "login-id". Ensuite au message "password:" il doit saisir son mot de passe. Si le nom et le mot de passe sont corrects l'utilisateur peut alors démarrer sa session de travail sur la machine.

Il est recommandé d'entrer son "login-id" en minuscules, sinon UNIX (qui fait la différence entre majuscules et minuscules) considérera que votre console ne reconnaît pas les minuscules et vous affichera tout en majuscules.

Exemple :

```sh
login :daniel&lt;cr&gt;
password : xxxxxxxxxx le mot de passe n'est pas affiché à l'écran pour des raisons évidentes de sécurité.

Bienvenue sous 3B15 <== Message de bienvenue.
$
```

A l'entrée sur le système on obtient un prompt (par défaut le caractère "\$") indiquant que UNIX est prêt à accéder à tous vos désirs (ou presque).

Un certain nombre de noms d'utilisateurs sont requis par le système pour gérer des taches particulières. Ces taches sont avant tout des taches systèmes et administratives, ex : root est le super-utilisateur du système, il a tous les droits (d'où la nécessité de protéger son utilisation par l'intermédiaire d'un mot de passe).

### Manipulations des commandes UNIX

Pour exécuter une commande sous UNIX, il suffit d'entrer son nom (Premier mot de la ligne entrée) ainsi que des options dont elle a éventuellement besoin.

Format d'une ligne de commande :

cmd \[arg ...\] &lt;cr&gt;

**cmd** est le nom de la commande.

**arg** représente les paramètres optionnels de la commande. Chaque paramètre étant séparé par un espace.

!!! example "Exemple avec la commande 'date"
    La commande date permet d'afficher la date et l'heure du système sur lequel vous êtes connectés.
    Il y a une option pour date permettant de changer la date du système mais elle n'est accessible que pour le super-utilisateur.

    ```sh
    $ date
    Mon Jan 11 14:55:15 GMT 1988
    $
    ```

### Procédure d'arrêt d'une commande

Il est possible d'arrêter le déroulement d'une commande avant son terme. Par défaut il s'agit de la combinaison de touches "Ctrl-C" la touche `Control` avec la touche `C` . L'utilisateur a la possibilité de changer cette touche.

### Procédure de sortie d'UNIX

Pour terminer une session de travail il suffit d'envoyer le caractère fin de fichier qui est par défaut le caractère "<Ctrl-D>".

Une autre possibilité est d'entrer la commande exit.

Exemple :

```sh
login :daniel
password : xxxxxxxxx

Bienvenue sous 3B15

$ date 
Mon Jan 11 14:55:15 GMT 1988
<Ctrl-d>
login :
```

### Premières Commandes.

#### La commande "banner"

Imprime ses arguments en gros caractères. Elle est utilisée pour l'étiquetage, ou le titrage en sortie.

```sh
$ banner Hello
#     #
#     #  ######  #       #        ####
#     #  #       #       #       #    #
#######  #####   #       #       #    #
#     #  #       #       #       #    #
#     #  #       #       #       #    #
#     #  ######  ######  ######   ####
$
```

#### La commande "logname"

La commande `logname` vous donne votre nom d'utilisateur.

#### La commande "who"

La commande who permet de savoir qui est connecté sur le système.

Avec les options "`am i`" ou "`am I`" permet de savoir qui on est.

```sh
$ who am i
daniel tty Tue 17:44
```

#### La commande "passwd"

Permet de changer son mot de passe. Entrer la commande `passwd`, elle vous demandera votre nouveau mot de passe et de le confirmer; si tout se passe bien votre nouveau mot de passe sera valide pour votre prochaine session.

#### La commande "echo"

Ecrit ses arguments et passe a la ligne suivante. Passe à la ligne si elle n'a aucun argument.

La commande reconnaît quelques caractères spéciaux:

| caractères |  description |
|:--------:| -----------------------------------------|
|  `\b`   |       backspace : retour arrière|
|  `\c`    |      Affiche la ligne sans passer à la ligne|
|  `\f`    |      form feed : efface l'écran|
|  `\n`  |        New line: passe à la ligne|
|  `\t`   |      tabulation|
|  `\v`   |       tabulation verticale|
|  `\`     |     le caractère \\|

Sur les versions de linux il faut activer les caractères spéciaux via l'option `-e`.

#### La commande "man"

Si l'on n'a pas le manuel sous la main. `man` permet de savoir ce que fait tel ou tel commande, ainsi que les options de la commande.

l'option "-k" suivi de mots clés affiche un résumé des commandes passées en arguments.

Pour savoir comment marche la commande `man` entrer :

```sh
$ man man
```

#### Le shell

Le shell est l'interpréteur de commandes. Il existe plusiseurs interpréteur de commandes : `sh`, `ksh`, `csh`, `bash`, `bash`étant le plus répandu de nos jours. Il interprète ce que vous tapez au clavier pour l'exécuter. Lorsque vous tapez un retour-chariot il interprète le texte que vous avez écrit et exécute la commande dont le nom est le premier mot de la ligne. C'est lui qui vous affiche le prompt (par défaut "\$") vous invitant à taper quelque chose.

## Le système de fichiers

### Qu'est ce qu'un fichier

Un fichier est un lieu de stockage d'informations, c'est un nom et des données associées. Par exemple la commande date est un nom et un fichier programme associé. Un terminal est un fichier sur lequel on peut écrire : l'écran, et sur lequel on peut lire : le clavier.

UNIX considère toutes les entrées/sorties comme des fichiers, donc: les programmes, les périphériques, les données sont tous considérés comme des fichiers.

Sous unix un fichier peut avoir plusieurs noms (Voir la commande  [ln](#la-commande-ln)  ).

### Présentation générale

Un fichier sous unix est une chaîne de caractères non structurée du point de vue du système. UNIX ne possède aucune notion d'organisation de fichiers telle que les fichiers séquentiels, indexés, partitionnés.

A tout fichier est associé un bloc d'information : le i-node contenant un certain nombre d'informations sur celui-ci :

-   sa taille.

-   l'adresse des blocs sur le disque où les données sont réellement écrites.

-   l'identification du propriétaire.

-   Un compteur de référence dans le système.

-   un certains nombre de dates relatives au fichier.

On remarquera que ce bloc ne contient aucun nom d'identification pour le fichier. Les noms sont gardés dans des fichiers spécifiques : Les catalogues (ou répertoires ou encore directories).

Sous UNIX il existe **trois types** de fichiers :

-   Les fichiers ordinaires ( type data, texte, ou binaire).

-   Les fichiers directory (répertoire ou catalogue en français).

-   Les fichiers spéciaux. Il s'agit des fichiers drivers (exemple le disque, le terminal).

Il existe deux types de fichiers spéciaux :

-   Les fichiers spéciaux de type caractères (Le terminal)

-   Les fichiers spéciaux de type blocs (Le disque)

Un fichier est référencé par un nom dans une directory. Un même fichier peut être référencé plusieurs fois dans différents catalogues. Le catalogue étant lui même référencé dans un autre catalogue. Cette architecture nécessite l'existence d'un répertoire spécial dont le système connaît l'emplacement, il s'agit du répertoire racine noté "`/`".

La structure des fichiers sous UNIX est donc une arborescence, on trouvera sous celui-ci des répertoires commun à tous les systèmes UNIX.

### Référence des fichiers et répertoire de travail

Architecture de l'arborescence des fichiers sous UNIX.

    /
    /usr/bin
    /etc
    /dev/tty1
    /home/daniel

Le système de fichiers forme une arborescence, les noeuds sont des catalogues et les feuilles des fichiers ou des catalogues vides. Nous pouvons nous déplacer dans cette arborescence au moyen de certaines commandes.

Le nom d'un fichier peut être donné soit par sa référence absolue c'est à dire son nom complet depuis la racine, soit par sa référence relative c'est à dire par rapport au répertoire sur lequel on se trouve.

Par convention une référence relative est une référence ne commençant pas par le caractère "`/`".

Le repérage des fichiers est facilité par l'existence dans toutes les directories de deux références particulieres qui sont : `.` et `..` point et point point, ils désignent respectivement le répertoire courant et le répertoire au dessus ou précédent avec une exception pour le répertoire racine qui désigne alors lui même.

Exemple , si nous sommes dans le répertoire /home/daniel

  

| référence           | designation                                                  |
| ------------------- | ------------------------------------------------------------ |
| /home/daniel/toto.c | Référence **absolue** au fichier toto.c se trouvant dans le répertoire /home/daniel |
| ../daniel/toto.c    | Référence **relative** par rapport au répertoire courant (on remonte d'un cran et on redescend) |
| toto.c              | Référence relative par rapport au répertoire courant         |
| .                   | désigne /home/daniel                                         |
| ..                  | désigne le répertoire parent : /home                         |

Tous les fichiers commençant par le caractère `.` n'apparaissent pas avec les commandes normales d'affichage des fichiers, ils sont considérés comme des fichiers cachés.

Tous les utilisateurs possédent leur propre répertoire de travail qui est par défaut le repertoire courant au moment du "login".

Il existe quelques répertoires communs à tous les systèmes UNIX.

|  répertoire  |      description |
| ------------------ |-------------------------------------------------------------------------------- |
|  /         |         La racine du système |
|  /usr      |         Contient ce qui est utilisé par l'utilisateur : compilateurs, librairies, etc. |
|  /bin et /usr/bin |  Contient les programmes associés aux commandes UNIX |
|  /dev   |            contient les fichiers spéciaux |
|  /etc   |            contient les fichiers systèmes |
|  /tmp     |          tous les fichiers temporaires |

### La protection des fichiers

Sous UNIX tout utilisateur possède, associé à son identification un numéro de compte et appartient à un groupe d'utilisateur. Ainsi pour un fichier donné les utilisateurs peuvent être classés en trois catégories :

-   Le propriétaire du fichier (Celui qui l'a créé).

-   Les membres du groupe du propriétaire.

-   tous les autres.

Sans oublier le super-utilisateur root, qui lui, a tous les droits.

Trois contrôles élémentaires sont faits par le système:

-   Les droits de lecture (représenté par `r` pour **r**ead)

-   Les droits d'écriture ( représenté par `w` pour **w**rite)

-   Les droits d'exécution(représenté par `x` pour e**x**ecution

Pour un répertoire :

-   Le droit d'exécution signifie la possibilité pour un utilisateur de se positionner sur ce répertoire (en fait plutôt de le traverser).

-   Le droit de lecture étant de lire le contenu du répertoire.

-   Le droit d'écriture donne la possibilité de créer des fichiers dans celui-ci ainsi que d'effacer des fichiers dans ce répertoire même si l'on n'a pas les droits d'écriture sur ces fichiers.

Il existe aussi trois autres bits de contrôles sur les fichiers qui ont un rôle spécial:

-   le set-uid : Lorsqu'il est positionné donne à l'utilisateur du programme les droits du créateur du programme et non ceux de l'utilisateur du programme.

-   le set-guid : Idem à set-uid mais au niveau du groupe.

-   le sticky-bit : qui permet au contrôleur de processus de garder ce programme en mémoire (RAM) même si d'autres en ont besoin.

### Les commandes de manipulations de fichiers.

Nous allons voir ici les principales commandes permettant de manipuler les fichiers et les répertoires.

#### La commande "pwd"

Affiche le nom du repertoire courant à partir de la racine.

```sh
$ pwd
/home/daniel
$
```

#### La commande "cd"

Permet de changer de répertoire de travail courant. Sans paramétre permet de revenir au répertoire par défaut du login (attention, celui-ci peut être changé).

Exemple:

```sh
$ pwd
/home/daniel
$ cd /usr/bin # Positionnement absolu
$ pwd
/usr/bin
$ cd ../include # Positionnement relatif
$ pwd
/usr/include
$ cd # Sans paramètre retour au pwd : HOME directory
/u1/daniel
$
```

#### La commande "ls"

Format : `ls [-options] [arg]`

Permet d'afficher la liste des fichiers dans le répertoire courant ou le répertoire passé en argument.

quelques options:

`-l` affiche en format long (donne plus d'informations) donnant:

-   le mode du fichier et le type.

-   le nombre de liens.(nombre de références du fichier)

-   le propriétaire.

-   le groupe du propriétaire.

-   la taille (en octets)

-   la date de dernière modification.

-   le nom

`-o` identique à -l mais sans le groupe.

`-g` identique à -l mais sans le propriétaire.

`-t` impression avec tri dans l'ordre des modifications

(dernières en tête)

`-a` tout les noms des fichiers sont imprimés alors que par défaut les fichiers commençant par le caractère "." ne sont pas affichés.

`-d` si l'argument est un répertoire seul son nom est affiché.

`-r` l'ordre d'impression est inversé (quelque soit le tri )

`-u` le tri est fait selon les dates de consultation.

`-i` pour chaque fichier affiche son numéro d'i-node

Avec l'option `-l` la commande `ls` affiche les protections appliquées aux entrées (répertoire, fichiers, fichiers spéciaux) dans l'ordre suivant:

-   type de fichier (un caractère)

-   un groupe de 3 caractère pour le propriétaire

-   un groupe de 3 caractères pour le groupe

-   un groupe de 3 caractères pour le reste du monde

les protections sont positionnées de la manière et dans l'ordre suivant, ceci pour chaque type d'utilisateur :

-   r autorise la lecture- sinon

-   w autorise l'écriture- sinon

-   x autorise l'exécution - sinon

type de fichiers

- fichier normal
- `d` fichier directory
- `l` lien symbolique
- `c` fichier spécial de type caractères
- `b` fichier spécial de type blocs
- `p` sur UNIX system III et V indique les tubes nommés

-   Si le set-uid est positionné le caractère "`s`" sera écrit au lieu de "`x`" dans les droits d'exécution du propriétaire.

-   Si le set-guid est positionné le caractère "`s`" sera écrit au lieu de "`x`" dans les droits d'exécution du groupe.

-   Si le sticky-bit est positionné le caractère "`t`" sera écrit au lieu de "`x`" dans les droits d'exécution des autres.

#### La commande "cat"

Format : `cat \[arg ...\]`

Permet d'afficher à l'écran le contenu des fichiers passés en arguments.

#### La commande "cp"

Format : `cp fichier-source fichier-dest`

Permet de dupliquer des fichiers. "cp" effectue la copie physique du premier argument dans le second. Il y a création d'un nouvel i-node et recopie effective des données.

Exemple :

```sh
$ pwd # affiche le répertoire courant
/home/daniel
$ ls # pas de fichier dans le repertoire
$ cat >toto
un contenu dans le fichier
<Ctrl-d> # appui sur la touche Control et sur la touche D 
$ ls
toto
$ cp  toto tutu
$ ls
toto
tutu
$
```

#### La commande "ln"

Format : `ln fichier-source fichier-dest`

Permet de créer des liens. Nous avons vu qu'un même fichier peut avoir plusieurs noms mais correspondre au même bloc de données sur le disque. Il n'y a pas création d'un nouvel i-node. il n'y a pas de de duplication des données.

Exemple:

```sh
$ ls -il
8122435 -rw------- 1	daniel	daniel	27	Janv 13 18:04 toto
$ cp toto tata
$ ls -il
8122489 -rw------- 1	daniel	daniel	27	Janv 13 18:14 tata
8122435 -rw------- 1	daniel	daniel	27	Janv 13 18:04 toto
$ ln tata tatalinked
$ ls -il
8122489 -rw------- 2	daniel	daniel	27	Janv 13 18:14 tata
8122489 -rw------- 2	daniel	daniel	27	Janv 13 18:14 tatalinked
8122435 -rw------- 1	daniel	daniel	27	Janv 13 18:04 toto
$ # le fichier tatalinked est une référence au fichier tata,
$ # il n'y a pas duplication de données
$
```

#### La commande "mv"

Format : `mv fichier-source fichier-destination`

Change le nom d'un lien. il n'y a pas recopie physique mais uniquement modification du nom.

#### La commande "rm"

Format : `rm [-options] arg [arg...]`

Efface les fichiers spécifiés par les arguments passés en paramétre.

Les options :

`-i` affiche chaque nom des fichiers demandés et demande la confirmation de la suppression (appui sur "y" pour oui)

`-r` provoque la suppression de tous les fichiers dans toutes les directories et sous directories spécifiées de manière recursive ( attention trés dangereux, à manier avec précautions !)

> On ne peut pas effacer un répertoire avec la commande "rm" sans l'option `-r`.

#### La commande "mkdir"

Format : `mkdir arg [arg...]`

Permet de créer des répertoires.

#### La commande "rmdir"

Format : `rmdir arg [arg...]`

Permet de supprimer des répertoires. Les répertoires ne seront supprimés que si ils sont vides.

```sh
$ pwd
/home/daniel
$ ls -d
$ mkdir dir1 dir2
$ ls
toto
tata
dir1
dir2
$ mv tata dir1
$ ls
toto
dir1
dir2
$ls dir1
tata
$ rmdir dir2 dir1
dir1 : directory not empty
$ rm dir1/*
$ rmdir dir1
$ ls
toto
$ 
```

### Modification des caractéristiques d'un i-node

Le propriétaire d'un fichier peut modifier le nom du propriétaire, du groupe, et des droits d'accés des différents utilisateurs de ce fichier et lui seul (Avec le super-utilisateur).

Les commandes sont : chmod, chown, chgrp.

#### La commande "chgrp"

Format : `chgrp group file [file...]`

Change le groupe pour les fichiers spécifiés. le groupe peut être donné par son numéro ou par son nom.

#### La commande "chown"

Format : `chown nom file [file...]`

Change le propiétaire des fichiers spécifiés.le nom peut être donné par son numéro ou par son nom litéral.

#### La commande "chmod"

Format : `chmod mod file [file...]`

Permet de modifier les bits de protection des fichiers. Les modes peuvent être décrits en octal ou en symbolique.

format de mode en symbolique: `[<qui>] <perm> <op>`

&lt;qui&gt;

-   `u` propriétaire (user)

-   `g` groupe

-   `o` autres (other)

-   `a` pour tous (all)

&lt;perm&gt;

-   `+` rajoute la permision

-   `-` enleve la permission

-   `=` impose les permission (absolu)

&lt;op&gt;

-   `r` lecture

-   `w` écriture

-   `x` exécution

-   `t` pour le "sticky-bit"

-   `s` pour le "set-uid" bit (associé à u) ou le "set-guid" (associé à g)

### Les entrées-sorties, Mécanismes de redirection

Certaines commandes ne produisent pas de sortie, comme la commande cp sauf s'il y a une erreur, d'autres font uniquement des sorties sur l'écran du terminal telles que `date`, `who`, `ls` ... Certaines font des lectures en entrée. En fait tout programme sous UNIX connait TROIS types de fichiers qui sont :

-   stdin : Fichier standard d'entrée (par défaut le clavier du terminal)

-   stdout : Fichier standard de sortie (par défaut l'écran du terminal)

-   stderr : Fichier standard d'affichage des erreurs (Par défaut l'écran du terminal)

Les entrées sorties étant des fichiers il est possible de les rediriger vers d'autres fichiers ( fichiers data, fichiers devices ) de telle sorte qu'au lieu d'utiliser le terminal les programmes peuvent aller lire ou écrire leurs données sur des fichiers. La redirection des entrées sorties est gérée par le shell.

Les commandes de redirection, *file* désignant le nom d'un fichier :

|  symbole |  entrée/sortie |      description  |
| ---------------- | ------------------- |------------------------------------------------------------------------------------------------------------------------------------- |
|  `>`*file*  |      stdout            |  redirige vers le fichier spécifié, si ce dernier existe il est tronqué à zéro caractère sinon il est créée. |
|  `>>`*file* |  stdout           |   Idem &gt; sauf si le fichier existe les données sont rajoutées en fin de celui-ci. |
| `2>`*file*       | stderr          |    Idem à `>` pour la sortie d'erreur |
| `2>>`*file*    |  stderr            |  Idem à `>>` pour la sortie d'erreur |
| `<`*file*      | stdin            |   les données sont lues depuis le fichier spécifié |
| `<<`TOTO  |   stdin          |     lit depuis l'entrée standard courante jusqu'à trouver la chaîne TOTO, TOTO pouvant être remplacé par les caractères de votre choix. |
| cmd1 `|`cmd2 |    stdout vers stdin |  Permet d'enchainer 2 commandes, la sortie standard de la commande cmd1 devenant l'entrée standard de cmd2 |

#### La commande "wc"

Format : `wc [option]`

Permet suivant l'option de compter le nombre de mots,de lignes, de caractéres lus au clavier jusqu'à rencontrer le caractère de fin de fichier &lt;Ctrl-d&gt;.

Les options :

-   `-l` compte le nombres de lignes.

-   `-w` compte le nombre de mots

-   `-c` compte le nombre de caractéres.

sans option c'est `-lwc` qui est pris.

Exemple:

```sh
$ ls
toto
$ date >fich1
$ ls
toto
fich1
$ cat fich1
Mon Jan 11 17:38 GMT 1988
wc -l <fich1
1
$
```

## Fichiers et processus

### Généralités et présentation

Un processus est l'exécution d'un programme à un instant donné, le fichier programme étant un objet inerte rangé sur disque. On peut distinguer deux types de processus :

-   Les processus systèmes qui ne sont attachés à aucun type de terminal, qui sont créés au lancement du système ou à des dates fixes. Les premiers ne s'arrêtant qu'avec l'arrêt du système.

-   Les processus lancés par un utilisateur particulier depuis un terminal donné. Le fait de se 'loguer' crée un processus correspondant à l'exécution d'un programme déterminé à l'avance pour chaque utilisateur. La plupart du temps il s'agit de l'exécution de l'interpréteur de commande : le shell.

Un point fondamental pour un processus est l'environnement. Chaque processus a un environnement dont il hérite du processus qui l'a lancé : le processus père.

Par exemple vous lancez la commande "rm", votre shell génère un nouveau processus qui sera créé pour exécuter le programme qui effectue la tache d'effacement de fichiers. Ce nouveau processus hérite de l'environnement de votre shell en particulier du répertoire courant où vous vous trouvez au moment du lancement de la commande.

Chaque processus est identifié par son "process-id" (PID) le numéro du processus père étant identifié par le PPID. La différence entre le processus père et le fils est que l'âge a effet sur sa priorité; en particulier la destruction du processus père entraîne la destruction de tous ses processus fils (par défaut).

#### La commande "ps"

Format : `ps [options]`

Permet d'avoir la liste des processus en cours dans le système. "`ps`" sans argument donne la liste des processus attachés à votre terminal.

Quelques options:

`-e` informations sur tous les processus en cours sur la machine.

`-a` information sur les processus associés aux terminaux.

`-f` liste toutes les informations sur les processus.

`-l` liste longue des informations.

`-t` suivi d'une liste de numéro donne la liste des processus associés à ces terminaux.

Ex: `ps -t tty05,tty10` donne la liste des processus attachés aux terminaux tty05 et tty10.

Détails sur les informations fournies par ps.

-   PID numéro du processus.

-   PPID numéro du processus père.

-   TTY Terminal auquel est rattaché le processus.

-   TIME Durée cumulée d'exécution.

-   COMMAND Commande qui a été exécutée.

-   UID numéro du propriétaire du processus.

-   CT aux d'utilisation de la CPU (Utilisé pour le calcul de la priorité du processus).

-   PRI Priorité du processus, les chiffres les plus hauts correspondants aux priorités les plus faibles.

-   STIME Heure de lancement du processus.

### Le Shell

Le shell est un processus important, tout utilisateur qui se connecte a sa copie du programme "sh" qui s'exécute dans son environnement. On peut Empiler plusieurs shells pour travailler sous différents environnements. Si l'on tape "sh" on lance un nouveau processus.

Exemple :

```sh
login: daniel

password:

Bienvenue sous UNIX
$ ps
PID TTY TIMECOMMAND
745 4500:06 sh
850 4500:01 ps
$ sh
$ ps
PID TTY TIMECOMMAND
745 4500:08 sh
860 4500:06 sh
865 4500:01 ps
$
```

On a deux shells qui s'exécutent en même temps. Si l'on se délogue en entrant `<Ctrl-d>` on obtient :

```sh
$ <Ctrl-d>
$ ps
PID TTY TIMECOMMAND
745 4501:10 sh
956 4500:01 ps

$ <Ctrl-d>
login:
```

Autre exemple : Environnement d'un processus.

```sh
$ pwd
/home/daniel
$ sh
$ pwd
/home/daniel # On hérite de l'environnement du père.
$ cd /usr/include
$ pwd
/usr/include
$ <Ctrl-d>;
$ pwd
/home/daniel # Mais pas l'inverse : l'environnement du fils n'est pas transmis au père.
$
```

### Lancement d'un processus en arrière plan

Le shell qui crée un processus en arrière plan reprend la main sans attendre que celui-ci soit terminé.

```sh
$ ps
PID TTY TIMECOMMAND
745 4500:06 sh
850 4500:01 ps

$ ls -al >fich1 &
800

$ ps -edf
PID TTY TIMECOMMAND
745 4500:06 sh
800 4500:01 ls -al >fich1 &
850 4500:01 ps

$
```

C'est le caractère "&" qui permet de lancer des processus en arrière plan. Quand un processus est lancé en arrière plan le shell renvoie le numéro de process qui lui a été attribué.

Attention un processus lancé en arrière-plan (background) est quand même détruit en cas de déconnexion car il reste attaché au terminal d'où il a été lancé.

De plus un processus en arrière plan a les mêmes entrées-sorties que le processus père, il est donc conseillé de rediriger les sorties, sinon les messages apparaîtront au fur et à mesure sur le terminal.

#### La commande "nohup"

Format : `nohup commande [args]`

La commande "`nohup`" permet de détacher un processus du terminal.On pourra donc lancer de longs travaux sans monopoliser le terminal puisque les processus lancés par l'intermédiaire de la commande "nohup" seront détachés du terminal, on pourra se déconnecter, nos processus continuerons à tourner. Si l'on ne redirige pas les sorties la commande les redirigera vers un fichier nommé "nohup.out".

```sh
$ nohup ps -efl >fich1 &
850

$ ps
PID TTY TIMECOMMAND
745 4500:06 sh
850 4500:01 nohup ps -efl >fich1 &
980 4500:01 ps

$
```

#### La commande "wait"

La commande wait attend la fin des processus lancés en arrière plan.

#### La commande "nice"

Format : `nice [-increment] & commande & [args...]`

Permet de changer artificiellement la priorité d'un processus. On ne peut pas augmenter sa priorité, mais seulement la baisser (sauf le super-utilisateur). Cela permet d'effectuer des travaux non-urgents en arrière-plan. La priorité par défaut est 10. La valeur d'incrément est comprise entre 1 et 19 (plus faible).

#### La commande "at"

Format : `at <heure> <jour> [<fichier>]`

Permet de lancer une commande en arrière plan à une date et une heure fixées. La commande n'est pas attaché à un terminal (comme pour la commande "nohup".

&lt;heure&gt; formé de 1 à 4 chiffres peut être suivi des lettres :

-   a : am

-   p : pm

-   n : midi

-   m : minuit

&lt;jour&gt;est optionnel (par défaut le jour courant)

```sh
$ # Lance la commande "ls -l >fich" à 18:00h le 15 janvier.
$ at 18 jan 15 ls -l >fich
$
```

### Destruction d'un processus

Le fait de se déconnecter tue tous les processus attachés au terminal. Autrement il faut utiliser la commande `kill`. Si l'on n'a plus la main sur son terminal pour une raison ou une autre on peut toujours se connecter par l'intermédiaire d'un autre terminal.

#### La commande "kill"

Format : `kill [-numéro] PID [PID...]`

Permet de tuer des processus. Le numéro de signal est compris entre 1 et 15.

Le signal n° 2 correspond à &lt;INTR&gt;

Le signel n° 3 correspond à &lt;QUIT&gt;

L'arme absolue contre les processus récalcitrants est : `kill -9 PID`

Ceci à condition d'être le propriétaire du processus ou d'être le super-utilisateur.

## Editeur de texte vi

### Introduction à vi

Vi est un éditeur de texte pleine page. Il à été développé à l'Université de Berkeley, mais est néanmoins disponible sur la plupart des versions de UNIX.

Ces principales caractéristiques sont :

-   Un système de récupération et de sauvegarde sophistiqué.

-   Possède les mêmes possibilités que l'éditeur ligne ed.

-   Possède un jeu de commandes puissant.

-   Travaille sur une image mémoire du fichier édité.

Vi étant un éditeur pleine page, il utilise les attributs vidéo du terminal, qu'il connaît par l'intermédiaire de la variable TERM de l'environnement. L'initialisation de la variable se fait par :

```sh
$ TERM=<valeur>
$ export TERM

$
```

### Appel de l'éditeur.

Il existe plusieurs façon d'appeler l'éditeur:

-   `vi <nom>` : édite le fichier et place le curseur sur la 1ere colonne de la 1ere ligne.

-   `vi +n <nom>` : édite le fichier et place le curseur sur la 1ere colonne de la ligne n.

-   `vi + <nom>` : édite le fichier et place le curseur sur la 1ere colonne de la dernière ligne.

-   `vi +/<chaine>/<nom>/` : édite le fichier et place le curseur sur le premier caractère de la ligne contenant la première occurrence de &lt;chaine&gt;

Il est possible de créer un fichier qui sera exécuté à chaque appel de vi ce fichier doit avoir comme nom ".exrc" dans le répertoire privé de l'utilisateur. Si ce fichier existe il sera considéré comme un ensemble de commandes à exécuter.



### Les commandes de vi

L'éditeur possède deux modes de travail :

-   le mode insertion : tout ce qui entré au clavier est écrit dans le tampon en mémoire associé au fichier.
-   Le mode commande : dans lequel tout ce qui est entré au clavier est interprété comme une commande de l'éditeur.
-   le mode commande étendue (commandes commençant par ':')

#### La touche `Esc` 

Permet de sortir du mode insertion et de passer en mode commande.

#### Pour sortir de l'éditeur 

`ZZ` sort de l'éditeur et sauvegarde les modifications (deux fois la touche  <Shift+Z> )

#### Commandes Générales

on commence toujours par appyer sur `<Esc>`, cela ne fait pas de mal et on est sur de sortir du mode insertion.

| commande                             | description                                                  |
| ------------------------------------ | ------------------------------------------------------------ |
| :f                                   | donne la référence du fichier en cours d'édition.            |
| ZZ ou :wq                            | Sort de l'éditeur et sauvegarde les modifications.           |
| :w                                   | Sauvegarde du fichier sous son nom d'entrée.                 |
| :w &lt;nom>                          | Sauvegarde le fichier sous le nom &lt;nom&gt;,le nom du tampon courant n'est pas modifié. |
| :w!                                  | Force l'écriture (utile dans certains cas).                  |
| :q                                   | Sortie de l'éditeur,possible uniquement s'il n'y a pas eu modification. |
| :q!                                  | Force la sortie sans modification.                           |
| :e &lt;nom&gt;                       | édite le fichier &lt;nom&gt; uniquement si l'ancien est sauvegardé. |
| :e! &lt;nom&gt;                      | force l'édition du nouveau fichier.                          |
| :w &lt;n1&gt;,&lt;n2&gt; &lt;nom&gt; | écrit uniquement les lignes comprises entre n1 et n2.        |
| :r &lt;nom&gt;                       | introduit le fichier &lt;nom&gt; en dessous de la ligne courante. |
| :r! &lt;commande&gt;                 | introduit le résultat de la commande shell &lt;commande&gt; après la ligne courante. |
| :!&lt;commande&gt;                   | Exécute la commande du shell &lt;commande>                   |
| &lt;Ctrl-l&gt;                       | Rafraîchissement de l'écran. Utile lorsque le résultat d'opération provoque des affichages parasites. |
| :se nu                               | Affiche les numéros de ligne en début de chaque... ligne (:se nonu pour les enlever) |

​                      

#### Déplacement du curseur

Dans les commandes qui suivent `<n>` désigne un facteur de répétition il peut être omis (de nos jours les flêches fonctionnent très bien).

|commande     |                             description|
|:----------:|- -----------------------------------------------------------------------|
|&lt;n&gt; h     |                          déplace le curseur vers la gauche.|
|&lt;n&gt; &lt;espace&gt; ou &lt;n&gt; l |  (L minuscule) déplace le| curseur vers la droite.|
|&lt;n&gt; &lt;Ctrl-n&gt; ou &lt;n&gt; j  | déplace le curseur vers le bas.|
|&lt;n&gt; &lt;Ctrl p&gt; ou &lt;n&gt; k  | déplace le curseur vers le haut.|
|&lt;n&gt; + ou &lt;n&gt; &lt;cr&gt;      | descend le curseur de &lt;n&gt; lignes.|
|&lt;n&gt; w               |                déplace le curseur en début de mot suivant.|
|&lt;n&gt; b                  |             déplace le curseur en début de mot précédent.|
|&lt;n&gt; e                    |           déplace le curseur en fin de mot courant.|
|&lt;n&gt; G                      |         déplace le curseur à la ligne spécifié. (par défaut en fin de texte.)|
|  &lt;n&gt; &lt;Ctrl-u&gt;      |            remonte de &lt;n&gt; lignes.(par défaut à une demi-page)|
|  &lt;n&gt; &lt;Ctrl-e&gt;        |          descend de &lt;n&gt; lignes.(par défaut à une demi-page)|

#### Commandes de suppression de texte.

Dans les commandes qui suivent `<n>` désigne un facteur de répétition il peut être omis.

|commande     |                             description|
|:----------:|- -----------------------------------------------------------------------|
| &lt;n&gt; x   |  supprime le caractère sous le curseur.|
| &lt;n&gt; X  |   supprime le caractère précédent le curseur.|
| D            |   supprime la fin de la ligne.|
| &lt;n&gt; d w  | supprime le mot.|
| &lt;n&gt; d d |  supprime la ligne.|

#### Commandes de recherche (chaîne de caractères)

|commande     |                             description|
|:----------:|-----------------------------------------------------------------------|
|&lt;n&gt; f &lt;car&gt;     |               recherche du premier &lt;car&gt; sur la fin de la ligne courante et se positionne dessus. |
|&lt;n&gt; F &lt;car&gt;       |             recherche du premier &lt;car&gt; sur le début de la ligne courante et se positionne dessus. |
|  &lt;n&gt; t &lt;car&gt;        |            recherche du premier &lt;car&gt; sur la fin de la ligne courante et se positionne sur le caractère précèdent. |
|  &lt;n&gt; T &lt;car&gt;         |           recherche du premier &lt;car&gt; sur le début de la ligne courante et se positionne sur le caractère précèdent. |
|&lt;n&gt; ;         |                       répète l'une des opérations f , F , t ou T.|
|&lt;n&gt; ,           |                     répète l'une des opérations f , F , t ou T dans le sens opposé.|
|  &lt;n&gt; / &lt;motif&gt;\[/\]&lt;cr&gt; |  Recherche la première occurrence de &lt;motif&gt;|
|  &lt;n&gt; ? &lt;motif&gt;\[?\]&lt;cr&gt;  | idem mais dans le sens opposé.|
|  n            |                              répétition d'une opération /ou ? dans le sens courant|
|  N              |                            répétition d'une opération ?ou / dans le sens opposé|

#### Commandes d'insertion

Le caractère &lt;Escape&gt; permet de repasser en mode commande.

|commande     |                             description|
|:----------:|-----------------------------------------------------------------------|
|  a   |      passe en mode entrée après le caractère courant.|
|  i      |    passe en mode entrée avant le caractère courant.|
|  A   |       passe en mode entrée en fin de ligne.|
|  I     |     passe en mode entrée en début de ligne.|
|  o  |        passe en mode entrée après la ligne courante.|
|  O      |    passe en mode entrée avant la ligne courante.|

En mode insertion les caractères suivant ont un rôle privilégié

|commande     |                             description|
|:----------:|-----------------------------------------------------------------------|
|  &lt;Escape&gt;  | passage en mode commande.|
|  &lt;Ctrl-h&gt; |  effacement du caractère précédent. (même si la visualisation n'est pas |immédiate.)|
|  &lt;Ctrl-v&gt; |  Permet d'introduire dans le fichier tous les caractères.|

#### Commandes de modification

|commande     |                             description|
|:----------:|-----------------------------------------------------------------------|
|  &lt;n&gt; cw &lt;chaine&gt; |  Remplace le mot par &lt;chaine&gt;|
|  &lt;n&gt; cc &lt;chaine&gt; |  Remplace les &lt;n&gt; lignes par &lt;chaine&gt;|
|  &lt;n&gt; J        |           joint la ligne courante et la suivante.|
|  &lt;n&gt; s &lt;chaine&gt;  |  Substitue aux &lt;n&gt; caractères la chaine &lt;chaine&gt;.|
|  R          |                   Substitution d'une chaine jusqu'à &lt;Escape&gt;|
|  r         |                    Substitution du caractère courant.|

#### Commandes de récupération

Chaque opération de suppression ou de modification est stocké dans un buffer spécial qu'il est possible de récupérer. Il existe plus de 26 buffers numérotés de a à z qu'il est possible d'utiliser. Ils sont notés <lettre> dans le tableau ci-dessous.

|commande     |                             description|
|:----------:|-----------------------------------------------------------------------|
|  " &lt;lettre&gt; &lt;n&gt; yw  | mémorise &lt;n&gt; mots dans le buffer &lt;lettre&gt;|
|  " &lt;lettre&gt; &lt;n&gt; yy |  mémorise &lt;n&gt; lignes dans le buffer &lt;lettre&gt;|
|  " &lt;lettre&gt; p      |        insère le buffer &lt;lettre&gt; après le curseur.|
|  " &lt;lettre&gt; P       |       insère le buffer &lt;lettre&gt; avant le curseur.|
|  p               |                insère le buffer spécial après le curseur.|
|  P            |                   insère le buffer spécial avant le curseur.|
|  u           |                    annulation de la commande précédente.|

#### Quelques commandes particulières

|commande     |                             description|
|:----------:|-----------------------------------------------------------------------|
|  :se all &lt;cr&gt;    |   Affiche l'état de l'éditeur. |
|  :se ai&lt;cr&gt;    |     auto-indentation|
|  :se wm=&lt;valeur&gt;  |  coupure des lignes à &lt;valeur&gt; de la droite de l'écran.|
|  :se ts=&lt;chiffre&gt; |  la valeur des tabulations est positionné à &lt;chiffre&gt; caractères (valeur par défaut 8)|
|  :se nu          |         affichage des numérotations de lignes.|
| :syntax on | pour aciver la coloration syntaxique (avec vi ) |

Toutes ces commandes trouvent leur place dans le fichier d'initialisation de `vi` qui porte le nom ".exrc" ou ".vimrc" pour `vim`.

### Conclusions

Vi est un éditeur puissant demandant de la pratique pour être pleinement utilisé. Pour les allergiques à `vi`, il existe aussi un autre éditeur : `emacs`.

Toutes les possibilités n'ont pas été abordées ici. Pour plus d'informations se reporter à la documentation de votre système UNIX.

## Pipelines (tubes)

### Introduction

Les *pipe* sont une fonctionnalité très puissantes dans unix et dans le shell. Ils permettent de créer des commandes sophistiquées à partir des commandes de base d'unix. Les sorties d'un processus peuvent être redirigées vers un fichier. Si un autre processus a besoin de ces données à l'entrée on peut les lui donner par l'intermédaire d'un fichier.

Exemple :

```sh
$ ls >fich1
$ wc -l fich1 # Compte le nombre de lignes,donc le  nombre de fichier.
12
$
```

On peut aussi diriger directement les sorties d'un processus en entrée d'un autre processus par l'intermédiaire d'un tube. Le symbole '|' permet de le faire.

```sh
$ ls
toto
tata
tutu
$  # Nombre de fichiers dans le répertoire courant.
$ ls | wc -l
3
$
```

Le symbole '|' indique au shell de prendre le résultat de la commande "ls" et de l'envoyer non pas sur l'écran, mais sur l'entrée de la commande "`wc`". La sortie de la commande "`wc`" n'étant pas redirigé (dans cet exemple) le résultat s'affiche à l'écran.

La redirection des entrées sorties permet d'orienter la commande vers un fichier. Les tubes (pipelines) permettent quand à eux de regiriger la sortie d'un processus vers l'entrée d'un autre processus.

### Les filtres.

Les commandes se situant aprés le caractère '|' doivent être des filtres, c'est à dire qu'elles doivent prendre leurs données depuis stdin et afficher le résultat sur stdout.

> Toutes les commandes ne sont pas des filtres.

Les commandes "`cp`", "`mv`", "`who`", "`date`" ne sont pas des filtres, elles ne peuvent donc être utilisées en bout de tubes. Par contre la commande "`wc`" est un filtre.

#### La commande "sort"

Format : `sort [-options] [ [<n1> [<n2>] [<fich1>..] [<fich2>]`

Tri les lignes sur l'entrée standard (ou &lt;fich1&gt;) et écrit le résultat sur la sortie standard (ou &lt;fich2&gt;). le tri est lexicographique sur l'ensemble des fichiers.

| options      | description                                                  |
| ------------ | ------------------------------------------------------------ |
| `-b`         | les espaces de tête sont ignorés dans les comparaisons.      |
| `-d`         | Seules les lettres,chiffres et espaces sont significatifs.   |
| `-f`         | Confond les lettres majuscules et minuscules.                |
| `-i`         | Ignore les caractères ASCII non compris entre 32 et 126      |
| `-n`         | le début des lignes numériques sont triés numériquement.     |
| `-r`         | Inverse l'ordre.                                             |
| `-t<x> +<n>` | Où &lt;x&gt;   est un caractères quelconque permettant de séparer des champs dans des lignes, le tri s'effectue à partir du &lt;n&gt;eme caractère &lt;x&gt; trouvé. |
| `<n1> -<n2>` | Limite la comparaisons entre les colonnes n1 et n2-1         |
|              |                                                              |

La commande "sort" possède de nombreuses autres options, se reporter à la documentation de votre système UNIX.

Exemple : Répertoire de numéro de postes.

```sh
$cat numpost
gilbert:611:bureau de développement
daniel:344:bureau d'études
valérie:312:secétaire
$
$ sort numpost # tri alphabétique sur les lignes
daniel:344:bureau d'études
gilbert:611:bureau de développement
valérie:312:secétaire
$
$ sort -n -t: +1 numpost ;# tri numérique sur le 2éme champ
valérie:312:secétaire
daniel:344:bureau d'études
gilbert:611:bureau de développement
$
```

#### La commande "grep"

Format : `grep [-options] '<motif>' [fich ...]`

La commande "`grep`" recherche dans les fichiers spécifiés (ou stdin) le motif spécifiéet affiche ces lignes. Si la recherche s'effectue sur plusieurs fichiers "grep" affiche en début de ligne le nom du fichier.

| options | description                                                  |
| ------- | ------------------------------------------------------------ |
| `-n`    | Imprime le numéro de ligne et la ligne.                      |
| `-n`    | Affiche les lignes ne contenant pas le motif spécifié.       |
| `-l`    | Seuls les numéros de lignes sont spécifiés.                  |
| `-c`    | Affiche uniquement le nombre de ligne contenant le motif le motif est écrit entre quotes " ' " . |

Exemple :

```sh
$ grep -v 'bureau' numpost
valérie:312:secétaire
$
```

### tubes et redirections d'I/O

Les redirections permet d'orienter la sortie d'un processus (c'est à dire le resultat d'un programme), tandis que les tubes (pipelines) permettent de rediriger les sorties d'un processus vers l'entrée d'un autre processus; c'est donc une communication entre processus.

Exemples de tubes :

```sh
$ ls | wc -l # donne le nombre de fichier dans le répertoire courant
32
$ ls .. | wc -l # donne le nombre de fichier dans le répertoire père
3
$ who | wc -l # donne le nombre de personnes connectées
4
$ # Exemple de tube avec redirection.
$ echo Nombre de gens connectés à la date de >fich
$ date >> fich
$ echo -n est :  >>fich
$ who |wc -l >>fich
$ cat fich
Nombre de gens connectés à la date de
Tue Jan 12 18:43 GMT 1988
est 4
$
```

### Quelques filtres usuels

#### La commande "pr"

Format : `pr [-options] [fichier ...]`

La commande pr permet de formatter du texte sur la sortie standard. Sans option affiche avec un en-tête et une numérotation de page. C'est une commande trés puissante.

Quelques options :

|  options   |    description|
|:------------: | ------------------------------------------------------------|
|  +&lt;n&gt; |   Débute à la page de numéro donné.|
|  -&lt;n&gt;  |  Impression sur le nombre de colonnes donné (1 par défaut).|
|  -m     |       Imprime les fichiers à raison de 1 par colonne.|
|  -d      |      Insère une ligne blanche entre chaque ligne.|
|  -w&lt;n&gt; |  Largeur d'une ligne (72 par défaut).|
|  -l&lt;n&gt; |  Chaque page contient &lt;n&gt; lignes.|
|  -h     |       L'argument suivant est utilisé comme en-tête à chaque page|
|  -p     |       Interruption entre chaque page (&lt;cr&gt; pour continuer)|
|  -t     |       Les 5 premières lignes de l'entête ne sont pas imprimées|

#### La commande "paste"

Format : `paste [options] [fichier ...]`

Les lignes de chaque fichier sont considérées comme des colonnes séparées par défaut par des tabulations.

Exemple :

```sh
$ cat fich1
aa
ab
ac
$ cat fich2
ba
bb
bc
$ paste fich1 fich2
aa ba
ab bb
ac bc
$
```

#### La commande "pg"

Format : `pg [<n>] [-p <chaine>] [-options] [<n>] [files...]`

Permet l'affichage de texte avec arrêt entre chaque page et possibilité de retour arrière.

&lt;n&gt; Spécifie le nombre de ligne à afficher.(par défaut 23)

-p &lt;chaine&gt;&lt;chaine&gt; est utilisé comme prompt (par défaut ":")

Quelques options:

-c Efface l'écran avant l'affichage de chaque page.

-e Enlève l'arrèt entre chaque fichiers.

+&lt;n1&gt; Commence à la ligne &lt;n1&gt;

Quelques commandes de "pg":

&lt;cr&gt; affichage d'une nouvelle page.

h Affiche une aide sur les commandes disponibles.

!&lt;commande&gt; Execute une commande du shell.

#### La commande "lp"

Format : `lp [fichier...]`

Permet d'imprimer sur l'imprimante locale les fichiers spécifiés (ou ce qui est écrit depuis l'entrée standard,

caractère fin de fichier pour terminer).

## Le Shell,Programmation et Environnement

### L'environnement.

Nous avons vu que lorsqu'un processus lance un autre processus, celui ci hérite de l'environnement du processus qui l'a lancé.

L'éditeur vi utilise la variable TERM de l'environnement.

L'environnement est constitué en grande partie de variables comme la variable TERM. Les programmes ont aussi des variables qui leur sont propres.

On distingue deux types d'environnement :

-   L'environnement global commun à tous les processus.

-   L'environnement local à un processus. c'est l'environnement associé au processus.

Certaines variables sont déjà définis et ont une utilisation spécifique.

#### La commande "set"

Permet d'avoir l'environnement local du shell en cours.

```sh
$ set
PATH=:/bin:/usr/bin
TERM=vt100
HOME=/home/daniel
PS1=\$
PS2=>
$
```

`PATH` Spécifie les répertoires où seront cherchés les commandes. Le caractère ":" étant le séparateur sauf le premier qui spécifie le répertoire courant. dans le cas présent le shell ira chercher les programmes dans :

-   le répertoire courant

-   le répertoire /bin

-   le répertoire /usr/bin

`TERM` Spécifie le terminal qui est utilisé.

`HOME` Le répertoire du login,c'est le répertoire qui est pris par la commande "cd".

`PS1` Le prompt du shell.

`PS2` Le deuxième prompt du shell

#### La commande "export"

Format : `export <variable> [variables ...]`

Permet de rendre une variable globale. Les variables globales sont passées aux processus fils.

```sh
$ VARIABLE_LOCALE=local
$ VARIABLE_GLOBALE=global
$ set | grep VARIABLE
$ VARIABLE_LOCALE=local
$ VARIABLE_GLOBALE=global
$ export VARIABLE_GLOBALE
$ sh 
$ set | grep VARIABLE
$ VARIABLE_GLOBALE=global
$
```

#### La commande "env"

Permet d'avoir la liste des variables globales. Ces variables seront passées aux processus fils.

Lorsqu'un processus fils est lancé il obtient une **copie** de l'environnement du père, toutes ces tâches se feront dans cette copie. C'est pourquoi un processus fils ne peut pas modifier l'environnement du père.

> Il est impossible de faire un "export" ascendant du fils vers le père.

#### Affectation des variables

&lt;nom\_de\_variable&gt;=&lt;valeur&gt;

Les noms de variable commencent par une lettre et sont composés de lettres, chiffres et du caractères "\_"

On peut affecter à une variable la valeur d'une autre variable, pour cela il faut faire précéder cette dernière par le caractère "\$".

Si les variables se trouvent au milieu d'une ligne il faut entourer le nom de la variable par deux accolades "{ }".

Exemple:

```sh
$ VARL=locale
$ echo $VARL
locale
$ echo La température $VARL est de 10 degrés
La température locale est de 10 degrés
$ echo Les températures ${VARL}s sont chaudes
Les températures locales sont chaudes
$
```

### Les caractères spéciaux

Nous avons vu déjà certains caractères spéciaux, \$ signifie que la suite est une variable d'environnement, les accolades {} permettent de délimiter le nom d'une variable, l'espace est considéré comme étant le séparateur.

Il est parfois nécessaire de pouvoir outrepasser un caractère, Il existe trois moyens :

`\` le caractère *backslash* ou barre oblique inverse

`''` deux simples quotes

`""` deux guillemets

Le *backslash* annihile le rôle d'un caractère spécial.

Exemple : \\\$var ne sera pas interprété comme le contenu de la variable var mais comme la chaine \$var .

\\\\ donnera le caractère \\

Les simples quotes sont utilisés pour marquer plusieurs caractères.

Les guillemets annulent toutes interprétation des caractères à l'exception des caractères : \'"\$ dont l'interprétation peut être annulée s'ils sont précédés de \\

### Les noms implicites de fichiers

Il existe un système de génération de fichiers. Une partie du nom d'un fichier peut être remplacée par des caractères jokers:

| caractère(s) |  description|
|-------------- | ----------------------------------------------|
|  `*`     |       Remplace un nombre quelconque de caractères.|
|  `?`      |        Remplace un seul caractère.|
|  `\[\]     |      Défini une classe de caractères.|
|  `..`     |         Une suite de caractères.|
|  `!`     |         négation d'une classe de caractères.|

Exemple:

```sh
$ ls * ;# idem à ls tout seul
toto
tata
$ ls to*
to
$ ls t[a-i]t*
tata
$ ls t[ao]*
toto
tata
$
```

Note : Les méta-caractères ne détectent pas les fichiers commençant par le caractère ".".

### Le fichier .profile

Lorsque que l'on se connecte, on se retrouve avec un certain environnement. Cet environnement peut être modifié en modifiant le fichier `.profile` qui se trouve dans le répertoire par défaut de l'utilisateur (repéré par la variable d'environnment `$HOME`). Les fichiers commençant par le caractère "."  n'apparassent pas avec la commande "ls" (il faut utiliser l'option `-a`).

Lors de la connexion le fichier .profile sera exécuté par le shell.

Exemple :

```sh
$ cd
$ echo "echo Bonjour Daniel" >>.profile
$ exit
login: daniel
password: xxxxxxx
Bonjour Daniel
$
```

### Introduction à la programmation en shell

Le shell est un langage de commande interprété. Un programme shell est donc un fichier texte contenant un ensemble de commandes, Il est rendu exécutable par la commande "chmod". Le shell est un langage puissant mais est très peu pratique pour les calculs arithmétiques.

Exemple de programme shell:

```sh
$ cat dir
ls -a
$ dir
.
..
.profile
dir
$
```

De même que pour les commandes on peut passer des paramètres aux programmes shell. les variables passées en paramètres sont de la forme \$&lt;n&gt; ou &lt;n&gt; est un chiffre.

\$0 est le nom du programme

\$1 à \$9 sont les arguments passés en paramètres.

Exemple :

```sh
$ cat mon_echo
echo $0 $1

$mon_echo mon_echo Bonjour
Bonjour
$
$ cat rend_executable
chmod +x $1
echo "$1 est devenu un programme executable."
$rend_executable dir
dir est devenu un programme executable.
$
```

On peut programmer directement en shell depuis la ligne de commande.

Exemple:

```sh
$ for i in 1 2 3;do echo bonjour;done
bonjour
bonjour
bonjour
$ for i in 1 2
> do echo bonjour
> done
bonjour
bonjour
$
```

Ici nous avons exécuté une boucle de deux manières différentes. La première fois nous avons écrit l'instruction complète, le shell l'a exécuté. La deuxième fois nous avons écrit l'instruction partiellement, le shell s'en rendant compte nous affiche le deuxième prompt (PS2) pour nous indiquer qu'il attendla suite de l'instruction pour l'exécuter.

Se reporter à la documentation UNIX pour avoir une description complète de possibilités du langage shell.

## Sauvegarde et archivage des fichiers.

### La commande "find"

Format : `find <liste de chemins> <expressions>`

Permet une recherche automatique de fichiers dans une partie de l'arborescence (recherche récursive) du système de fichiers de UNIX.

C'est une commande très gourmande en temps CPU, à utiliser avec modération.

&lt;liste de chemins&gt; est la liste des répertoires de recherches

&lt;expressions&gt; Défini le type de recherche.

convention d' écritures:

&lt;n&gt; sans signe signifie :égale valeur

&lt;n&gt; avec le signe plus signifie: supérieur ou égalàn.

&lt;n&gt; avec le signe moins signifie : inférieur ou égalàn.

options:

-name &lt;nom&gt; Vrai si le fichier a pourréférence &lt;nom&gt;

-perm &lt;nombre en octal&gt; Vrai si le fichier a pour droit d'accès &lt;...&gt;

-type &lt;x&gt; Vrai si le type de fichier est &lt;x&gt;.

&lt;x&gt; :

-   b fichier spécial de type block

-   c fichier spécial de type caractère

-   d fichier de type catalogue

-   f fichier de type ordinaire.

-   p pour les tubes nommés.(System III etV)

-links &lt;n&gt; Vrai si le fichiera&lt;n&gt; liens.

-user &lt;nom&gt;Vrai si le fichierapour propriétaire &lt;nom&gt;

-group &lt;nom&gt; Idem pour le groupe d'utilisateur.

-size &lt;n&gt;Vrai si le fichier a &lt;n&gt; blocs.

-atime &lt;n&gt; Vrai si le fichier a été consulté depuis &lt;n&gt; jours

-mtime &lt;n&gt; Vrai si le fichier a été modifiédepuis &lt;n&gt; jours.

-inum &lt;n&gt; Vrai si le fichier a pour i-node &lt;n&gt;.

-print Affiche les noms des fichiers répondant à &lt;expressions&gt;.

Toutes ces primitives peuvent être composées avec l'opérateur de négation "!".

### La commande "cpio"

C'est la commande de sauvegarde des fichiers et des répertoires. Elle s'emploie selon trois formes, par défaut la commande attend la liste des fichiers à sauvegarder depuis l'entrée standard (&lt;Ctrl-d&gt; pour terminer). Elle s'utilise le plus souvent avec la commande "find".

#### cpio -p &lt;directory&gt;

Format : `cpio -p [adlmruv] <répertoire>`

Lit la liste des fichiers à sauvegarder sur l'entrée standard et les sauvegarde dans &lt;répertoire&gt;.

#### cpio -o (output = sortie)

Format : `cpio -o [aBcv]`

copie les fichiers sur la sortie standard en indiquant le chemin et le statuts.

#### cpio -i (input = entrée)

Format : `cpio -i [BcdmrtuvfsSb] [patterns]`

Lit l'entrée standard et recrée la structure de l'arborescence indiquée par l'entrée.

#### Les options:

a Remet à 0 les temps d'accès des fichiers d'entrées.

B l'entrée et la sortie se font par bloc de 5120 octets (A n'utiliser qu'avec redirection sur des devices par

blocs, des lecteurs de bandes par exemple).

d Les répertoires sont créés s'il y a lieu.

c Ecrit l'en-tête en ASCII (pour la portabilité).

r Renomme les fichiers (de manière interactive)

t Affiche la liste des fichiers d'entrées (Rien n'est créé, utile pour vérifier que tout c'est bien passé).

u copie inconditionnelle (normalement les fichiers plus anciens ne remplacent pas les fichiers plus jeunes).

v affiche sur la sortie une liste des fichiers affichés.

l Essaye de créer des liens plutôt que la recopie des fichiers.

f copie tout les fichiers sauf ceux définis dans \[patterns\]

s échange l'ordre des octets.

S échange l'ordre des demi-mots.

b équivalent aux options s et S.

### La commande "tar"

Format : `tar [<clés>] [<fichiers> ...]`

Permet d'archiver des fichiers sur un fichier unique sur bande magnétique, ainsi que leur restitutions. A l'origine pour l'usage des lecteurs des bandes ( tar : pour **t**ape **ar**chive ) cet outil est encore d'usage courant.

&lt;clés&gt; Permet de contrôler le type d'opération :

-   r Ecriture des fichiers en fin de bande.

-   x Extraction des fichiers de la bande, si le nom est un répertoire il est créé et les caractéristiques des fichiers sont respectés si possibles.

-   t Liste les fichiers de la bande sans extraction.

-   u Sauvegarde les fichiers en fin de bande s'ils n'y sont pas déjà.

-   c Création d'une nouvelle bande.(sauvegarde en début de bande)


Les paramètres des clés sont les suivants:

-   0..7 Sélectionne le dérouleur de bande.

-   v Le nom de chaque fichier est affiché

-   w Avant chaque opération affiche le fichier en cours et demande confirmation à l'utilisateur.

-   f Le nom de l'argument suivant est utilisé comme référence du fichier d'archive.(Par défaut c'est /dev/rmt0 (dérouleur de bande 0)


-   m Demande la non-restitution de la date,la date courante est alors utilisée.

-   z Compresse ou décompresse les données suivant les cas

!!! note
    Il n'y a pas de caractère "-" au début des options !!.

    Si le nom du fichier avec l'option `f` est "-" c'est la sortie standard qui est utilisée.

!!! example "Exemple:"
    récopie du répertoire courant vers un autre endroit
    ```bash
    $ tar cf - . | ( cd /tmp; tar xvf - )
    ```

### La commande "ar"

Format : `ar [options] <nom de librairie> [<liste-de-fichiers>]`

Permet d'archiver des fichiers et de créer des bibliothèques de fichiers objets (pour les compilateurs.)

options:

-d supprime les fichiers spécifiés de la bibliothèque.

-r Remplace les fichiers spécifié dans la bibliothèque.

-q Rajout des fichiers en fin de bibliothèque.

-t Impression du contenu des fichiers de la bibliothèque ou de la liste des fichiers

-p Impression des modules de la bibliothèque.

-m déplacement des modules en fin de bibliothèque.

-x Extraction des fichiers de la bibliothèque.

-v option d'affichage détaillé.

### La commande "cmp"

Format : `cmp [option] <fichier1> <fichier2>`

Permet de comparer deux fichiers.

options :

-l Toutes les différences sont signalées par le numéro du caractère en décimal et sa valeur en octal.

-s aucune sortie, la commande est utilisée pour avoir un code de sortie.

## Commandes additionnelles

### La commande "crypt"

Permet de coder un fichier, affiche sur la sortie standard le fichier codé. Les fichiers sont codé par un algorithme en fonction de la clé que vous donnez.

### La commande "od"

Format : `od [options] <fichier>`

Permet de réaliser un "dump" du fichier spécifié.(par défaut en octal.) .

options:

-b Les mots sont interprétés en octal

-c les octets sont interprétés en ASCII

-d Les mots sont interprétés en décimal

-o Les mots sont interprétés en octal

-x les mots sont interprétés en hexadécimal

### La commande "touch"

Format : `touch [options] [date] <fichier> ...`

Permet de changer la date de dernière modification des fichiers spécifiés. Si aucune date n'est donnée, la date courante est utilisée.

options:

-a Change la date d'accès.

-m Change la date de modification.

-c Empêche la fonction "touch" de créer le fichier si celui-ci n'existe pas.

### La commande "split"

Format : `split [-<n>] [<fichier> [<nom>] ]`

Permet de découper un fichier en plusieurs fichiers. Par défaut découpe le fichier toute les 1000 lignes si -&lt;n&gt; n'est pas spécifié . Les fichiers de sorties ont pour nom &lt;nom&gt; avec les lettres 'aa' à 'zz' (au maximum 676 fichiers) Si &lt;nom&gt; n'est pas spécifié "x" est pris par défaut.

## Les commandes d'administration du système

### La commande "su"

Permet de passer en mode super-utilisateur(Plus de protection dans le système UNIX, à condition d'avoir le mot de passe. Plutôt remplacé par `sudo` qui permet de donner des accès à certaines commandes à un utilisateur donné sans que celui-ci ne connaisse le mot de passe de root.

### La commande "sudo"

De nos jours on évite de passer en root directement, on passe plutôt par la commande `sudo` qui permet de donner des droits plus fin aux utilisateurs.

### La commande "sar"

Permet d'avoir des renseignements sur l'activité du système UNIX. Se reporter à la documentation UNIX pour plus de détails.


## La commande de configuration du terminal "stty"

Format : `stty [-a][-g] [options]`

La commande "stty" permet de connaître l'état du paramétrage de la ligne du terminal ainsi que de le reconfigurer.

Sans arguments donne l'état de la ligne.

-a donne l'état complet de la ligne.

-g donne l'état de la ligne dans un format permettant de configurer un autre terminal (via les tubes).

Sans "-" pour actionné l'option, Avec "-" pour la désactiver.

### Les modes de contrôles

parenb autorise le contrôle de parité.

parodd parité impaire

cs5 cs6 cs6 cs8

Nombre de bits de données.

50..300...1200..9800 Vitesse de transmission de la ligne.

cstopbutilise 1 bits de stop (sinon 2)

### Les modes d'entrées

ignbrk ignore le break;

ignpar ignore les erreurs de parité.

istrip compacte sur 7 bits les données.

inclr le caractère &lt;New-line&gt; est interprété comme &lt;return&gt;

icrnl le &lt;return&gt; est interprété comme &lt;new-line&gt;

iuclc Interprète les majuscules comme des minuscules.

ixon Autorise le contrôle de flux (&lt;Ctrl-s&gt;)

ixany Tout caractère relance l'affichage (sinon uniquement &lt;Ctrl-q&gt;)

ixoff Le système envoie des START/STOP suivant l'état des buffers

### Les modes de sorties

opost Les caractères en sortie doivent être traiter (par l'une des options suivantes)

olcuc identifie les minuscules en majuscules

onlcr &lt;new-line&gt; comme la suite &lt;return&gt; &lt;new-line&gt;

onocr les &lt;return&gt; en tête de ligne sont ignorés.

onlret sur le terminal &lt;new-line&gt; est interprété comme &lt;return&gt;

### Les modes locaux

echo envoie l'écho de chaque caractère

echoe l'écho du caractère &lt;erase&gt; est la suite &lt;backspace&gt; &lt;espace&gt; &lt;backspace&gt;

icanonles caractères sont entrés en modes lignes délimités par &lt;new-line&gt;

noflshne vide pas les buffers après une interruption INTR, QUIT, ou SWTCH

isig Autorise le test des caractères en entrée pour détecter les interruptions INTR,QUIT,SWTCH

> Se reporter à la documentation pour une information plus détaillée.
>

## Index des commandes

[ar](#la-commande-ar), 
[at](#la-commande-at), 
[banner](#la-commande-banner), 
[cat](#la-commande-cat), 
[cd](#la-commande-cd), 
[chgrp](#la-commande-chgrp), 
[chmod](#la-commande-chmod), 
[chown](#la-commande-chown), 
[cmp](#la-commande-cmp), 
[cp](#la-commande-cp), 
[cpio](#la-commande-cpio), 
[crypt](#la-commande-crypt), 
[echo](#la-commande-echo), 
[env](#la-commande-env), 
[export](#la-commande-export), 
[find](#la-commande-find), 
[grep](#la-commande-grep), 
[kill](#la-commande-kill), 
[ln](#la-commande-ln), 
[logname](#la-commande-logname), 
[lp](#la-commande-lp), 
[ls](#la-commande-ls), 
[man](#la-commande-man), 
[mkdir](#la-commande-mkdir), 
[mv](#la-commande-mv), 
[nice](#la-commande-nice), 
[nohup](#la-commande-nohup), 
[od](#la-commande-od), 
[passwd](#la-commande-passwd), 
[paste](#la-commande-paste), 
[pg](#la-commande-pg), 
[pr](#la-commande-pr), 
[ps](#la-commande-ps), 
[pwd](#la-commande-pwd), 
[rm](#la-commande-rm), 
[rmdir](#la-commande-rmdir), 
[sar](#la-commande-sar), 
[set](#la-commande-set), 
[sort](#la-commande-sort), 
[split](#la-commande-split), 
[su](#la-commande-su), 
[sudo](#la-commande-sudo), 
[tar](#la-commande-tar), 
[touch](#la-commande-touch), 
[wait](#la-commande-wait), 
[wc](#la-commande-wc), 
[who](#la-commande-who), 
