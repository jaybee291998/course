#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <unistd.h>

int main() {

	printf("Started hand crafted http server\n");
	// read file to be sent

		
	// http response
	char response_data[1024] = "<html><head><title></title></head><body><h1>Hand crafted http server!!!</h1></body></html>";
	
	char http_header[2048] = "HTTP/1.1 200 OK\r\n\n";
	strcat(http_header, response_data);
	// create the server socket
	int network_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (network_socket < 0) {
		perror("Error creating socket");
		exit(EXIT_FAILURE);
	}
	
	printf("socket initiated\n");

	// define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9005);
	server_address.sin_addr.s_addr = INADDR_ANY;

	// bind the socket to the specified IP and port
	int bind_result = bind(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	if (bind_result < 0) {
		perror("Error binding socket");
		close(network_socket);
		exit(EXIT_FAILURE);
	}

	printf("successfully bind to 0.0.0.0:9005\n");

	int listen_result = listen(network_socket, 5);
	if (listen_result < 0) {
		perror("Error listening on socket");
		close (network_socket);
		exit(EXIT_FAILURE);
	}
	
	printf("listening to 0.0.0.0 on port 9005\n");

	// accept a connection
	struct sockaddr_in client_addr;
	socklen_t client_addr_len = sizeof(client_addr);
	int client_socket;
	while(1) {
		client_socket = accept(network_socket, (struct sockaddr *) &client_addr, &client_addr_len);
		if (client_socket < 0) {
			perror("Error accepting connection");
			continue;
		}
		printf("accepted request from: %d\n", client_addr.sin_addr.s_addr);
		int send_result = send(client_socket, http_header, sizeof(http_header), 0);
		if(send_result < 0) {
			perror("Error sending message to client");
			close(client_socket);
			continue;
		}
		printf("successfully sent payload\n\n");
		close(client_socket);
	}
	close(network_socket);
	return 0;
}
