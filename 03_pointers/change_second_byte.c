#include <stdio.h>

int main()
{
        int a = 270533154;
	char*ptr;

	ptr = &a;

	ptr = ptr + 1;
	*ptr = 32;
        printf ("%d\n", a);
        return 0;
}
