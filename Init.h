#pragma once
#include "Desk.h"

/*init base functions*/
void init(Desk desk);
void printDesk(Desk desk);
char* input(char hod[7]);
void initMoves(Moves* moves, char* hod);
void initListMoves(char** moveslist, Moves** moves_game);