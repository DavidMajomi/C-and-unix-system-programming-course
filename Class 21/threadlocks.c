#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS     7

int shared_variable = 0;

// Mutex lock to protect the shared variable
pthread_mutex_t mutex_lock;

void* thread_function(void* arg);

int main() {
    // Initialize the mutex lock
    pthread_mutex_init(&mutex_lock, NULL);

    // Create and start 5 threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, thread_function, NULL);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex lock
    pthread_mutex_destroy(&mutex_lock);

    printf("Final value of the shared variable: %d\n", shared_variable);

    return 0;
}

void* thread_function(void* arg) {
    // Lock the mutex before accessing the shared variable
    pthread_mutex_lock(&mutex_lock);
    shared_variable+=2;
    printf("Thread %ld incremented the shared variable to %d\n", pthread_self(), shared_variable);

    // Unlock the mutex after accessing the shared variable
    pthread_mutex_unlock(&mutex_lock);

    // Exit the thread
    pthread_exit(NULL);
}
