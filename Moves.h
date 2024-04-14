#pragma once
#include "Desk.h"


/*init moves functions*/

/*init main move function*/
void Move(Desk desk, char hod[7]);
/*init Forward-Back move functions*/
void MoveForward(Desk desk, int cord_x, int cord_y, int dist_y, char hod[7]);
void MoveBack(Desk desk, int cord_x, int cord_y, int dist_y, char hod[7]);
/*init Diagonal move functions*/
void MoveDiagonalForwardRight(Desk desk, int cord_x, int cord_y, int dist_x, int dist_y, char hod[7]);
void MoveDiagonalForwardLeft(Desk desk, int cord_x, int cord_y, int dist_x, int dist_y, char hod[7]);
void MoveDiagonalBackRight(Desk desk, int cord_x, int cord_y, int dist_x, int dist_y, char hod[7]);
void MoveDiagonalBackLeft(Desk desk, int cord_x, int cord_y, int dist_x, int dist_y, char hod[7]);
/*init Left-Right move Functions*/
void MoveRight(Desk desk, int cord_x, int cord_y, int dist_x, char hod[7]);
void MoveLeft(Desk desk, int cord_x, int cord_y, int dist_x, char hod[7]);
/*init Horse move functions*/
void HorseMoveForward(Desk desk, int cord_x, int cord_y, int dist_y, int dist_x, char hod[7]);
void HorseMoveBack(Desk desk, int cord_x, int cord_y, int dist_y, int dist_x, char hod[7]);
