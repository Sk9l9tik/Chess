#include "../includes/Moves.h"
#include "../includes/MovesCheck.h"

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

	int i = 1;
	while (1) {
		_king_y--;

		tmp.cord_x = _king_x;
		tmp.cord_y = _king_y;


		if (color == 1) {
			tmp.dist_x = _king_x - kingspos->w_king_x;
			tmp.dist_y = _king_y - kingspos->w_king_y;
		}
		else {
			tmp.dist_x = _king_x - kingspos->b_king_x;
			tmp.dist_y = _king_y - kingspos->b_king_y ;
		}


		if ((_king_y <= 0 || desk[_king_y][_king_x].color != 2)) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
			break;
		}
	}

	flag = Move(desk, &tmp, kingspos);

	return flag;
}

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

		if (color == 1) {
			tmp.dist_x = _king_x - kingspos->w_king_x;
			tmp.dist_y = _king_y - kingspos->w_king_y;
		}
		else {
			tmp.dist_x = _king_x - kingspos->b_king_x;
			tmp.dist_y = _king_y - kingspos->b_king_y;
		}

		//if (color == 1) {
		//	tmp.dist_x = kingspos->w_king_x - _king_x;
		//	tmp.dist_y = kingspos->w_king_y - _king_y;
		//}
		//else {
		//	tmp.dist_x = kingspos->b_king_x - _king_x;
		//	tmp.dist_y = kingspos->b_king_y - _king_y;
		//}

		if ((_king_y >= 7 || desk[_king_y][_king_x].color != 2)) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
			break;
		}

	}
	flag = Move(desk, &tmp, kingspos);

	return flag;
}

int MoveDiagonalForwardLeftCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color) {
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
		_king_x--;
		_king_y--;

		tmp.cord_x = _king_x;
		tmp.cord_y = _king_y;

		if (color == 1) {
			tmp.dist_x = kingspos->w_king_x - _king_x;
			tmp.dist_y = _king_y - kingspos->w_king_y;
		}
		else {
			tmp.dist_x = kingspos->b_king_x - _king_x;
			tmp.dist_y = _king_y - kingspos->b_king_y;
		}

		if ((_king_y <= 0 || _king_x <= 0 || desk[_king_y][_king_x].color != 2)) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
			break;
		}
	}

	flag = Move(desk, &tmp, kingspos);

	return flag;
}

int MoveDiagonalForwardRightCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color) {
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
		_king_x++;
		_king_y--;

		tmp.cord_x = _king_x;
		tmp.cord_y = _king_y;

		if (color == 1) {
			tmp.dist_x = kingspos->w_king_x - _king_x;
			tmp.dist_y = _king_y - kingspos->w_king_y;
		}
		else {
			tmp.dist_x = kingspos->b_king_x - _king_x;
			tmp.dist_y = _king_y - kingspos->b_king_y;
		}

		if ((_king_y <= 0 || _king_x >= 7 || desk[_king_y][_king_x].color != 2)) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
			break;
		}
	}

	flag = Move(desk, &tmp, kingspos);

	return flag;
}

int MoveDiagonalBackLeftCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color) {
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
		_king_x--;
		_king_y++;

		tmp.cord_x = _king_x;
		tmp.cord_y = _king_y;

		if (color == 1) {
			tmp.dist_x = kingspos->w_king_x - _king_x;
			tmp.dist_y = _king_y - kingspos->w_king_y;
		}
		else {
			tmp.dist_x = kingspos->b_king_x - _king_x;
			tmp.dist_y = _king_y - kingspos->b_king_y;
		}

		if ((_king_y >= 7 || _king_x <= 0 || desk[_king_y][_king_x].color != 2)) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
			break;
		}
	}

	flag = Move(desk, &tmp, kingspos);

	return flag;
}

int MoveDiagonalBackRightCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color) {
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
		_king_x++;
		_king_y++;

		tmp.cord_x = _king_x;
		tmp.cord_y = _king_y;

		if (color == 1) {
			tmp.dist_x = kingspos->w_king_x - _king_x;
			tmp.dist_y = _king_y - kingspos->w_king_y;
		}
		else {
			tmp.dist_x = kingspos->b_king_x - _king_x;
			tmp.dist_y = _king_y - kingspos->b_king_y;
		}


		if ((_king_y >= 7 || _king_x >= 7 || desk[_king_y][_king_x].color != 2)) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
			break;
		}
	}

	flag = Move(desk, &tmp, kingspos);

	return flag;
}

int MoveLeftCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color) {
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

	int i = 1;
	while (1) {
		_king_x--;

		tmp.cord_x = _king_x;
		tmp.cord_y = _king_y;


		if (color == 1) {
			tmp.dist_x = kingspos->w_king_x - _king_x;
			tmp.dist_y = _king_y - kingspos->w_king_y;
		}
		else {
			tmp.dist_x = kingspos->b_king_x - _king_x;
			tmp.dist_y = _king_y - kingspos->b_king_y;
		}


		if ((_king_x <= 0 || desk[_king_y][_king_x].color != 2)) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
			break;
		}
	}

	flag = Move(desk, &tmp, kingspos);

	return flag;
}

int MoveRightCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color) {
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

	int i = 1;
	while (1) {
		_king_x++;

		tmp.cord_x = _king_x;
		tmp.cord_y = _king_y;


		if (color == 1) {
			tmp.dist_x = kingspos->w_king_x - _king_x;
			tmp.dist_y = _king_y - kingspos->w_king_y;
		}
		else {
			tmp.dist_x = kingspos->b_king_x - _king_x;
			tmp.dist_y = _king_y - kingspos->b_king_y;
		}


		if ((_king_x >= 7 || desk[_king_y][_king_x].color != 2)) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
			break;
		}
	}

	flag = Move(desk, &tmp, kingspos);

	return flag;
}