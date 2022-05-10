#include <stdio.h>

int main()
{
        int a = 0xDDCCAABB;

	a = (a & 0xFFBBFFFF);
        printf ("%x\n", a);
        return 0;
}

