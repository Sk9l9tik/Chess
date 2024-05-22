#include "Moves.h"
#include "MovesCheck.h"

void MoveForwardCheck(Desk desk, Moves* moves, KingsPos* kingspos){
	Moves tmp;

	int b_king_x = kingspos->b_king_x;
	int b_king_y = kingspos->b_king_y;
	while (1) {
		b_king_y--;
		if ((b_king_y == 0 || desk[b_king_y][b_king_x].color != desk[kingspos->b_king_y][kingspos->b_king_x].color)) {
			//break;
			tmp.cord_x = b_king_x;
			tmp.cord_y = b_king_y;
			tmp.dist_x = kingspos->b_king_x - b_king_x;
			tmp.dist_y = kingspos->b_king_y - b_king_y;

			Move(desk, &tmp);
		}
	}
}