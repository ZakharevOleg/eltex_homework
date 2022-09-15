#include <stdio.h>
#include <pthread.h>

int a = 0;

void *thread_start(void *args)
{
    int k;

    for (k = 0; k < 200000; k++) {
        a++;
    }
    return 0;
}

int main(void)
{
    int i, i1;
    int *s;
    pthread_t thread[5];

    for (i = 0; i < 5; i++) {
        pthread_create(&thread[i], NULL, thread_start, NULL);
    }

    for (i1 = 0; i1 < 5; i1++) {
        pthread_join(thread[i1], (void **) &s);
    }

    printf("a = %d\n", a);
    return 0;
}
