#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main () {
    // Create a socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Can call connect
    int connection_status;
    connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    // Check for error with the connection
    if (connection_status == -1)
    { printf("There was an error making a connection to the remote socket!\n\n"); }

    // Receive data from the server
    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response), 0);

    // Print the data from the server
    printf("The server sent the data: %s\n",server_response);

    // Close the socket
    shutdown(network_socket,2);
    return 0;
}