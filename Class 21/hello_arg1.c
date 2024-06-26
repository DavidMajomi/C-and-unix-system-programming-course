/* Same has hello.c, but now using pointers
for our arg value that we pass in. */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 8

char *messages[NUM_THREADS];
void *PrintHello(void *);

int main() {
    pthread_t threads[NUM_THREADS];
    int *taskids[NUM_THREADS];
    int rc, t, j;

    messages[0] = "English: Hello World!";
    messages[1] = "French: Bonjour, le monde!";
    messages[2] = "Spanish: Hola al mundo";
    messages[3] = "Klingon: Nuq neH!";
    messages[4] = "German: Guten Tag, Welt!"; 
    messages[5] = "Russian: Zdravstvytye, mir!";
    messages[6] = "Japan: Sekai e konnichiwa!";
    messages[7] = "Latin: Orbis, te saluto!";

    for(t=0; t<NUM_THREADS; t++) {
        taskids[t] = (int *)malloc(sizeof(int));
        *taskids[t] = t;
        printf("Creating thread %d\n", t);
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *)taskids[t]);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    for(j=0; j < NUM_THREADS; j++)
    { pthread_join(threads[j], NULL); }
}

void *PrintHello(void *threadid) {
    int *id_ptr, taskid;

    sleep(1);
    id_ptr = (int *) threadid;
    taskid = *id_ptr;
    printf("Thread %d: %s\n", taskid, messages[taskid]);
}