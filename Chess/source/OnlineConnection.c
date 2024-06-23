#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib, "ws2_32.lib")

#include <winsock2.h>
#include <WS2tcpip.h>
#include <stdio.h>

#include "../includes/OnlineConnection.h"

int Server() {

	WSADATA wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);

	if (WSAStartup(DLLVersion, &wsaData)) {
		printf("Error init WSAStartup!!\n");
		return 1;
	}

	SOCKADDR_IN addr; //struct keep ethernet adders
	int sizeaddr = sizeof(addr);

	IN_ADDR ip_to_num;
	if (inet_pton(AF_INET, ServerIP(wsaData), &ip_to_num) <= 0) {
		printf("Error in IP translation to special numeric format");
		return 1;
	}

	addr.sin_addr = ip_to_num;
	addr.sin_port = htons(1234);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL); // create socket
	bind(sListen, (SOCKADDR*)&addr, sizeaddr); // socket, struct sockaddr, size struct sockaddr
	listen(sListen, SOMAXCONN); // socket, max count request



	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeaddr);

	//listen(newConnection, 100);

	if (!newConnection) {
		printf("Error connection!!\n");
		return 1;
	}
	printf("Success connection!!\n");

	char msg_in[256];
	char msg_out[256];

	while (newConnection) {
		printf(">");
		fflush(stdin);
		scanf("%s", msg_out);
		send(newConnection, msg_out, sizeof(msg_out), NULL);
		while (recv(newConnection, msg_in, sizeof(msg_in), NULL) > 0) {
			printf("client:%s\n", msg_in);
			printf(">");
			fflush(stdin);
			scanf("%s", msg_out);
			send(newConnection, msg_out, sizeof(msg_out), NULL);
		}
	}

	return 0;
}


int Client() {

	WSADATA wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);



	if (WSAStartup(DLLVersion, &wsaData)) {
		printf("Error init WSAStartup!!\n");
		return 1;
	}

	SOCKADDR_IN addr; //struct keep ethernet adders
	int sizeaddr = sizeof(addr);

	char* server_ip = malloc(sizeof(char) * 13);
	//server_ip = "192.168.1.59";
	printf("Input ip-address to connect:");
	scanf("%13[0-9.]", server_ip);



	IN_ADDR ip_to_num;
	if (inet_pton(AF_INET, server_ip, &ip_to_num) <= 0) {
		printf("Error in IP translation to special numeric format");
		return 1;
	}

	addr.sin_addr = ip_to_num;
	addr.sin_port = htons(1234);
	addr.sin_family = AF_INET;

	Sleep(5000);

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);

	if (connect(Connection, (SOCKADDR*)&addr, sizeaddr)) {
		printf("Error connection to server\n");
		return 1;
	}

	printf("Success!!\n");

	char msg_in[256];
	char msg_out[256];

	while (1) {
		recv(Connection, msg_in, sizeof(msg_in), NULL);
		printf("server: %s\n", msg_in);
		fflush(stdin);
		printf(">");
		scanf("%s", msg_out);
		send(Connection, msg_out, sizeof(msg_out), NULL);
	}


	free(server_ip);
	return 0;

}

char* ServerIP(WSADATA wsa_Data) {
	// Init WinSock
	//WSADATA wsa_Data;
	//int wsa_ReturnCode = WSAStartup(0x101, &wsa_Data);

	// Get the local hostname
	char szHostName[255];
	gethostname(szHostName, 255);

	struct hostent* host_entry;
	host_entry = gethostbyname(szHostName);

	char* szLocalIP;
	szLocalIP = inet_ntoa(*(struct in_addr*)*host_entry->h_addr_list);
	//printf("%s", szLocalIP);

	/*WSACleanup();*/
	return szLocalIP;
}