#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define SHOP_COUNT 5
#define CUSTOMER_COUNT 3

#define handle_error_en(en, msg) \
        do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

int shop[SHOP_COUNT];
int need_costomer[CUSTOMER_COUNT];
pthread_mutex_t mutx[SHOP_COUNT];
int flag = 1;

int main(){
    return 0;
}
