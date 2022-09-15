#include <stdio.h>

int main(void)
{
    int a = 0;
    int i;

    for (i = 0; i < 1000000; i++) {
        a++;
    }
    printf("a = %d\n", a);
    return 0;
}
