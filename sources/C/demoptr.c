/* $cat demoptr.c */
#include <stdio.h>

void main(void)
{
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
