#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib, "ws2_32.lib")

#include <winsock2.h>
#include <WS2tcpip.h>
#include <stdio.h>
#include <conio.h>

#include "../includes/OnlineConnection.h"
#include "../includes/Desk.h"
#include "../includes/Init.h"
#include "../includes/Game_menu_functions.h"

void OnlineGame(Moves** game, int* count) {

	WSADATA wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);

	if (WSAStartup(DLLVersion, &wsaData)) {
		printf("Error init WSAStartup!!\n");
		return 1;
	}

	SOCKADDR_IN addr; //struct keep ethernet adders
	int sizeaddr = sizeof(addr);

	IN_ADDR ip_to_num;


	int k;
	char msg_in[7];
	char msg_out[7];
	

	Desk desk;
	init(desk);

	KingsPos kingspos;
	initKingsPos(&kingspos);


	do {
		system("cls");
		printf("Choice one and input option number\n"
			"\t1: Create game (server)\n"
			"\t2: Connect to game (client)\n"
			"\t0: Exit\n"
			">");

		fflush(stdin);
		if (scanf("%d", &k) != 1) k = -1;

		switch (k) {
		case 0:
			return;
		case 1:
			if (inet_pton(AF_INET, ServerIP(wsaData), &ip_to_num) <= 0) {
				printf("Error in IP translation to special numeric format");
				return;
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
				return;
			}
			printf("Success connection!!\n");

			system("cls");
			while (newConnection) {
				if (NewOnlineGame(desk, &kingspos, game, count, NULL)) {
					break;
				}

				send(newConnection, (*game)[*count - 1].hod, sizeof((*game)[*count - 1].hod), NULL);
				while (recv(newConnection, msg_in, sizeof(msg_in), NULL) > 0) {

					if (msg_in[0] == 'x' && msg_in[1] == 'x') break;
					if (msg_in[0] == 0) continue;

					if (NewOnlineGame(desk, &kingspos, game, count, msg_in)) {
						break;
					}

					if (NewOnlineGame(desk, &kingspos, game, count, NULL)) {
						break;
					}

					send(newConnection, (*game)[*count - 1].hod, sizeof((*game)[*count - 1].hod), NULL);
				}
				printf("Press eny key to continue\n");
				_getch();
				return;
			}
			break;
		case 2:

			fflush(stdin);
			printf("Input ip-address to connect:");
			char* server_ip = malloc(sizeof(char) * 13);
			//scanf("%13[0-9.]", server_ip);
			scanf("%s", server_ip);
			if (inet_pton(AF_INET, server_ip, &ip_to_num) <= 0) {
				printf("Error in IP translation to special numeric format");
				return 1;
			}

			addr.sin_addr = ip_to_num;
			addr.sin_port = htons(1234);
			addr.sin_family = AF_INET;


			SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);

			if (connect(Connection, (SOCKADDR*)&addr, sizeaddr)) {
				printf("Error connection to server\n");
				return 1;
			}

			printf("Success!!\n");

			system("cls");
			printDesk(desk);
			kingspos.color_turn = 1;
			printf("Current color turn: %s\n", kingspos.color_turn == 1 ? "WHITE" : "BLACK");
			printf("Please wait oponetn`s turn\n");
			while (1) {
				recv(Connection, msg_in, sizeof(msg_in), NULL);

				if (msg_in[0] == 0) continue;

				if (NewOnlineGame(desk, &kingspos, game, count, msg_in)) {
					send(Connection, "xx", sizeof("xx"), NULL);
					break;
				}
				
				if(NewOnlineGame(desk, &kingspos, game, count, NULL)) {
					send(Connection, "xx", sizeof("xx"), NULL);
					break;
				}

				send(Connection, (*game)[*count - 1].hod, sizeof((*game)[*count - 1].hod), NULL);
			}

			free(server_ip);
			printf("Press eny key to continue\n");
			_getch();
			return;
		}
	} while (k);

	return;
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