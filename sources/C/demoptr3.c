/* $cat demoptr3.c */

#include <stdio.h>

char *p,c;
int i;

void main(void)
{
	p = "ABCDEFGHIJKLMNO";
    c = *(p+2); /* c contient le caractère 'C'. */
    i = *(((int *) p) + 1);

    printf("sizeof(int*) = %ld\n", sizeof(int*));
    printf("sizeof(int) = %ld\n", sizeof(int));
    printf("i = %x\n", i);
}
