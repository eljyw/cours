/*  min.c */

#include <stdio.h>
/* 
 * La fonction min renvoie le plus petit des deux entiers qui
 * lui sont passé en paramètres.
 */

int min(int a,int b)
{
	return( a < b ? a : b);
}


void main(void)
{
	printf("le minimum de 4 et 10 est : %d\n",min(10,4));
}
