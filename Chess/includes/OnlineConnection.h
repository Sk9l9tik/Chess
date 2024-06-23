#pragma once

#include <winsock2.h>
#include "../includes/Desk.h"

void OnlineGame(Moves** game, int* count);
char* ServerIP(WSADATA wsa_Data);