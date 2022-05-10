#include <stdio.h>
#define N 5
#define M 5

int main()
{
	int a[N][M], i, k;
	int j = 1;
	for (i = 0; i < N; i++)
	{
		for (k = 0; k < M; k++)
		{
			a[i][k] = j;
			if(a[i][k] < 10) {
			printf("%d   ", a[i][k]);
			} else {
			printf("%d  ", a[i][k]);
			}
			j++;
		}
		printf("\n");
	}
	return 0;
}
