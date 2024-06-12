#include "../includes/Moves.h"

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
		if (kingspos->Check_f == 2) {
			kingspos->color = color;
			moves->hod[5] = '+';
			moves->hod[6] = '\0';
			break;
		}
	}
	return kingspos->Check_f;
}

int Mate(Desk desk, KingsPos* kingspos, int color_turn) { //!!!! delete Moves* moves
	char color; // 0 - black 1 - white
	kingspos->cMate_f = 0;
	int flag = 0, check_f = kingspos->Check_f, cmate_f = 0;


	Moves tmove;

	kingspos->cMate_f = 1;
	int i = 0;
	for (int x = 0; x < 8; x++) { // perebor vseh figur
		for (int y = 0; y < 8; y++) {

		if (color_turn != desk[y][x].color) continue;

		for (int dx = -8; dx <= 8; dx++) { // peremeshenie figur
			for (int dy = -8; dy <= 8; dy++) {
				//init move
				tmove.cord_x = x;
				tmove.cord_y = y;
				tmove.dist_x = dx;
				tmove.dist_y = dy;


				flag = Move(desk, &tmove, kingspos);

				//printf("%d-%d %d,%d: %d - %d\n", x, y, dx, dy, flag, i);
				i++;

				if (check_f == 0 && flag == 0) {
					kingspos->cMate_f = 0;
					return 0;
				}
				else if (check_f == 2 && flag == 0) {
					kingspos->cMate_f = 0;
					return 0;
				}
			}
		}
		}
	}
	
	//int x = 6, y = 0; // отладить короля, коня
	

	if (check_f == 0 && flag != 0) return 1; // pat
	else if (check_f == 2 && flag != 0) {	 //mate
		kingspos->Mate_color = color_turn;
		return 2;
	} 

	kingspos->cMate_f = 0;

	return 0;
}
