#include <stdio.h>
#define N 5

int main()
{
        int a[N] = {1, 2, 3, 4, 5};
	int i;

	for (i = 0; i < N; i++)
        {
                printf("%d  ", a[i]);
        }
	printf("\n");


	for (i = 0; i < N; i++)
	{
	a[i] = N - i;
	}

	for (i = 0; i < N; i++)
        {
                printf("%d  ", a[i]);
        }
	printf("\n");

        return 0;
}
