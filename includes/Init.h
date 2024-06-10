#pragma once
#include "Desk.h"

/*init base functions*/
void init(Desk desk);
int printDesk(Desk desk);
void initMoves(Moves* moves, int color_turn);
void initKingsPos(KingsPos* kingspos);