#pragma once

#include <winsock2.h>

int Server();
int Client();
char* ServerIP(WSADATA wsa_Data);