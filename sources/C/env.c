#include <stdio.h>

void main(int argc, char ** argv, char ** envp)
{
	int i;
	
    for(i=0;envp[i];i++)
        printf("%s\n",envp[i]);
	/* La condition est fausse quand envp[i] vaut NULL (c.à.d 0) */
}
