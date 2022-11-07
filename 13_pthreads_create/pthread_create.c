#include <stdio.h>
#include <pthread.h>

void *thread_output()
{
    printf ("This thread ID of this process is %ld\n", pthread_self());
    return 0;
}
int main(void)
{
    int i, i1;
    int *s;
    pthread_t thread[3];

    for (i = 0; i < 3; i++) {
        pthread_create(&thread[i], NULL, thread_output, NULL);
    }

    for (i1 = 0; i1 < 3; i1++) {
        pthread_join(thread[i1], (void **) &s);
    }

    return 0;
}
