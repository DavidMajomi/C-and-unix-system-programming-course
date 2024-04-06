#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char a;
    int childpid;
    printf("Files in the current directory:\n");
    system("ls -l");  // system function is made up of 3 other system calls:
                      // execl(), wait() and fork() (prototyed in <unistd>)

    printf("\nPress enter to continue...\n");
    a = getchar();

    childpid = fork();
    // Child Process
    if (childpid == 0) {
        printf("Files in the current directory:\n");
        execl("/bin/ls", "ls", "-l", 0);
    }
    else
    { wait(); }
 
    // Only the Parent process will ever get here now.
    printf("HI THERE!\n");
    exit(0);
}
