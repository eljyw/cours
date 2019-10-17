/* $cat demoptr2.c */
#include <stdio.h>

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

	/* Affiche le contenu du premier octet de la variable 'i'.*/

}
