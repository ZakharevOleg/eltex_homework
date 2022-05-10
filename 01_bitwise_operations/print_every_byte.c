#include <stdio.h>

int main()
{
	int i;
	int a = 0xDDCCAABB;
	unsigned char c;
	
	for (i = 0; i < 4; i++)
	{
		c = ((a>>(i*8)) & 0xFF);
		printf ("%d byte of a = %x\n", (i+1), c);
	}
	return 0;
}

