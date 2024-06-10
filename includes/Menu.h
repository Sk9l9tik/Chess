#pragma once

#include "Desk.h"

void main_menu();
void game_menu(Moves** game, KingsPos* kingspos, int* size);
void* games_list(Moves* lastgame, int* count);
