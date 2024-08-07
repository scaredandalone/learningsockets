#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main()
{
	int server_socket; // create socket
	int client_socket; // accept connection
	struct sockaddr_in server_addr; // struct required to use bind()
	char buffer[500] = "server is connected!";
	char recv_buffer[500];
	
	server_socket = socket(AF_INET, SOCK_STREAM, 0); // TCP socket creation
	
	server_addr.sin_family = AF_INET; // declare the type
	server_addr.sin_port = htons(9001); // listener port number
	server_addr.sin_addr.s_addr = inet_addr("ip"); // listener ip
	
	bind(server_socket, (struct server_addr*) &server_addr, sizeof(server_addr)); //bind server
	listen(server_socket, 5);
	
	client_socket = accept(server_socket, NULL, NULL); // accept incoming connections
	printf("client connected!\n");
	send(client_socket, buffer, sizeof(buffer), 0); // send data to client
	recv(client_socket, recv_buffer, sizeof(recv_buffer), 0); // recv data from client
	printf("client has sent : %s", recv_buffer); // print data from client
	close(server_socket); // close connection
	return 0;
} 
