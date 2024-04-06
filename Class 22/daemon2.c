#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/* Double-fork daemon example */

int main() {
    pid_t childpid; /* variable to store the child's pid */
    int retval;     /* child process: user-provided return code */
    int status;     /* parent process: child's exit status */

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
                    /* GOOD: We are writing to a file instead of stdout */
                    FILE *file;
                    /* Write to a file */
                    file = fopen("daemon2.log","w");
                    fprintf(file, "CHILD: I am the second child process! (I'm a daemon)\n");
                    fprintf(file, "CHILD: Here's my PID: %d\n", getpid());
                    fprintf(file, "CHILD: My parent's PID is: %d\n", getppid());
                    fprintf(file, "CHILD: The value of my copy of childpid is: %d\n", childpid);
                    fprintf(file, "CHILD: Sleeping for 5 seconds...\n");
                    // File writes are buffered, so let's flush our buffer so that
                    // we can see the above contents before the file is closed
                    fflush(file);
                    /* sleep for 5 seconds */
                    sleep(5);
                    fprintf(file, "CHILD: Goodbye!\n");    
                    /* close the file */
                    fclose(file);
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
            //wait();
            printf("PARENT: First Child exited.\n");
            printf("PARENT: Goodbye!\n");             
            /* parent exits */       
            exit(0);       
        }
    }
    /* fork returns -1 on failure */
    else {
        /* display error message */
        perror("fork");
        exit(0); 
    }
}