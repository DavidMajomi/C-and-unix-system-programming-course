#include <stdio.h>
#include <stdlib.h>

/* Double-fork daemon example */

int main() {
    pid_t childpid; /* variable to store the child's pid */
    int retval;     /* child process: user-provided return code */
    int status;     /* parent process: child's exit status */

    /* only 1 int variable is needed because
    each process would have its own instance
    of the variable here, 2 int variables are used for clarity */

    printf("PARENT: I'm starting up!\n");
    printf("PARENT: Calling fork...\n");
    /* now create new process */
    childpid = fork();

    /* fork succeeded */
    if (childpid >= 0) {
        /* fork() returns 0 to the child process */
        if (childpid == 0) {
            /* **** WE ARE IN FIRST CHILD **** */
            childpid = fork();
            /* fork succeeded */
            if (childpid >= 0) {
                /* fork() returns 0 to the child process */
                if (childpid == 0) {
                /* **** WE ARE IN SECOND CHILD **** */
                    printf("CHILD: I am the second child process! (I'm a daemon)\n");
                    /* sleep for 5 seconds */
                    sleep(5);
                    /* child exits */
                    exit(0);
                }
                // Notice, no else here, we want our FIRST CHILD to just end right away
            }
            /* fork returns -1 on failure */
            else {
                /* display error message */
                perror("fork");
                exit(0); 
            }
        }
        /* fork() returns new pid to the parent process */
        else {
            printf("PARENT: I am the parent process!\n");
            printf("PARENT: Here's my PID: %d\n", getpid());
            printf("PARENT: The value of my copy of childpid is %d\n", childpid);
            printf("PARENT: I will now wait for my child to exit.\n");
            /* wait for child to exit, and store its status */
            wait();
            printf("PARENT: First Child exited.\n");
            printf("PARENT: Goodbye!\n");             
            /* parent exits */       
            exit(0);       
        }
    }
    /* fork returns -1 on failure */
    else
    {
        /* display error message */
        perror("fork");
        exit(0); 
    }
}
