#include "../includes/CheckMate.h"
#include "../includes/MovesCheck.h"

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
		flag = HorseMoveCheck(desk, moves, kingspos, color);
		if (flag == 2) kingspos->Check_f = 2;
		if (flag == 2) kingspos->color = color;
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

void Mate(Desk desk, Moves* moves, KingsPos* kingspos) {
	char white = 0, black = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			//if (i == 0 && j == 0 && kingspos->Check_f == 2) continue;
			kingspos->w_king_x + i;
			kingspos->w_king_y + j;

			kingspos->b_king_x + i;
			kingspos->b_king_y + j;

			black += (Check(desk, moves, kingspos, 0) != 0 ? 1 : 0);
			white += (Check(desk, moves, kingspos, 0) != 0 ? 1 : 0);

		}
	}

	printf("%d-%d\n", white, black);

	if (kingspos->color == 1 && white == 9) kingspos->Mate_f = 2;
	else if (kingspos->color == 0 && black == 9) kingspos->Mate_f = 1;
	else kingspos->Mate_f = 0;
}
