#pragma once

#include "Desk.h"

void new_game(Moves** game, int* count);

void print_game(Moves* game, int turn, int* size);

void* insert_turn(Moves** game, int* size);
void* delete_turn(Moves** game, int* size, int flag);
void modify_turn(Moves** game, int* size);
