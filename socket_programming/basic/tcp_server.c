#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#include <unistd.h>

int main() {
	
	char server_message[256] = "You have reached the server";

	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9001);
	server_address.sin_addr.s_addr = INADDR_ANY;

	bind(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

	listen(network_socket, 5);
	
	struct sockaddr my_client_addr;
	//struct socklen_t client_addr_len; 

	int client_socket;
	client_socket = accept(network_socket, NULL, NULL);

	send(client_socket, server_message, sizeof(server_message), 0);

	close(network_socket);

	return 0;
}
