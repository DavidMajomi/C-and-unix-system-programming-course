/* Start up a number of threads and see how the OS scheduler effects which
 threads run longer and which run shorter.  We use a sleep() call to make
 sure that all of the threads are in existence at the same time. */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#define NTHREADS 32

void *Hello(void *);

int main(int argc, char *argv[]) {
    pthread_t threads[NTHREADS];
    int rc; 
    int j;
    long t;
    for(t=0; t<NTHREADS; t++) {
        // threadID, thread attributes, function, function args
        rc = pthread_create(&threads[t], NULL, Hello, (void *)t);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            printf("Code %d= %s\n",rc,strerror(rc));
            exit(-1);
        }
    }
    printf("main(): Created %ld threads.\n", t);
    for(j=0; j < NTHREADS; j++)
    { pthread_join(threads[j], NULL); }
}

void *Hello(void *threadid) {
    int i;
    double result=0.0;

    sleep(3);
    for (i=0; i<10000; i++)
    { result = result + sin(i) * tan(i); }

    printf("%ld: Hello World!\n", threadid);
    pthread_exit(NULL);
}