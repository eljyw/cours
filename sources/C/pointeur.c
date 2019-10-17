#include <stdio.h>

char *p,c;
int i;

void main(void)
{
	char *p = "ABCDEFGHIJKLMNO";
    c = *(p+2); /* c contient le caractère 'C'. */
    i = *(((int *) p) + 1);

    printf("sizeof(int*) = %ld\n", sizeof(int*));
    printf("sizeof(int) = %ld\n", sizeof(int));
    printf("i = %x\n", i);
}
