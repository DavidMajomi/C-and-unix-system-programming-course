#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main () {
    char server_message [256] = "You have reached the server!";

    // Create a server socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the ip and port
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    // Listen for data from the client
    listen(server_socket, 5);

    // Accept the client socket information
    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);

    send(client_socket, server_message, sizeof(server_message), 0);

    // Close the socket
    shutdown(server_socket,2);
    return 0;
}
