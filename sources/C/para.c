/* $cat para.c*/
#include <stdio.h>
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
