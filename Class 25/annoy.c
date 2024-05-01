#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void myhandle(int);

int main () {
    int i;
    signal(SIGINT, myhandle);
    signal(SIGTERM, myhandle);
    signal(SIGKILL, myhandle);

    while (1) {
        printf("i = %d\n", i);
        i++;
        sleep(1);
    }
    return 0;
}

void myhandle(int mysignal) {
    write(STDOUT_FILENO,"I live forever!!\n",17); 
}