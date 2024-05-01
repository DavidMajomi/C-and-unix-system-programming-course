#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void myhandle(int);

int main () {
    int i;
    signal(SIGTERM, myhandle);

    while (1) {
        printf("i = %d\n", i);
        i++;
        sleep(1);
    }
    return 0;
}

void myhandle(int mysignal) {
    printf("received %d signal\n", mysignal); 
}
