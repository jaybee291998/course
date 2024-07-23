#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (network_socket < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9001);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (connection_status == -1) {
        perror("Error making a connection to the remote socket");
        close(network_socket);
        exit(EXIT_FAILURE);
    }

    // Receive data from the server
    char server_response[256];
    int recv_status = recv(network_socket, &server_response, sizeof(server_response), 0);
    if (recv_status < 0) {
        perror("Error receiving data from the server");
        close(network_socket);
        exit(EXIT_FAILURE);
    }

    printf("The server sent the data: %s\n", server_response);

    // Close the socket
    close(network_socket);
    return 0;
}

