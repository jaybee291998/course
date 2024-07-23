#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    char server_message[256] = "You have reached the server";

    // Create the server socket
    int network_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (network_socket < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9001);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the specified IP and port
    if (bind(network_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");
        close(network_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(network_socket, 5) < 0) {
        perror("Error listening on socket");
        close(network_socket);
        exit(EXIT_FAILURE);
    }

    // Accept a connection
    struct sockaddr_in client_address;
    socklen_t client_addr_len = sizeof(client_address);
    int client_socket = accept(network_socket, (struct sockaddr *) &client_address, &client_addr_len);
    if (client_socket < 0) {
        perror("Error accepting connection");
        close(network_socket);
        exit(EXIT_FAILURE);
    }

    // Send a message to the client
    if (send(client_socket, server_message, sizeof(server_message), 0) < 0) {
        perror("Error sending message");
        close(client_socket);
        close(network_socket);
        exit(EXIT_FAILURE);
    }

    // Close the sockets
    close(client_socket);
    close(network_socket);

    return 0;
}

