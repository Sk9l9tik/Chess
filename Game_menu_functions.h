#pragma once

#include "Desk.h"

void new_game(Moves* game);

void print_game(Moves* game, int turn, int* size);

void insert_turn(Moves* game, int* size);
void delete_turn(Moves* game, int* size);
void modify_turn(Moves* game);
