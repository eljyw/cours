/* sans.c */
void main(void)
{
	int i,j,s;
	for(i=1;i <=100000;i++)
	{
		s = 0;
		for(j=0;j <1000000;j+=i)
			s+=j;
	}
}
