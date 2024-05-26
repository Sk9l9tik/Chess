#include "Moves.h"
#include "MovesCheck.h"

int MoveBackCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color){
	Moves tmp;

	int flag = 0;

	int _king_x;
	int _king_y;

	// white
	if (color == 1) {
		_king_x = kingspos->w_king_x;
		_king_y = kingspos->w_king_y;
	}
	// black
	else {
		_king_x = kingspos->b_king_x;
		_king_y = kingspos->b_king_y;
	}

	while (1) {
		_king_y++;

		tmp.cord_x = _king_x;
		tmp.cord_y = _king_y;
		tmp.dist_x = kingspos->b_king_x - _king_x;
		if (color == 1)
			tmp.dist_y = kingspos->w_king_y + _king_y;
		else
			tmp.dist_y = kingspos->b_king_y + _king_y;

		flag = Move(desk, &tmp, kingspos);

		if ((_king_y == 7 || desk[_king_y][_king_x].color != 2)) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
			break;
		}
		
		if (flag == 2) break;
	}
	
	return flag;
}

int MoveForwardCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color) {
	Moves tmp;

	int flag = 0;

	int _king_x;
	int _king_y;

	 // white
	if (color == 1) {
		_king_x = kingspos->w_king_x;
		_king_y = kingspos->w_king_y;
	}
	// black
	else {
		_king_x = kingspos->b_king_x;
		_king_y = kingspos->b_king_y;
	}

	while (1) {
		_king_y--;

		tmp.cord_x = _king_x;
		tmp.cord_y = _king_y;
		tmp.dist_x = kingspos->w_king_x - _king_x;
		if(color == 1)
			tmp.dist_y = (_king_y - kingspos->w_king_y);
		else
			tmp.dist_y = (_king_y - kingspos->b_king_y);

		flag = Move(desk, &tmp, kingspos);

		if ((_king_y == 0 || desk[_king_y][_king_x].color != 2)) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
			break;
		}

		if (flag == 2) break;
	}

	return flag;
}