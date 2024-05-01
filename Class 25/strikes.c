#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler_1(int signum);
void handler_2(int signum);

int main() {
    signal(SIGINT, handler_1);

    while(1) {
        printf("Swing batter!\n");
        sleep(5);
    }
}
 
void handler_1(int signum) {
    printf("Strike 1!\n");
    sleep(1);
    signal(SIGINT, handler_2);
}

void handler_2(int signum) {
    printf("Strike 2!!\n");
    sleep(2);  
    signal(SIGINT, SIG_DFL);
}
