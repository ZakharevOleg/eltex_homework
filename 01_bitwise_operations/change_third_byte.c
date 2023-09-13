#include <stdio.h>

int main()
{
        int a = 0xDDCCAABB;
	printf ("%x\n", a);
	a = (a & 0xFFBBFFFF);
        printf ("%x\n", a);
        return 0;
}

