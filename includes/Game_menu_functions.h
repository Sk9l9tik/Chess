#pragma once

#include "Desk.h"

void new_game(Moves** game, int* count);

void print_game(Moves* game,KingsPos* kingspos, int turn, int* size);

void* insert_turn(Moves** game, int color_turn, int* size);
void* delete_turn(Moves** game, int* size, int flag);
void modify_turn(Moves** game, int color_turn, int* size);
