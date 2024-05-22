#pragma once
#include "Desk.h"


/*init moves functions*/

/*init main move function*/
int Move(Desk desk, Moves* moves);
/*init Forward-Back move functions*/
int MoveForward(Desk desk, Moves* moves);
void MoveBack(Desk desk, Moves* moves);
/*init Diagonal move functions*/
void MoveDiagonalForwardRight(Desk desk, Moves* moves);
void MoveDiagonalForwardLeft(Desk desk, Moves* moves);
void MoveDiagonalBackRight(Desk desk, Moves* moves);
void MoveDiagonalBackLeft(Desk desk, Moves* moves);
/*init Left-Right move Functions*/
void MoveRight(Desk desk, Moves* moves);
void MoveLeft(Desk desk, Moves* moves);
/*init Horse move functions*/
void HorseMoveForward(Desk desk, Moves* moves);
void HorseMoveBack(Desk desk, Moves* moves);
