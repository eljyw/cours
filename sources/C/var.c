/* $cat var.c */
#include <stdio.h>

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
