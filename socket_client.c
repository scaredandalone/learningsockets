#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdio.h>
#pragma comment(lib, "Ws2_32.lib")

int main()
{
    WSADATA wsastructure; // create wsa strucutre required for winsock
    SOCKET client_socket; // create socket structure
    int result;
    struct sockaddr_in client_addr; // create struct required for connect()
    char recvData[500];
    char sendData[500] = "client successfully connected!";

    result = WSAStartup(MAKEWORD(2, 2), &wsastructure); // initialise winsock1
    if (result != 0)
    {
        printf("[!] Winsock initalisation failed!\n"); // print and exit
        return 1;
    }

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(9001);
    client_addr.sin_addr.s_addr = inet_addr("ip");

    connect(client_socket, (SOCKADDR*) &client_addr, sizeof(client_addr)); // connect to target server
    recv(client_socket, recvData, sizeof(recvData), 0); // receive data from server
    printf("data from the server : %s\n", recvData); 
    send(client_socket, sendData, sizeof(sendData), 0); // send data to server
    closesocket(client_socket); // close socket and exit
    WSACleanup(); // cleanup
    return 0;
}
