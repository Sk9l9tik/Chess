#include "Moves.h"
#include "MovesCheck.h"

int MoveBackCheck(Desk desk, Moves* moves, KingsPos* kingspos){
	Moves tmp;

	int flag = 0;

	int b_king_x = kingspos->b_king_x;
	int b_king_y = kingspos->b_king_y;

	while (1) {
		b_king_y++;

		tmp.cord_x = b_king_x;
		tmp.cord_y = b_king_y;
		tmp.dist_x = kingspos->b_king_x - b_king_x;
		tmp.dist_y = kingspos->b_king_y + b_king_y;

		flag = Move(desk, &tmp, kingspos);

		if ((b_king_y == 7 || desk[b_king_y][b_king_x].color != 2)) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
			break;
		}
		
		if (flag == 2) break;
	}
	
	return flag;
}