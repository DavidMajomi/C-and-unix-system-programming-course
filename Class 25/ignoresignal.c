#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signalign(int signum);
void signalquit(int signum);

int main() {
    signal(SIGINT, signalign);

    while(1) {
        printf("My PID is %d\n", getpid());
        sleep(2);
    }
}

void signalign(int signum) {
    write(0," Ctrl-C Nothing!\n",18);
    signal(SIGINT, signalign);
    write(0," Pressed Ctrl-\\!!\n",17);
}

void signalquit(int signum) {
    sleep(2);
    exit(0);
}