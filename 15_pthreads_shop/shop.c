#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define SHOP_COUNT 5
#define CUSTOMER_COUNT 3

#define handle_error(en, msg) \
        do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

int shop[SHOP_COUNT];
int need_customer[CUSTOMER_COUNT];
pthread_mutex_t mtx[SHOP_COUNT] = {
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_MUTEX_INITIALIZER
};
/* for finish loader */
int flag = 1;

void *customer_task(void *arg)
{
    int i = *((int *) arg);
    int rand_num;

    while(need_customer[i] != 0){
        rand_num = rand() % SHOP_COUNT + 1;
        pthread_mutex_lock(&mtx[i]);
        if (shop[rand_num] > need_customer[i]) {
            shop[rand_num] -= need_customer[i];
            need_customer[i] = 0;
        } else {
            need_customer[i] -= shop[rand_num];
            shop[rand_num] = 0;
        }
        pthread_mutex_unlock(&mtx[i]);
        printf("\n");
        printf(" %d Customer visited %d shop\n", i, rand_num);
        printf(" His need is %d\n", need_customer[i]);
        printf("\n");
        sleep(2);
    }
    return 0;
}

void *loader_task(void *arg)
{
    int i;
    while (flag) {
        for (i = 1; i <= SHOP_COUNT; i++) {
            pthread_mutex_lock(&mtx[i]);
            shop[i] += 500;
            pthread_mutex_unlock(&mtx[i]);
            printf("\n");
            printf(" Loader added 500 product to %d shop \n", i);
            printf(" Amount of product in %d shop is %d\n", i, shop[i]);
            printf("\n");
            sleep(1);
        }
    }

    return 0;
}

int main(){

    int i, k, s;
    pthread_t customer[CUSTOMER_COUNT];
    pthread_t loader;
    void *res;


    srand(time(NULL));
    
    /* init shops */
    for (i = 1; i <= SHOP_COUNT; i++){
        shop[i] = rand() % (1050 - 950 + 1) + 950;
    }

    /* init customers need */
    for (i = 1; i <= CUSTOMER_COUNT; i++){
        need_customer[i] = rand() % (10500 - 9500 + 1) + 9500;
    }

    for (i = 1; i <= CUSTOMER_COUNT; i++){
        s = pthread_create(&customer[i], NULL, customer_task, &i);
        if (s != 0){
            handle_error(s, "pthread_create");
        }
        sleep(1);
    }

    s = pthread_create(&loader, NULL, loader_task, NULL);
    if (s != 0){
        handle_error(s, "pthread_create");
    }

    for (k = 1; k <= CUSTOMER_COUNT; k++){
        s = pthread_join(customer[k], &res);
        if (k == 3){
        	flag = 0;
        }
        if (s != 0){
            handle_error(s, "pthread_join");
        }
    }
    
    s = pthread_join(loader, &res);
    if (s != 0){
        handle_error(s, "pthread_join");
    }


    exit(EXIT_SUCCESS);
}
