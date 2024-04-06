#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char a;
    printf("Files in the current directory:\n");
    system("ls -l");  // system function is made up of 3 other system calls:
                // execl(), wait() and fork() (prototyed in <unistd>)

    printf("\nPress enter to continue...\n");
    a = getchar();

    printf("Files in the current directory:\n");
    execl("/bin/ls", "ls", "-l", 0);

    // We'll never get here, because execl replaces our current process
    printf("HI THERE!\n");

    exit(0);
}