#include <stdio.h>
#define N 5
#define M 5

int main()
{
    int a[N][M], i, k;
    for (i = 0; i < N; i++)
    {
        for (k = 0; k < M; k++)
        {
            if((i + k) >= (N - 1)) {
                a[i][k] = 1;
            } else {
                a[i][k] = 0;
            }
            printf("%d  ", a[i][k]);
        }
        printf("\n");
    }
    
    return 0;
}

