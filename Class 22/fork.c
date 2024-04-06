#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */ 
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <sys/wait.h>   /* Wait for Process Termination */
#include <stdlib.h>     /* General Utilities */
 
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
            printf("CHILD: I am the child process!\n");
            printf("CHILD: Here's my PID: %d\n", getpid());
            printf("CHILD: My parent's PID is: %d\n", getppid());
            printf("CHILD: The value of my copy of childpid is: %d\n", childpid);
            printf("CHILD: Sleeping for 5 seconds...\n");
            sleep(5); /* sleep for 5 seconds */
            printf("CHILD: Goodbye!\n");    
            exit(0); /* child exits */
        }
        /* fork() returns new pid to the parent process */
        else {
            printf("PARENT: I am the parent process!\n");
            printf("PARENT: Here's my PID: %d\n", getpid());
            printf("PARENT: The value of my copy of childpid is %d\n", childpid);
            printf("PARENT: I will now wait for my child to exit.\n");
            wait(&status); /* wait for child to exit, and store its status */
            printf("PARENT: Child's exit code is: %d\n", WEXITSTATUS(status));
            printf("PARENT: Goodbye!\n");             
            exit(0);  /* parent exits */       
        }
    }
    /* fork returns -1 on failure */
    else {
        perror("fork"); /* display error message */
        exit(0); 
    }
}