// Server
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORTNUM 2300

int main(int argc, char *argv[]) {
    char* msg = "Hello World !\n";

    // socket info about the machine connecting to us
    struct sockaddr_in dest;

    // socket info about our server
    struct sockaddr_in serv;

    // socket used to listen for incoming connections
    int mysocket;
    socklen_t socksize = sizeof(struct sockaddr_in);

    // zero the struct before filling the fields
    memset(&serv, 0, sizeof(serv));

    // set the type of connection to TCP/IP
    serv.sin_family = AF_INET;

    // set our address to any interface
    serv.sin_addr.s_addr = htonl(INADDR_ANY);

    // set the server port number
    serv.sin_port = htons(PORTNUM);

    mysocket = socket(AF_INET, SOCK_STREAM, 0);

    // bind serv information to mysocket
    bind(mysocket, (struct sockaddr *)&serv, sizeof(struct sockaddr));

    // start listening, allowing a queue of up to 1 pending connection
    listen(mysocket, 1);
    int consocket = accept(mysocket, (struct sockaddr *)&dest, &socksize);

    while(consocket) {
        printf("Incoming connection from %s - sending welcome\n", inet_ntoa(dest.sin_addr));
        send(consocket, msg, strlen(msg), 0); 
        close(consocket);
        consocket = accept(mysocket, (struct sockaddr *)&dest, &socksize);
    }

    close(mysocket);
    return EXIT_SUCCESS;
}