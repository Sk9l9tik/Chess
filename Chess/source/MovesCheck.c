#include "../includes/Moves.h"
#include "../includes/MovesCheck.h"

int MoveForwardCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color) {
	Moves tmp;

	int flag = 0;

	int king_x;
	int king_y;

	// white
	if (color == 1) {
		king_x = kingspos->w_king_x;
		king_y = kingspos->w_king_y;
	}
	// black
	else {
		king_x = kingspos->b_king_x;
		king_y = kingspos->b_king_y;
	}

	int i = 1;
	while (1) {
		king_y--;

		tmp.cord_x = king_x;
		tmp.cord_y = king_y;


		if (color == 1) {
			tmp.dist_x = king_x - kingspos->w_king_x;
			tmp.dist_y = king_y - kingspos->w_king_y;
		}
		else {
			tmp.dist_x = king_x - kingspos->b_king_x;
			tmp.dist_y = king_y - kingspos->b_king_y ;
		}


		if ((king_y <= 0 || desk[king_y][king_x].figure != '_')) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
			break;
		}
	}

	flag = Move(desk, &tmp, kingspos);

	return flag;
}

int MoveBackCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color){
	Moves tmp;

	int flag = 0;


	int king_x;
	int king_y;

	// white
	if (color == 1) {
		king_x = kingspos->w_king_x;
		king_y = kingspos->w_king_y;
	}
	// black
	else {
		king_x = kingspos->b_king_x;
		king_y = kingspos->b_king_y;
	}

	while (1) {
		king_y++;

		tmp.cord_x = king_x;
		tmp.cord_y = king_y;

		if (color == 1) {
			tmp.dist_x = king_x - kingspos->w_king_x;
			tmp.dist_y = king_y - kingspos->w_king_y;
		}
		else {
			tmp.dist_x = king_x - kingspos->b_king_x;
			tmp.dist_y = king_y - kingspos->b_king_y;
		}

		//if (color == 1) {
		//	tmp.dist_x = kingspos->w_king_x - king_x;
		//	tmp.dist_y = kingspos->w_king_y - king_y;
		//}
		//else {
		//	tmp.dist_x = kingspos->b_king_x - king_x;
		//	tmp.dist_y = kingspos->b_king_y - king_y;
		//}

		if ((king_y >= 7 || desk[king_y][king_x].figure != '_')) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
			break;
		}

	}
	flag = Move(desk, &tmp, kingspos);

	return flag;
}

int MoveDiagonalForwardLeftCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color) {
	Moves tmp;

	int flag = 0;

	int king_x;
	int king_y;

	// white
	if (color == 1) {
		king_x = kingspos->w_king_x;
		king_y = kingspos->w_king_y;
	}
	// black
	else {
		king_x = kingspos->b_king_x;
		king_y = kingspos->b_king_y;
	}

	while (1) {
		king_x--;
		king_y--;

		tmp.cord_x = king_x;
		tmp.cord_y = king_y;

		if (color == 1) {
			tmp.dist_x = kingspos->w_king_x - king_x;
			tmp.dist_y = king_y - kingspos->w_king_y;
		}
		else {
			tmp.dist_x = kingspos->b_king_x - king_x;
			tmp.dist_y = king_y - kingspos->b_king_y;
		}

		if ((king_y <= 0 || king_x <= 0 || desk[king_y][king_x].figure != '_')) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
			break;
		}
	}

	flag = Move(desk, &tmp, kingspos);

	return flag;
}

int MoveDiagonalForwardRightCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color) {
	Moves tmp;

	int flag = 0;

	int king_x;
	int king_y;

	// white
	if (color == 1) {
		king_x = kingspos->w_king_x;
		king_y = kingspos->w_king_y;
	}
	// black
	else {
		king_x = kingspos->b_king_x;
		king_y = kingspos->b_king_y;
	}

	while (1) {
		king_x++;
		king_y--;

		tmp.cord_x = king_x;
		tmp.cord_y = king_y;

		if (color == 1) {
			tmp.dist_x = kingspos->w_king_x - king_x;
			tmp.dist_y = king_y - kingspos->w_king_y;
		}
		else {
			tmp.dist_x = kingspos->b_king_x - king_x;
			tmp.dist_y = king_y - kingspos->b_king_y;
		}

		if ((king_y <= 0 || king_x >= 7 || desk[king_y][king_x].figure != '_')) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
			break;
		}
	}

	flag = Move(desk, &tmp, kingspos);

	return flag;
}

int MoveDiagonalBackLeftCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color) {
	Moves tmp;

	int flag = 0;

	int king_x;
	int king_y;

	// white
	if (color == 1) {
		king_x = kingspos->w_king_x;
		king_y = kingspos->w_king_y;
	}
	// black
	else {
		king_x = kingspos->b_king_x;
		king_y = kingspos->b_king_y;
	}

	while (1) {
		king_x--;
		king_y++;

		tmp.cord_x = king_x;
		tmp.cord_y = king_y;

		if (color == 1) {
			tmp.dist_x = kingspos->w_king_x - king_x;
			tmp.dist_y = king_y - kingspos->w_king_y;
		}
		else {
			tmp.dist_x = kingspos->b_king_x - king_x;
			tmp.dist_y = king_y - kingspos->b_king_y;
		}

		if ((king_y >= 7 || king_x <= 0 || desk[king_y][king_x].figure != '_')) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
			break;
		}
	}

	flag = Move(desk, &tmp, kingspos);

	return flag;
}

int MoveDiagonalBackRightCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color) {
	Moves tmp;

	int flag = 0;

	int king_x;
	int king_y;

	// white
	if (color == 1) {
		king_x = kingspos->w_king_x;
		king_y = kingspos->w_king_y;
	}
	// black
	else {
		king_x = kingspos->b_king_x;
		king_y = kingspos->b_king_y;
	}

	while (1) {
		king_x++;
		king_y++;

		tmp.cord_x = king_x;
		tmp.cord_y = king_y;

		if (color == 1) {
			tmp.dist_x = kingspos->w_king_x - king_x;
			tmp.dist_y = king_y - kingspos->w_king_y;
		}
		else {
			tmp.dist_x = kingspos->b_king_x - king_x;
			tmp.dist_y = king_y - kingspos->b_king_y;
		}


		if ((king_y >= 7 || king_x >= 7 || desk[king_y][king_x].figure != '_')) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
			break;
		}
	}

	flag = Move(desk, &tmp, kingspos);

	return flag;
}

int MoveLeftCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color) {
	Moves tmp;

	int flag = 0;

	int king_x;
	int king_y;

	// white
	if (color == 1) {
		king_x = kingspos->w_king_x;
		king_y = kingspos->w_king_y;
	}
	// black
	else {
		king_x = kingspos->b_king_x;
		king_y = kingspos->b_king_y;
	}

	int i = 1;
	while (1) {
		king_x--;

		tmp.cord_x = king_x;
		tmp.cord_y = king_y;


		if (color == 1) {
			tmp.dist_x = kingspos->w_king_x - king_x;
			tmp.dist_y = king_y - kingspos->w_king_y;
		}
		else {
			tmp.dist_x = kingspos->b_king_x - king_x;
			tmp.dist_y = king_y - kingspos->b_king_y;
		}


		if ((king_x <= 0 || desk[king_y][king_x].figure != '_')) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
			break;
		}
	}

	flag = Move(desk, &tmp, kingspos);

	return flag;
}

int MoveRightCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color) {
	Moves tmp;

	int flag = 0;

	int king_x;
	int king_y;

	// white
	if (color == 1) {
		king_x = kingspos->w_king_x;
		king_y = kingspos->w_king_y;
	}
	// black
	else {
		king_x = kingspos->b_king_x;
		king_y = kingspos->b_king_y;
	}

	int i = 1;
	while (1) {
		king_x++;

		tmp.cord_x = king_x;
		tmp.cord_y = king_y;


		if (color == 1) {
			tmp.dist_x = kingspos->w_king_x - king_x;
			tmp.dist_y = king_y - kingspos->w_king_y;
		}
		else {
			tmp.dist_x = kingspos->b_king_x - king_x;
			tmp.dist_y = king_y - kingspos->b_king_y;
		}


		if ((king_x >= 7 || desk[king_y][king_x].figure != '_')) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
			break;
		}
	}

	flag = Move(desk, &tmp, kingspos);

	return flag;
}

int HorseMoveCheck(Desk desk, Moves* moves, KingsPos* kingspos, char color) {
	Moves tmp;

	int flag = 0;

	int king_x;
	int king_y;

	// white
	if (color == 1) {
		king_x = kingspos->w_king_x;
		king_y = kingspos->w_king_y;
	}
	// black
	else {
		king_x = kingspos->b_king_x;
		king_y = kingspos->b_king_y;
	}
	

	for (int i = -1; i <= 1; i += 2) {
		for (int j = -2; j <= 2; j += 4) {
			tmp.dist_x = j;
			tmp.dist_y = i;

			if ((king_y + i >= 7 || king_x + j >= 7 || king_y + i <= 0 || king_x + j <= 0 || desk[king_y][king_x].figure != '_')) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
				flag = 1;
			}
			else if ((king_y + j >= 7 || king_x + i >= 7 || king_y + j <= 0 || king_x + i <= 0 || desk[king_y][king_x].figure != '_')) { //desk[kingspos->b_king_y][kingspos->b_king_x].color
				flag = 1;
			}

			//printf("%c\n", desk[king_y + tmp.dist_y][king_x + tmp.dist_x].figure);
			if (desk[king_y + tmp.dist_y][king_x + tmp.dist_x].figure == 'N' &&
				desk[king_y + tmp.dist_y][king_x + tmp.dist_x].color != desk[king_y][king_x].color)
				return 2;
			

			tmp.dist_x = i;
			tmp.dist_y = j;

			//printf("%c\n", desk[king_y + tmp.dist_y][king_x + tmp.dist_x].figure);
			if (desk[king_y + tmp.dist_y][king_x + tmp.dist_x].figure == 'N' &&
				desk[king_y + tmp.dist_y][king_x + tmp.dist_x].color != desk[king_y][king_x].color)
				return 2;
		}
	}
	return flag;
}