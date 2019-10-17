# Langage C niveau 1

SUIVI DES VERSIONS DU DOCUMENT

Creation : 1990/10/20

Last change : 2019/10/05 passage en markdown, et aux compilateurs actuelxs.

------
[TOC]

## Présentation générale

### Introduction, historique.

Le langage C a été développé par DANIEL RITCHIE au même moment que le système d'exploitation UNIX. Unix a été écrit quasi entièrement en langage C (Sur 13000 lignes de codes, seulement 800 sont écrites en assembleur). Ce n'était pas la première fois qu'un système d'exploitation était écrit dans un langage évolué, mais UNIX est le premier à connaître une large diffusion.

Le langage C est un langage structuré de haut niveau ne faisant que peu (ou pas du tout) de contrôles de type.

Exemple : la variable 'c' étant défini comme caractère 'c = 65;' est correct pour le compilateur C alors que l'équivalent en Pascal (Langage de haut niveau très strict sur les contrôles de type) ferait hurler le compilateur. Les faiblesses du langage C viennent de l'objectif même de ses concepteurs : écrire le système UNIX. Il ne comporte aucune instruction d'entrées sorties de gestion de la mémoire etc \...

Tous ces mécanismes sont fournis dans une bibliothèque de fonctions dans l'environnement système, heureusement le noyau des fonctions (environ 300 fonctions) est le même quelque soit le système sur lequel on travaille que se soit UNIX ou non.

A l'heure actuelle le langage C est normalisé par l'ANSI (depuis décembre 1989).

Le présent document présente les principales difficultés du langage C, il ne constitue pas un cours, pour de plus plus amples détails on se reportera au livre \"Le langage C de Kerningham et Ritchie.\" et si possible à la dernière version .

### Un premier programme.

```C
/* $cat mini.c */
void main(void){
}
```

```bash
$cc mini.c
$a.out
$
```

Rajoutons une ligne grâce à l'éditeur vi.

```c
/* $cat mini.c */
##include <sdtio.h>

void main(void)
{
	printf("Bonjour.\n"); /* Ceci est un commentaire */
}
```

```bash
$cc mini.c
$a.out
Bonjour.
$
```

Un programme C est formé d'une ou plusieurs fonctions. Une seule est obligatoire, celle qui a pour nom 'main'. En fait c'est le point d'entrée du programme : c'est la première fonction que le programme exécute. La fonction 'main' peut se trouver n'importe où dans le programme (en général au début ou à la fin du programme pour des questions de lisibilité.).

La fonction 'main' exécutera en général d'autres fonctions soit celles qui proviendront du programme lui-même, soit celles qui proviennent de bibliothèques, 'printf' est l'une de ces fonctions sa déclaration se trouve dans le fichier `stdio.h` qui se trouvent dans le répertoire `/usr/include` (sous UNIX).

Les parenthèses qui suivent le nom de la fonction encadrent les paramètres qui lui sont passés. Les accolades encadrent les instructions à exécuter (équivalent au Begin End du Pascal). Les commentaires sont encadrés par les suites de caractères '/\*' et '\*/'.

Un exemple plus conséquent :

```c
/*  min.c */
##include <stdio.h>
/* 
 * La fonction min renvoie le plus petit des deux entiers qui
 * lui sont passé en paramètres.
 */

int min(int a,int b)
{
	return( a < b ? a : b);
}

void main.c(){
	printf("le minimum de 4 et 10 est : %d\n",min(10,4));
}
```

```sh
$cc -o min min.c
$min

le minimum de 4 et 10 est : 4
$
```

## Les types et les variables

### Les variables.

Les variables peuvent être définies à l'extérieur ou à l'intérieur des fonctions.

A l'intérieur des fonctions les variables n'existent qu'à partir de l'endroit où elles sont déclarées.

```c
/* $cat var.c */
##include <stdio.h>

int globale_au_fichier;

void ma_procedure()
{
	int locale_a_la_fonction;
    
    locale_a_la_fonction = 2;
    globale_au_fichier = 4;
    printf("procedure: locale_a_la_fonction = %d\n", locale_a_la_fonction);  
    printf("procedure: globale_au_fichier = %d\n", globale_au_fichier);   
}

void main(void)
{
    int locale_a_la_fonction = 1;
    
    globale_au_fichier = 1;
    ma_procedure();
    printf("main: locale_a_la_fonction = %d\n", locale_a_la_fonction);  
    printf("main: globale_au_fichier = %d\n", globale_au_fichier);   
	
}
    
```

!!! warning "Attention"
    le langage C fait la différence entre majuscules et minuscules,
    ici les appels à `bon()` et à `BON()` ne sont pas identiques, mais correspondent à deux fonctions différentes.
    
    Faire d'autant plus attention que sur certaines implantations du langage C le compilateur fait la différence mais pas l'éditeur de liens.

### Les types de bases.

- **char** :  caractères
- **short** : entiers courts
- **int** : entiers
- **long** : entiers longs
- **float** : réels
- **double** : réels double précision.

La taille de ces types (nombre d'octet pris en mémoire) varie suivant les versions. La seule chose qui vous est assuré est que:

char <= short <= int <= long <= float <= double

Tous ces types peuvent recevoir le mot clé `unsigned` pour non signé.

!!! example "Exemple :"
    ```c
    int i;
    unsigned char c;
    long j;
    ```



### Construction de types.

`[ ]` définit les vecteurs et tableaux

`struct` les structures (équivalent au record du pascal)

`union` équivalent au Record case du Pascal

`typedef` Permet de définir des types

`*`pour les pointeurs.

#### Les tableaux:

```C
int tab[32]; 		/* défini un tableau de 32 entiers */
int * ptr[32]; 		/* défini un tableau de 32 pointeurs sur des entiers.*/
/*
 * tableaux à plusieurs dimensions sont définis comme les vecteurs.
 */
int matrice[20][30]; /* défini un tableau de 20 lignes de 30 entiers.*/
```

!!! note
    Il n'est pas possible de borner un tableau le premier élément est toujours le numéro ZERO.

La taille d'un tableau est une constante, elle ne peut être définie dynamiquement.
le seul cas où la taille peut ne pas être définie est dans la déclaration de
variables d'une fonction. DAns le cas d'un tableau multi-dimensionnel seul le premier
niveau peut ne pas être défini.

Exemple :

```C
/* parcours_tab.c */
#include <stdio.h>

#define MAXSIZE 32

int tableau[MAXSIZE];
int i;

void main(int argc, char * argv[])
{
	for (i=0;i <=MAXSIZE-1; i++)
	{
		tableau[i] = i;
		/*
		 * parcours de TOUS les éléments du tableau 
  		 */
  	}
	for (i = 0; i < argc; i++){
		printf("argument %d: %s\n", i, argv[i]);
	}	
}
```

On pourrait tout aussi bien écrire le programme de la manière suivante :


```C
/* parcours_tab.c */
#include <stdio.h>

#define MAXSIZE 32

int tableau[MAXSIZE];
int i;

void main(int argc, char ** argv)
{
	for (i=0;i <=MAXSIZE-1; i++)
	{
		tableau[i] = i;
		/*
		 * parcours de TOUS les éléments du tableau 
  		 */
  	}
	for (i = 0; i < argc; i++){
		printf("argument %d: %s\n", i, argv[i]);
	}	
}
```
#### Les structures:

Il existe deux manières de définir des structures.

```c
struct {
	int x,y; 		/* Coordonnées d'un pixel \*/
	int couleur; 	/* couleur du pixel \*/
} pix, *p;
```


Ici on définit 'pix' comme étant un structure et 'p' comme étant un pointeur sur une structure. La structure définie n'a pas de nom. Les éléments sont accessibles par :

pix.x

pix.y

pix.couleur



```C
struct point {
	int x,y;
	int couleur;
} pix;

struct point *p;

```

La structure a un nom 'point' qui peut être réutiliser dans un programme.

Un autre moyen est d'utiliser le constructeur de type 'typedef'

```C
typedef struct _point{
	int x,y;
	int couleur;
} Point; /* le type point est définit CE N'EST PAS UNE VARIABLE */

Point pix;

struct _point *p;
```

le '\_point' au niveau de `typedef struct _point {` n'est pas obligatoire il peut être omis dans ce cas.

Les deux moyens sont bons, et utile dans certains cas pour faire des structures récursives.

```C
/* Définition d'une structure de type noeud */
typedef struct {
	noeud * fils_gauche; /* Interdit de faire cela */
	noeud * fils_droit;
	int valeur;
} noeud;

/*
 * Définition de 2 types de structures
 * noeud : objet de type noeud
 * noeudptr :  object de type pointeur vers un objet de type noeud
 */
typedef struct _noeud{
	struct _noeud * fils_gauche; /* On définit le nom '_noeud' */
	struct _noeud * fils_droit;  /* qui ne sera utilisé qu'ici */
	int valeur;
} noeud,*noeudptr; 

```

La manière la plus lisible est d'utiliser la déclaration avec `typedef`, de plus elle évite de réécrire à chaque fois le mot `struct`.

### Les classes des variables.

Dans un soucis de simplification, tout les modificateurs ont été regroupés. Les variables sont caractérisées par leur types et par leurs classe de stockage, c'est à dire leur visibilité : locale ou globale.

Les variables ont une classe par défaut qui dépend de l'endroit où elles sont définies.

Les classes sont : `auto`, `static`, `extern`, `const`, `volatile` et `register`.

#### auto

`auto` n'est autorisé que pour des variables locales à intérieure d'un bloc d'instruction, c'est la déclaration utilisée par défaut. En fait ne sert à rien, à part forcer l'optimiseur de code à ne pas utiliser `register`.

#### static

|             | dans une fonction                              | Hors d'une fonction                            |
| ----------- | ---------------------------------------------- | ---------------------------------------------- |
| Sans static | Dynamique, locale à la fonction                | globale à tous les fichiers                    |
| Avec static | Statique, permanente, visible dans la fonction | Statique, permanente, visible dans le fichier. |


#### extern

Permet de faire référence à une variable déjà déclarée, IL N'Y A PAS RESERVATION DE PLACE MEMOIRE, il est indispensable que la variable soit réellement déclarée dans un autre fichier ou module du programme.

En général, on peut se dispenser du mot clé `extern` mais certains compilateurs veulent que les variables ne soient déclarées qu'une seule fois dans tout le programme.

#### volatile
Permet de dire au compilateur de ne pas faire d'optimisation sur la variable. la variable peut être mise à jour à tout moment par une autre tache (thread).

#### const
`const` permet d'éviter la modification des variables. Elles peuvent juste être initialisées à la déclaration.

!!! example Exemple
```C
#include <stdio.h>

size_t longueur_de_chaine(const char chaine [] )
{
	register size_t longueur;
	for(longueur = 0; chaine[longueur]; longueur++);
	return longueur;
}

void main(int argc, char ** argv)
{
	int i;
	for (i = 0; i < argc; i++){
		printf("argument %2d  - longueur=%3ld - %s\n", i, longueur_de_chaine(*(argv+i)), argv[i]);
	}
}
```

#### register

Demande que la variable soit rangée dans un registre dans la mesure du possible, c'est à dire qu'il y ait un registre de libre et que la taille de la variable soit inférieure ou égale à celle du registre de la machine.

Ceci est surtout utilisé pour les variables de boucles et accélère de manière sensible l'exécution de programme.

!!! example "Exemple :"
    ```C
    /* sans.c */
    void main(void)
    {
    	int i,j,s;
    	for(i=1;i <=1000;i++)
    	{
    		s = 0;
    		for(j=0;j <10000;j+=i)
    			s+=j;
    	}
    }
    ```
    
    ```C
    /* $cat avec.c */
    void main(void)
    {
    	register int i,j,s;
    
    	for(i=1;i <=1000;i++)
    	{
    		s = 0;
    		for(j=0;j <10000;j+=i)
    			s+=j;
    	}
    }
    ```

```sh
$cc -o sans sans.c
$cc -o avec avec.c
$time sans
0.8 real
0.7 user
0.0 sys

$time avec
0.7 real
0.3 user
0.0 sys
$
```

Avec les machines actuelles il faudra peut être rajouter deux 0 dans les boucles pour voir quelque chose.

### Les constantes.

Les constantes peuvent être de type :

entier : 12 , 012 , 0xff , 0L

réel : 35.2 , .78e-23

caractère : 'c' , '\\n' , '\\007'

chaîne : \"\\0x07Chaine qui \\\"sonne\\\" et va à la ligne \\n\"

Les constantes entières peuvent être en base 10,base 8 (Premier chiffre est un 0 ) ou en base 16 (commençant par 0x). le suffixe `L` indique une constante de type long.

Le caractère `'` joue le rôle de caractère d'échappement, il permet de représenter certains caractères:

`\n` fin de ligne

`\t` tabulation

`\b` backspace

`\r` retour chariot

`\f` form feed (saut de page)

`\\` \\

`\"` "

`\'` '

`\0` le caractère de code ASCII zéro NULL

Le caractère `\` permet d'*échapper* un caractère dans les définitions de constantes caractère ainsi que dans les constantes chaîne.

!!! example "Exemple"
    chaîne formée de deux guillemets : `"\"\""`.

### Les opérateurs.

#### Les opérateurs logiques:

**\<** inférieur

**>** supérieur

**=\>** Supérieur ou égal

**<=** inférieur ou égal

**==** égal

**!=** différent

**!** non logique

**&&** et logique

**\|\|** ou logique

#### Les opérateurs arithmétiques:

**+** plus

**-** moins

**\*** multiplication

**/** division

**%** modulo

**++** auto-incrémentation (préfixe '++var'ou postfixe 'var++')

**--** auto-décrémentation (idem)

#### Les opérateurs sur les bits:

**~** complément

**&** et

**|** ou

**^** ou exclusif

**<<** décalage de bits vers la droite

**>>** décalage de bits vers la gauche

!!! note "Remarque"
    pour les opérateurs arithmétique et sur les bits on notera le raccourci suivant : 
    `a (op)=b` équivaut à `a = a (op) b`

    Ceci est un raccourci d'écriture mais correspond aussi à une optimisation du code du programme.

#### Les opérateurs sur les pointeurs

**\*** indirection

**&** adresse d'une variable

**->** accès aux champs d'une structure ( p-\>x est équivalent à (\*p).c )

Certains opérateurs acceptent des pointeurs :

\+ , - , ++ , \-- opérateurs arithmétiques

\* , -\> indirections

(TYPE) conversion de type

< , > , <= , => , == , != opérateurs de comparaison

!!! example "Exemple"
    si p est un pointeur sur un objet et i un entier `p + i` est l'adresse du i-ème objet suivant l'objet pointé par p

#### Autres opérateurs:

`(TYPE)` Opérateur unaire permettant de convertir une variable dans le type TYPE .

`sizeof(OBJET)` Taille de l'objet en octets (peut être une variable ou le type d'une variable)

= Affectation simple.

`e ? e1 : e2` Expression conditionnelle sa valeur est e1 si e est vrai e2 sinon.

`e1,e2,...,eq` Liste d'expressions évaluées séquentiellement de e1 puis e2 jusqu'à eq, la valeur de la liste vaut eq

Exemple : `(i=2,j=i++,5*j-i)` a pour valeur 7, de plus i vaut 3 et j vaut 2

### Booléens.

Il n'y a pas de variables booléennes (au contraire du Pascal) les expressions sont évalués numériquement, un 0 correspond à FAUX, tout autre valeur correspond à VRAI.

## Les Pointeurs

Une variable de type pointeur est une variable contenant une adresse. On peut définir des pointeurs sur des variables de type de base ou sur des variables construites à partir des types de bases.

Le type pointeur d'un objet de type 'TYPE' est : 'TYPE \*' .

Exemple :

```C
int * p; /* Pointeur sur un entier */
struct _point * pixptr;/* Pointeur sur un objet de TYPE _point */
```

L'objet pointé par le pointeur 'p' est noté : '\*p' , l'adresse d'un objet 'q' est notée ' &q ';


Exemple : (sur les versions actuelles peut donner un warning à la compilation, ne pas en tenir compte)

```C
/* $cat demoptr.c */
##include <stdio.h>

void main(void){
	int i;
	int *p;
	char *ch;

	i = 10;

	p = &i; /* p contient l'adresse de la variable i */
	ch = "Ceci est une chaîne.\n";

	/*
	 * ch contient l'adresse de la chaîne qui sera rangée dans le
	 * segment des données au moment de la génération de code. Le
	 * délimiteur de chaîne EST rajouté au moment de la génération de
	 * code.
	 */
	printf("Valeur du contenu à l'adresse de p est %d\n",*p);
	printf("%s",ch);
	printf(ch); /* donne la même chose que la ligne précédente */
}
```

```sh
$cc -o demoptr.e demoptr.c
$
$demoptr.e
Valeur du contenu à l'adresse de p est 10
Ceci est une chaîne.
Ceci est une chaîne.
$
```

Les opérations sur les pointeurs sont :

L'affectation simple : **=**

Les opérations arithmétiques : **+** , **-** , **++** , **\--**

L'indirection : **\*** , **-\>**

Les conversions de type et le calcul de la taille.

Les opérateurs de comparaison.

### Affectation des pointeurs.

La déclaration d'un pointeur réserve de la place pour le pointeur **ET NON** pour l'objet pointé.

Exemple :

```C
/* $cat faux.c */

void main(void)
{
	int *p; /* Réservation de place pour le pointeur uniquement */
	*p = 120; /* Pas de réservation de place pour l'entier */
}
```

```sh
$cc -o faux faux.c
$faux

Bus error (core dumped)
$

```

ATTENTION la différence de type entre les deux membres lors d'une affectation n'est pas traitée comme une erreur fatale mais donne lieu à un 'warning'.

Exemple :

```C
/* $cat demoptr2.c */
##include <stdio.h>

void main(void)
{
	long i;
	long *p;
	char *c;

	i = p; /*Donne lieu à un warning mais pas une erreur fatale */
	i = (long) p;
	/*
	 * Bonne méthode ne donne lieu à aucun commentaire de la part
	 * du compilateur et l'on sait ce que l'on fait !!!!
	 */
	i = 0x41424344;
	p = &i;
	c = (char *)p;

	/* La valeur du pointeur 'p' est convertie en pointeur sur
	 * caractère
	 */
	printf("%c\n",*c);
	/* Affiche le contenu du premier octet de la variable 'i' ou le dernier*/
}
```

La règle à appliquer est de toujours écrire des expressions homogènes pour éviter les warnings, de plus l'on sait ce que l'on fait !!!! (En principe.)

#### Les pointeurs et les chaînes de caractères.

Une chaîne de caractères en C est est une suite d'octets se terminant par le caractère de code ASCII zéro (NULL).

Ainsi \"chaine\" est une constante ayant pour valeur l'adresse d'un zone mémoire dont les 7 premiers octets ont pour valeur 'c' 'h' 'a' 'i' 'n' 'e' ET '\\0'.

Exemple :

```C
/* $cat demoptr3.c */

##include <stdio.h>

char *p,c;
int i;

void main(void)
{
    p = "ABCDEFGHIJKLMNO";
    c = *(p+2); /* c contient le caractère 'C'. */
    i = *(((int *) p) + 1);

    printf("sizeof(int*) = %ld\n", sizeof(int*));
    printf("sizeof(int) = %ld\n", sizeof(int));
    printf("i = %x\n", i);
}
```

Regardons la dernière expression de plus prés :

`(int *) p` : p est un pointeur sur des caractères il est converti en pointeur sur un entier.

`((int *) p) + 1` : On obtient l'adresse de l'entier suivant, le déplacement dépend de l'implémentation sur la machine du langage, en pratique on se déplace de 2, 4 ou 8  octets

`*(((int *) p) + 1)` : On obtient la valeur de l'entier suivant (0x45464748 ou 0x48474645 suivant la taille des indiens).

On peut construire une chaîne de caractères de différentes manières:

- En utilisant les guillemets, la caractère de fin de chaîne (NULL) est automatiquement rajouté.
- En remplissant \"à la main\" les zones d'un tableau.
- En utilisant des fonctions de la bibliothèque standard du C tel que strcpy, strcat \...

Exemple:

```C
/* $cat chaine.c */
##include <stdio.h>
##include <string.h>

void main(void)
{
	char ch[10],chh[10];
	char *chaine;

	chaine = "ijklmn"; 		/* 1ère méthode */
	ch[0] = 'a'; 			/* 2ème méthode */
	ch[1] = 'b';
	ch[2] = '\0';

	(void)strcpy(chh,"cdefgh");	/* 3ème méthode */
	(void)strcat(ch,chh);

	printf("chaine contient : %s\n",chaine);
	printf("chh contient : %s\n",chh);
	printf("ch contient : %s\n",ch);

	ch[4] = '\0';

	printf("La chaine S'ARRETE au premier caractère '\\0'\n");
	printf("ch vaut maintenant : %s\n",ch);
}
```

A l'exécution :

```sh
$./a.out
chaine contient : ijklmn
chh contient : cdefgh
ch contient : abcdefgh
La chaine S'ARRETE au premier caractère '\0'
ch vaut maintenant : abcd
$
```



### Procédures et fonctions.


En C il n'y a pas de différence entre une procédure et une fonction, par défaut une fonction retourne un entier. Une procédure étant une fonction qui ne retourne pas de valeur.

Une fonction peut également retourner l'un des types de base ou un pointeur. 

Attention dans une fonction les variables sont de classe 'auto' c'est à dire dynamique. En fait elles sont allouées dans la pile et disparaissent après l'exécution de la fonction.

En C Les paramètres d'un fonction sont TOUS passés par valeurs. Si l'on veut passer des paramètres par référence il est nécessaire de passer l'adresse de la variable.

Exemple :

```C
/* $cat para.c*/
##include <stdio.h>
/* La fonction swap1 ne marche pas */
void swap1(int a,int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

/* La fonction swap marche. */
void swap(int * a,int * b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void main(void)
{
	int a,b;
	
    a = 10;
	b = 5;
	printf("Les valeurs de a et b sont a=%d , b=%d\n",a,b);
	swap1(a,b);
	printf("la fonction swap1 ne marche pas a=%d , b = %d\n",a,b);

	swap(&a,&b);
	printf("la focntion swap marche a=%d , b = %d\n",a,b);
}
```



### Pointeur de fonction.

On peut définir des fonctions sur n'importe quel type de variables; on peut aussi déclarer des pointeurs sur des fonctions.

Exemple:

```C
/* $cat foncptr.c */
##include <stdio.h>

typedef int (*adfonc) (int i);

/* declare adfonc comme pointeur de fonction retournant un entier. */

int f0(int i)
{
	printf("La valeur du paramètre de f0 est %d\n",i);
}

int f1(int i)
{
	printf("La valeur du paramètre de f1 est %d\n",i);
}

int f2(int i)
{
	printf("La valeur du paramètre de f2 est %d\n",i);
}

void main(void)
{
    int i;
	adfonc tab[3] = {f0,f1,f2};
	for (i=0;i<3;i++){
    	(*tab[i])(i);
    } 
}
```



```sh
$foncptr
La valeur du paramètre de f0 est 0
La valeur du paramètre de f1 est 1
La valeur du paramètre de f2 est 2
$
```



Remarque : On écrit tab\[0\] = f0; et non tab\[0\] = &f0; car f0 est une constante dont la valeur est l'adresse de la fonction f0() tout comme pour un tableau où t et &t\[0\] sont équivalents.

### Récupération des paramètres d'une commande.

La plupart des commandes UNIX demandent des paramètres pour s'exécuter. De même, il est possible de récupérer des paramètres passés sur la ligne de commande pour nos propres programmes C.

Exemple:

```C
/* cat litarg.c */
##include <stdio.h>
void main(int argc,char ** argv)
{
	int i;
	for(i=0;i<argc;i++)
		printf("Argument n° %d est %s\n",i,argv[i]);
}
```

```sh
$cc -o arg litarg.c
$arg bonjour cc -o argument
Argument n° 0 est arg
Argument n° 1 est bonjour
Argument n° 2 est cc
Argument n° 3 est -o
Argument n° 4 est argument
$
$arg
Argument n° 0 est arg
$
```

On remarque qu'un programme possède au moins un argument : le nom du programme.

NOTE : Si vous travaillez sous UNIX Essayer 'arg \*' cela vous donnera la liste des fichiers sous votre directory courante.

```sh
$arg *.c
Argument n° 0 est arg
Argument n° 1 est lit_arg.c
Argument n° 2 est foncptr.c
Argument n° 3 est para.c
$
```

Sous UNIX (ou DOS) il est possible de lire la table d'environnement passée au programme; la déclaration est la suivante :

```C
/* $cat env.c */
##include <stdio.h>

void main(int argc, char ** argv, char ** envp)
{
	int i;
	
    for(i=0;envp[i];i++)
        printf("%s\n",envp[i]);
	/* La condition est fausse quand envp[i] vaut NULL (c.à.d 0) */
}

```

```sh
$env
PATH=:/usr/bin:/bin
HOME=/usr/alfred
TZ=GMT0
TERM=VT100
$
```

Permet de lire la table d'environnement.

### Allocation dynamique.

L'allocation dynamique nous permet de réserver de l'espace mémoire durant l'exécution du programme.

Exemple sur des listes chainées :

```C
/* cat liste.c */

##include <stdio.h>  /* Fonctions standards d'entrées sorties */
##include <stdlib.h> /* pour malloc */
##include <string.h> /* Fonctions de manipulations de chaines */

##define MAXSIZE 32

typedef struct _LISTE {
	char nom[MAXSIZE];
	struct _LISTE * suivant;
} LISTE, *LISTEPTR;

LISTEPTR deblist = NULL; /* pointeur initialisé à vide */
LISTEPTR finlist = NULL;

/*
 * Fonction d'ajout d'un élément
 */
LISTEPTR ajoute(char * s)
{
	LISTEPTR p;
	/* Allocation d'une nouvelle structure */
	p = (LISTEPTR) malloc(sizeof(LISTE));
    /* mise à 0 de la partie memoire obtenue */
    (void) memset(p, sizeof(LISTE), 0);

	/* si p vaut NULL il n'y a plus de place */
	if (p == NULL) {
		fprintf(stderr,"Dépassement capacité mémoire !!\n");
		exit(1);
	}
	if (deblist == NULL){
		deblist = finlist = p;
	}else{
		finlist->suivant = p;
		finlist = p;
		finlist->suivant = NULL;
	}
    /* on recopie en gardant un ocet pour le caratere de fon de chaine */
	strncpy(finlist->nom, s, MAXSIZE-1);
    return finlist;
}

/*
 * Supprimme un élément de la liste
 */
void supprime(LISTEPTR pl)
{
	LISTEPTR p,q;

	if (pl == NULL) return; /* Si chaine vide on ne fait rien */
	p = q = deblist; /* Initialisation de p et q */

	if (pl == deblist){
		deblist = deblist->suivant;
        if (pl == finlist)
            finlist = NULL;
	}else{
		do { 			/* Parcours de la liste */
			q = p;		/* jusqu'à pl */
			p = p->suivant;
        } while((q->suivant != pl) || (p == NULL));
		if (p == NULL) return; /* Si pl n'est pas dans la liste */
		q->suivant = p->suivant;
        if (q->suivant == NULL) /* si c'est le dernier element */
            finlist = q;
	}
    free(pl);
}

void main(void)
{
    LISTEPTR p;
    LISTEPTR curptr = NULL;
    
	(void)ajoute("alfred");
	curptr = ajoute("michel");
	(void)ajoute("robert");
    (void)ajoute("un tres long nom de prenom qui depasse les 32 caractères");

	/* On affiche la liste */

	for(p=deblist;p;p=p->suivant)
		printf("%s\n",p->nom);
	supprime(curptr); /* On supprime michel*/
	printf("michel est supprimé\n");

	for(p=deblist;p;p=p->suivant)
		printf("%s\n",p->nom);
}
```

```sh
$
$./liste
alfred
michel
robert
michel est supprimé
alfred
robert
$
```

La fonction d'allocation de mémoire est 'malloc' elle alloue le nombre d'octets passé en paramètre.

!!! warning "Attention"
    toujours passer par la fonction sizeof() pour determiner la taille d'une structure, ceci pour des problèmes de portabilité.

Exemple :

```C
/* mauvais.c */
void main(void)
{
	int *p;
	p = (int *)malloc(2);
	
	*p = 12*256*256;
}
```



```C
/* bon.c */
void main(void)
{
	int *p;
	p = (int *)malloc(sizeof(int));
	
	*p = 12*256*256;
}
```

Le programme 'mauvais.c' marche sur DOS où la taille des entiers est de 2 octets; mais pas sur d'autres machines où la taille des entiers est de 4 octets (système d'exploitation 32 bits).

## Le Préprocesseur C : cpp


Le préprocesseur permet de faire de la compilation conditionnelle, de définir des macros (comme en assembleur), et de donner des directives de compilation. Toutes ces instructions commencent par le caractère \#. Certains compilateurs tiennent absolument à ce que ce soit le premier caractère d'une ligne.

ATTENTION toutes les directives (commençant par \#) ne se terminent pas par un point-virgule.

### \#define

Permet de définir des entités des macros instructions. Une ligne trop longue peut être coupée par le caractère d'échappement `\`.

Exemple :

`#define _UNIX` l'entité \_UNIX est définie.

`#define MAX 43` Dans tout le programme suivant la définition MAX sera remplacé par 43

```C
/* $cat pre.c */
##include <stdio.h>

##define COMMENTAIRE() { \
    printf("Un #define trop long"); \
    printf(" être coupé par le caractère \\"); \
    printf("\n"); \
    }

##if 0
##define STRCAT(a,b) a/**/b
##endif

##define carre(x) ((x)*(x))

##define fauxcarre(x) x*x

##define MAX 43

int i;

void main(void)
{
	i = 4;#include <stdio.h>
##include <string.h>

##define COMMENTAIRE() { \
    printf("Un #define trop long"); \
    printf(" peut être coupé par le caractère \\"); \
    printf("\n"); \
    }

##if 1
##define STR(FONC) str ## FONC
##define TOSTR(FONC) #FONC
##endif

##define carre(x) ((x)*(x))

##define fauxcarre(x) x*x

##define MAX 43

int i;

void main(void)
{
	i = 4;
    char chaine[32] = "str";

	COMMENTAIRE();
	printf("MAX MAXSIZE %d\n",MAX);
    printf("i vaut %d\n", i);
	printf("Le resultat de carre(i+1) est %d\n",carre(i+1));
	printf("Le resultat de fauxcarre(i+1) est %d\n",fauxcarre(i+1));
##if 1
    printf("%s\n", STR(cat)(chaine,TOSTR(cat)));
##endif
}
	COMMENTAIRE();
	printf("MAX MAXSIZE %d\n",MAX);
    printf("i vaut %d\n", i);
	printf("Le resultat de carre(i+1) est %d\n",carre(i+1));
	printf("Le resultat de fauxcarre(i+1) est %d\n",fauxcarre(i+1));
##if 0
    printf("%s\n", STRCAT(str,cat)("aaa", "bbb"));
##endif
}
```

```sh
$cc -o pre pre.c
$./pre
un #define trop long peut être coupé par le caractère \
MAX MAXSIZE 43
i vaut 4
Le resultat de carre(i+1) est 25;
Le resultat de fauxcarre(i+1) est 9
strcat
$
```

On remarque sur cet exemple tout l'intérêt d'utiliser lesparenthèses dans les pseudo-fonctions.

l'expression `carre(i+1)` est remplacé AVANT génération de code par `(i+1)*(i+1)`

L'expression `fauxcarre(i+1)` est remplacé par : `i+1*i+1` soit par `i+i+1` ce qui n'est pas le résultat espéré

#### directive #

Le # permet de changer le paramètre en chaine de caractère, comme dans la macro de l'exemple précédent `TOSTR()`.

#### directive ##

le ## permet la concaténation de 2 mots, comme la macro `STR()`de l'exemple précèdent.

Ces deux directives permettent de faire du pseudo objet, ou de simplifier des définitions laborieuses.

### Compilation conditionnelle.

Exemple:

```C
/* $cat cond.c */

##define _UNIX

void main(void)
{
##ifdef _UNIX
	printf("Un :_UNIX est défini\n");
##else
	printf("Un : _UNIX n'est pas défini\n");
##endif
    
##undef _UNIX

##ifdef _UNIX
	printf("Deux : _UNIX est défini\n");
##else
	printf("Deux : _UNIX n'est pas défini\n\");
##endif
           
}
```

```sh
$cond
Un : _UNIX est défini
Deux : _UNIX n'est pas défini
$
```

\#undef permet de supprimer une 'variable' précédemment définie.

\#ifdef équivalent à if

\#else équivalent à else

### Directives de compilation.

La directive '\#include' permet d'inclure des fichiers.

Exemple :

```C
##include <stdio.h>
##include "myinclude.h"
```

Les noms de fichiers entre \< et \> seront cherchés dans le répertoire par défaut du système, sur UNIX dans le répertoire `/usr/include`

Les noms de fichiers entre \" et \" seront cherchés dans le répertoire courant ou les répertoires spécifiés sur la ligne de commande du compliateur puis dans le(s) répertoire(s) par défaut.

## Les fonctions standards d'entrées sorties.


Les I/O sont de deux sortes : les I/O de haut niveaux qui sont formatées et en général bufferisées.

fopen(),open() : ouverture

fscanf(),read() : lecture formattée, non formattée

fprintf(),write() : écriture formatée, non formattée

fseek(),lseek() : positionnement

fclose(),close() : fermeture

Les fonctions f\... travaillent avec un pointeur sur le descripteur de fichier, les autres avec le numéro du descripteur.

### les entrées sorties par défaut

TROIS Fichiers sont ouverts par défaut :

stdin : entrée standard (clavier par défaut)

stdout : sortie standard (écran par défaut)

stderr : sortie standard (erreur (écran par défaut)

Ils occupent respectivement les numéros de descripteur 0,1 et 2.

Ainsi les appels :

printf(\"\.... sont équivalents à fprintf(stdout,\"\...

scanf(\"\.... sont équivalents à fscanf(stdin,\"\...

Exemple:

```C
void main(void)
{
    int fd,n;
	fd = open("test",0); /* 0 : Ouverture en lecture */
	for(n=0;read(fd,&c,1) == 1;n++); /* parcours du fichier */
	close(fd);
}
```



Se reporter au chapitre 7 du \"Kernighan et ritchie\"

