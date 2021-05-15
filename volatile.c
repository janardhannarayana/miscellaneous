/**
 * volatile.c -- This program is to understand about the volatile key word
 *               programitically. We use threads to demostrate.
 *
 * Written on Saturday, 15 May 2021.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define USE_VOLATILE 0

#if (USE_VOLATILE == 1)
volatile int a = 0;
#else
int a = 0;
#endif

/*
 * thread2 change the value of a to 4000 and exits.
 */
void *thread2(void *arg)
{
    // sleep to make sure thread1 print some logs before changing the a value.
    usleep(1);
    a = 10000;
}


/*
 * thread1 continuosly prints the global variable a
 */
void *thread1(void *arg)
{
    printf("Thread 1\n");
    int i = 0;

    for (i = 0; i < 10000; i++)
	printf("%d\n",a++);
}

int main()
{

    pthread_t th1;
    pthread_t th2;

    // main thread creates a new thread thread1 and starts executing.
    // thread1 starts printing the a value continosly.
    pthread_create(&th1, NULL, thread1, NULL);

    // After thread1 executes for some time, context switch occurs and main thread
    // creates new thread which is thread2.
    // thread2 sets the value of a to 4000.
    pthread_create(&th2, NULL, thread2, NULL);

    /* Expected output: 
     * 1. thread1 starts incrementing a and print.
     * 2. thread switch occurs and thread2 sets a to 4000
     * 3. thread1 again starts printing from 4000
     */
    /*
     * When using optimization and without volatile:
     * thread1 print a continuosly without considering the a value from thread2.
     * Because thread takes the value of a from the cache instead of memory after thread
     * context switching.
     * But when we use volatile a will be retained from the ram instead of cpu cache.
     */

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

}
