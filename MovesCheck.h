#pragma once

#include "Desk.h"

int MoveForwardCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color);
int MoveBackCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color);
int MoveDiagonalForwardLeftCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color);
int MoveDiagonalForwardRightCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color);
int MoveDiagonalBackLeftCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color);
int MoveDiagonalBackRightCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color);
int MoveLeftCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color);
int MoveRightCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color);