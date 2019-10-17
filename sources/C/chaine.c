/* $cat chaine.c */
#include <stdio.h>
#include <string.h>

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
