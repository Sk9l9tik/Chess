#include "CheckMate.h"
#include "MovesCheck.h"

int Check(Desk desk, Moves* moves, KingsPos* kingspos) {

	// white king
	int flag = kingspos->Check_f;
	//main pos
	flag = MoveForwardCheck(desk, moves, kingspos);
	if (flag == 2) kingspos->Check_f = 2;
	flag = MoveBackCheck(desk, moves, kingspos);
	if (flag == 2) kingspos->Check_f = 2;
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