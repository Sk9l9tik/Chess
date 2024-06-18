#pragma once
#include "Desk.h"


/*init moves functions*/

/*init main move function*/
int Move(Desk desk, Moves* moves, KingsPos* kingspos);
/*init Forward-Back move functions*/
int MoveForward(Desk desk, Moves* moves, KingsPos* kingspos);
int MoveBack(Desk desk, Moves* moves, KingsPos* kingspos);
/*init Diagonal move functions*/
int MoveDiagonalForwardRight(Desk desk, Moves* moves, KingsPos* kingspos);
int MoveDiagonalForwardLeft(Desk desk, Moves* moves, KingsPos* kingspos);
int MoveDiagonalBackRight(Desk desk, Moves* moves, KingsPos* kingspos);
int MoveDiagonalBackLeft(Desk desk, Moves* moves, KingsPos* kingspos);
/*init Left-Right move functions*/
int MoveRight(Desk desk, Moves* moves, KingsPos* kingspos);
int MoveLeft(Desk desk, Moves* moves, KingsPos* kingspos);
/*init Horse move functions*/
int HorseMove(Desk desk, Moves* moves, KingsPos* kingspos);
/*init taking on the pass function*/
char Taking_on_the_pass(Desk desk, Moves* moves, char quater);
