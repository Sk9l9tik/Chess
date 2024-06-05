#pragma once

#include "Desk.h"

int Check(Desk desk, Moves* moves, KingsPos* kingspos);
int Mate(Desk desk, KingsPos* kingspos, int color_turn);

