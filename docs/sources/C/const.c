#include <stdio.h>

size_t longueur_de_chaine(const char chaine [] )
{
    register size_t longueur;
    for(longueur = 0; chaine[longueur]; longueur++);
    // chaine[0] = 'A';
    return longueur;
}

void main(int argc, char ** argv)
{
    int i;
    for (i = 0; i < argc; i++){
	printf("argument %2d  - longueur=%3ld - %s\n", i, longueur_de_chaine(*(argv+i)), argv[i]);
	}
}

