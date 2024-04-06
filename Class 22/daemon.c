#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    pid_t pid;

    /* Create a new process */
    pid = fork();

    /* If we got a negative value, the creation of a child process was unsuccessful */
    if (pid < 0)
    { exit(EXIT_FAILURE); }

    /* If we got a positive value, we are in the parent process */
    if (pid > 0)
    { exit(EXIT_SUCCESS); }

    /* If execution reaches this point, we are in the child process */
    if (setsid() < 0)
    { exit(EXIT_FAILURE); }

    /* Change the current working directory */
    if (chdir("/") < 0)
    { exit(EXIT_FAILURE); }

    /* Close all open file descriptors */
    int x;
    for (x = sysconf(_SC_OPEN_MAX); x>=0; x--)
    { close (x); }

    /* Count to 1000 */
    int counter;
    for (counter = 1; counter <= 1000; counter++) {
        // sleep(1);  // sleep for 1 second
        printf("%d\n", counter);
    }

    return 0;
}
