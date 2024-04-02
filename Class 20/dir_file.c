#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main () {
    /* "*" means pointer */
    /* Check out /usr/include/dirent.h */
    DIR *dp;
    /* Check out /usr/include/bits/dirent.h */
    struct dirent *ep;

    dp = opendir ("./");
    if (dp != NULL) {
        while (ep = readdir(dp)) {
            /* Think of the "->" as a "." for now, we use -> because it's a pointer */
            if (ep->d_type == DT_REG)
            { printf("file: %s\n", ep->d_name); }
            else if (ep->d_type == DT_LNK)
            { printf("link: %s\n", ep->d_name); }
            else if (ep->d_type == DT_DIR)
            { printf(" dir: %s\n", ep->d_name); }
            else
            { printf("   ?: %s\n", ep->d_name); }
        }
        closedir(dp);
    }
    else {
        /* Instead of printf (stdout) you can use perror (stderr) which
        will display the last error with whatever prefix you choose */
        perror ("Couldn't open the directory");
    }
    exit(0);
}