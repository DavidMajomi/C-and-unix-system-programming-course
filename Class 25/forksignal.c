#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
void sighup(); 
void sigint(); 
void sigquit(); 

void main() { 
    int pid; 

    if ((pid = fork()) < 0) {
        perror("fork"); 
        exit(1); 
    } 
    if (pid == 0) {
        // Child
        signal(SIGHUP, sighup); 
        signal(SIGINT, sigint); 
        signal(SIGQUIT, sigquit); 

        // loop for ever
        for (;;)
            ;
    }
    else {
        // Parent
        printf("\nPARENT: sending SIGHUP\n\n"); 
        kill(pid, SIGHUP); 
        sleep(3);
        printf("\nPARENT: sending SIGINT\n\n"); 
        kill(pid, SIGINT); 
        sleep(3);
        printf("\nPARENT: sending SIGQUIT\n\n"); 
        kill(pid, SIGQUIT); 
        sleep(3); 
        printf("\n");
    }
}

void sighup() { 
    signal(SIGHUP, sighup);
    write(STDOUT_FILENO,"CHILD: I have received a SIGHUP\n",32); 
}

void sigint() { 
    signal(SIGINT, sigint);
    write(STDOUT_FILENO,"CHILD: I have received a SIGINT\n",32); 
}

void sigquit()  {
    write(STDOUT_FILENO,"My Parent has killed me!!!\n",26); 
    exit(0); 
}