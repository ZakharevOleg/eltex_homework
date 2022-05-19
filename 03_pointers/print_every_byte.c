#include <stdio.h>

int main()
{
	int i;
	int a = 270533154;
	char*ptr;

	ptr = &a;

	for (i = 0; i < 4; i++)
	{
		printf ("%d byte of a = %d\n", (i+1), *ptr);
		ptr++;
	}
	return 0;
}
