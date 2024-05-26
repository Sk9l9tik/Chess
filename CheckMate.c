#include "CheckMate.h"
#include "MovesCheck.h"

int Check(Desk desk, Moves* moves, KingsPos* kingspos) {

	char color; // 0 - black 1 - white
	kingspos->Check_f = 0;
	int flag = 0;
	for (char color = 0; color != 2; color++) {
		//main pos
		flag = MoveForwardCheck(desk, moves, kingspos, color);
		if (flag == 2) kingspos->Check_f = 2;
		flag = MoveBackCheck(desk, moves, kingspos, color);
		if (flag == 2) kingspos->Check_f = 2;
		flag = MoveDiagonalForwardLeftCheck(desk, moves, kingspos, color);
		if (flag == 2) kingspos->Check_f = 2;
		flag = MoveDiagonalForwardRightCheck(desk, moves, kingspos, color);
		if (flag == 2) kingspos->Check_f = 2;
		flag = MoveDiagonalBackLeftCheck(desk, moves, kingspos, color);
		if (flag == 2) kingspos->Check_f = 2;
		flag = MoveDiagonalBackRightCheck(desk, moves, kingspos, color);
		if (flag == 2) kingspos->Check_f = 2;
		flag = MoveLeftCheck(desk, moves, kingspos, color);
		if (flag == 2) kingspos->Check_f = 2;
		flag = MoveRightCheck(desk, moves, kingspos, color);
		if (flag == 2) kingspos->Check_f = 2;
	}


	//....//
	//list of pos = ...

	/* 
	0) make it for 2 kings
	1) list of all moves
	2) for all pos check "Check" on all directions (8)
	3) remake "new_game" check right move
	*/

	return kingspos->Check_f;
}