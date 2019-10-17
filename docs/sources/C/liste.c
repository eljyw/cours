/* cat liste.c */

#include <stdio.h>  /* Fonctions standards d'entrées sorties */
#include <stdlib.h> /* pour malloc */
#include <string.h> /* Fonctions de manipulations de chaines */

#define MAXSIZE 32

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
