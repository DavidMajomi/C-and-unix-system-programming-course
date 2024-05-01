#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
    while (1) {
        printf("My PID is %d\n", getpid());
        sleep(5);
    }
    return 0;
}
