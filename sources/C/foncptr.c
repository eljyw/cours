#include <stdio.h>
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
