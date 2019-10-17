#include <stdio.h>
#include <string.h>

#define COMMENTAIRE() { \
    printf("Un #define trop long"); \
    printf(" être coupé par le caractère \\"); \
    printf("\n"); \
    }

#if 1
#define STR(FONC) str ## FONC
#define TOSTR(FONC) #FONC
#endif

#define carre(x) ((x)*(x))

#define fauxcarre(x) x*x

#define MAX 43

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
#if 1
    printf("%s\n", STR(cat)(chaine,TOSTR(cat)));
#endif
}
