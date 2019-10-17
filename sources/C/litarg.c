/* cat litarg.c */
#include <stdio.h>
void main(int argc,char ** argv)
{
	int i;
	for(i=0;i<argc;i++)
		printf("Argument n° %d est %s\n",i,argv[i]);
}