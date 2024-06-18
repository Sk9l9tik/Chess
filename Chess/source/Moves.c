#include <stdio.h>

#include "../includes/Moves.h"

#include "../includes/CheckMate.h"

/*Forward-Back move functions*/
int MoveForward(Desk desk, Moves* moves, KingsPos* kingspos) {
	Figure t = { '_',2}, tl;
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1; //check_f = kingspos->Check_f;

	for (int i = 1; i <= moves->dist_y; i++) {
		t_cord_y--;

		//printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
		//printf("%c %d\n", desk[t_cord_y][t_cord_x].figure, desk[t_cord_y][t_cord_x].color);
		if ((t_cord_y + moves->dist_y == moves->cord_y && desk[t_cord_y][t_cord_x].color != desk[moves->cord_y][moves->cord_x].color) && t_cord_y >= 0) {
			if (desk[t_cord_y][t_cord_x].figure == 'K'&& desk[t_cord_y][t_cord_x].color != desk[moves->cord_y][moves->cord_x].color) 
				return 2;
			break;
		}
		else if (desk[t_cord_y][t_cord_x].figure != '_' || t_cord_y < 0) {
			return 1;
		}
	}


	tl = desk[t_cord_y][t_cord_x];
	desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
	desk[moves->cord_y][moves->cord_x] = t;
	

	if (desk[t_cord_y][t_cord_x].figure == 'K') {
		if (desk[t_cord_y][t_cord_x].color == 1) {
			kingspos->w_king_x = t_cord_x;
			kingspos->w_king_y = t_cord_y;
		}
		else {
			kingspos->b_king_x = t_cord_x;
			kingspos->b_king_y = t_cord_y;
		}
	}


	if ((kingspos->Check_f != 0 && Check(desk, moves, kingspos) != 0) || (Check(desk, moves, kingspos) != 0 && desk[t_cord_y][t_cord_x].color == kingspos->color)) { //&& Check(desk, moves, kingspos) != 2

		if (desk[t_cord_y][t_cord_x].figure == 'K') {
			if (desk[t_cord_y][t_cord_x].color == 1) {
				kingspos->w_king_x = moves->cord_x;
				kingspos->w_king_y = moves->cord_y;
			}
			else {
				kingspos->b_king_x = moves->cord_x;
				kingspos->b_king_y = moves->cord_y;
			}
		}

		desk[moves->cord_y][moves->cord_x] = desk[t_cord_y][t_cord_x];
		desk[t_cord_y][t_cord_x] = tl;
		return 2;
	}

	if (kingspos->cMate_f == 1) {
		if (desk[t_cord_y][t_cord_x].figure == 'K') {
			if (desk[t_cord_y][t_cord_x].color == 1) {
				kingspos->w_king_x = moves->cord_x;
				kingspos->w_king_y = moves->cord_y;
			}
			else {
				kingspos->b_king_x = moves->cord_x;
				kingspos->b_king_y = moves->cord_y;
			}
		}

		desk[moves->cord_y][moves->cord_x] = desk[t_cord_y][t_cord_x];
		desk[t_cord_y][t_cord_x] = tl;
		return 0;
	}

	return 0;
}

int MoveBack(Desk desk, Moves* moves, KingsPos* kingspos) {
	Figure t = { '_',2 }, tl;
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1, check_f = kingspos->Check_f;

	for (int i = 0; i > moves->dist_y; i--) {
		t_cord_y++;

		if (t_cord_y > 7) return -1;

		//printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
		//printf("%c %d\n", desk[t_cord_y][t_cord_x].figure, desk[t_cord_y][t_cord_x].color);
		if ((t_cord_y + moves->dist_y == moves->cord_y && desk[t_cord_y][t_cord_x].color != desk[moves->cord_y][moves->cord_x].color && desk[t_cord_y][t_cord_x].color != 2 && t_cord_y <= 7)) {
			//if (kingspos->cMate_f == 1) return 0;
			
			if (desk[t_cord_y][t_cord_x].figure == 'K' && desk[t_cord_y][t_cord_x].color != desk[moves->cord_y][moves->cord_x].color)
				return 2;
			break;
		}
		else if (desk[t_cord_y][t_cord_x].figure != '_' || t_cord_y > 7) {
			return 1;
		}
	}

	tl = desk[t_cord_y][t_cord_x];
	desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
	desk[moves->cord_y][moves->cord_x] = t;

	if (desk[t_cord_y][t_cord_x].figure == 'K') {
		if (desk[t_cord_y][t_cord_x].color == 1) {
			kingspos->w_king_x = t_cord_x;
			kingspos->w_king_y = t_cord_y;
		}
		else {
			kingspos->b_king_x = t_cord_x;
			kingspos->b_king_y = t_cord_y;
		}
	}


	if ((kingspos->Check_f != 0 && Check(desk, moves, kingspos) != 0) || (Check(desk, moves, kingspos) != 0 && desk[t_cord_y][t_cord_x].color == kingspos->color)) { //&& Check(desk, moves, kingspos) != 2

		if (desk[t_cord_y][t_cord_x].figure == 'K') {
			if (desk[t_cord_y][t_cord_x].color == 1) {
				kingspos->w_king_x = moves->cord_x;
				kingspos->w_king_y = moves->cord_y;
			}
			else {
				kingspos->b_king_x = moves->cord_x;
				kingspos->b_king_y = moves->cord_y;
			}
		}

		desk[moves->cord_y][moves->cord_x] = desk[t_cord_y][t_cord_x];
		desk[t_cord_y][t_cord_x] = tl;

		//printf("1\n");

		return 2;
	}

	if (kingspos->cMate_f == 1) {
		if (desk[t_cord_y][t_cord_x].figure == 'K') {
			if (desk[t_cord_y][t_cord_x].color == 1) {
				kingspos->w_king_x = moves->cord_x;
				kingspos->w_king_y = moves->cord_y;
			}
			else {
				kingspos->b_king_x = moves->cord_x;
				kingspos->b_king_y = moves->cord_y;
			}
		}

		desk[moves->cord_y][moves->cord_x] = desk[t_cord_y][t_cord_x];
		desk[t_cord_y][t_cord_x] = tl;
		return 0;
	}

	return 0;
}


/*Diagonal move functions*/
int MoveDiagonalForwardLeft(Desk desk, Moves* moves, KingsPos* kingspos) {
	Figure t = { '_',2}, tl;
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1, check_f = kingspos->Check_f;

	for (int i = 1; i <= moves->dist_y; i++) {
		t_cord_x--;
		t_cord_y--;

		/*
		printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
		printf("%c %d\n", desk[t_cord_y][t_cord_x].figure, desk[t_cord_y][t_cord_x].color);
		printf("X-dX:%d Y-dY:%d\n", t_cord_x - moves->dist_x, t_cord_y+moves->dist_y);
		*/
		if ((t_cord_y + moves->dist_y == moves->cord_y && t_cord_x - moves->dist_x == moves->cord_x && desk[t_cord_y][t_cord_x].color != desk[moves->cord_y][moves->cord_x].color && t_cord_x >= 0 & t_cord_y >= 0)) {
			if (desk[t_cord_y][t_cord_x].figure == 'K')
				return 2;
			break;
		}
		else if (desk[t_cord_y][t_cord_x].figure != '_' || t_cord_x < 0 || t_cord_y < 0) {
			return 1;
		}
	}

	tl = desk[t_cord_y][t_cord_x];
	desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
	desk[moves->cord_y][moves->cord_x] = t;

	if (desk[t_cord_y][t_cord_x].figure == 'K') {
		if (desk[t_cord_y][t_cord_x].color == 1) {
			kingspos->w_king_x = t_cord_x;
			kingspos->w_king_y = t_cord_y;
		}
		else {
			kingspos->b_king_x = t_cord_x;
			kingspos->b_king_y = t_cord_y;
		}
	}

	if ((kingspos->Check_f != 0 && Check(desk, moves, kingspos) != 0) || (Check(desk, moves, kingspos) != 0 && desk[t_cord_y][t_cord_x].color == kingspos->color))  { //&& Check(desk, moves, kingspos) != 2

		if (desk[t_cord_y][t_cord_x].figure == 'K') {
			if (desk[t_cord_y][t_cord_x].color == 1) {
				kingspos->w_king_x = moves->cord_x;
				kingspos->w_king_y = moves->cord_y;
			}
			else {
				kingspos->b_king_x = moves->cord_x;
				kingspos->b_king_y = moves->cord_y;
			}
		}

		desk[moves->cord_y][moves->cord_x] = desk[t_cord_y][t_cord_x];
		desk[t_cord_y][t_cord_x] = tl;

		return 2;
	}

	if (kingspos->cMate_f == 1) {
		if (desk[t_cord_y][t_cord_x].figure == 'K') {
			if (desk[t_cord_y][t_cord_x].color == 1) {
				kingspos->w_king_x = moves->cord_x;
				kingspos->w_king_y = moves->cord_y;
			}
			else {
				kingspos->b_king_x = moves->cord_x;
				kingspos->b_king_y = moves->cord_y;
			}
		}

		desk[moves->cord_y][moves->cord_x] = desk[t_cord_y][t_cord_x];
		desk[t_cord_y][t_cord_x] = tl;
		return 0;
	}

	return 0;
}

int MoveDiagonalForwardRight(Desk desk, Moves* moves, KingsPos* kingspos) {
	Figure t = { '_',2 }, tl;
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1, check_f = kingspos->Check_f;

	for (int i = 1; i <= moves->dist_y; i++) {
		t_cord_x++;
		t_cord_y--;
			
		//printf("X:%d Y:%d\n", moves->cord_x, moves->cord_y);
		//printf("%c %d\n", desk[moves->cord_y][moves->cord_x].figure, desk[moves->cord_y][moves->cord_x].color);
		if ((t_cord_y + moves->dist_y == moves->cord_y && t_cord_x - moves->dist_x == moves->cord_x && desk[t_cord_y][t_cord_x].color != desk[moves->cord_y][moves->cord_x].color && t_cord_x <= 7 && t_cord_y >= 0)) {
			if (desk[t_cord_y][t_cord_x].figure == 'K')
				return 2;
			break;
		}
		else if (desk[t_cord_y][t_cord_x].figure != '_' || t_cord_x > 7 || t_cord_y < 0) {
			return 1;
		}

	}

	tl = desk[t_cord_y][t_cord_x];
	desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
	desk[moves->cord_y][moves->cord_x] = t;

	if (desk[t_cord_y][t_cord_x].figure == 'K') {
		if (desk[t_cord_y][t_cord_x].color == 1) {
			kingspos->w_king_x = t_cord_x;
			kingspos->w_king_y = t_cord_y;
		}
		else {
			kingspos->b_king_x = t_cord_x;
			kingspos->b_king_y = t_cord_y;
		}
	}

	if ((kingspos->Check_f != 0 && Check(desk, moves, kingspos) != 0) || (Check(desk, moves, kingspos) != 0 && desk[t_cord_y][t_cord_x].color == kingspos->color))  { //&& Check(desk, moves, kingspos) != 2

		if (desk[t_cord_y][t_cord_x].figure == 'K') {
			if (desk[t_cord_y][t_cord_x].color == 1) {
				kingspos->w_king_x = moves->cord_x;
				kingspos->w_king_y = moves->cord_y;
			}
			else {
				kingspos->b_king_x = moves->cord_x;
				kingspos->b_king_y = moves->cord_y;
			}
		}

		desk[moves->cord_y][moves->cord_x] = desk[t_cord_y][t_cord_x];
		desk[t_cord_y][t_cord_x] = tl;

		return 2;
	}

	if (kingspos->cMate_f == 1) {
		if (desk[t_cord_y][t_cord_x].figure == 'K') {
			if (desk[t_cord_y][t_cord_x].color == 1) {
				kingspos->w_king_x = moves->cord_x;
				kingspos->w_king_y = moves->cord_y;
			}
			else {
				kingspos->b_king_x = moves->cord_x;
				kingspos->b_king_y = moves->cord_y;
			}
		}

		desk[moves->cord_y][moves->cord_x] = desk[t_cord_y][t_cord_x];
		desk[t_cord_y][t_cord_x] = tl;
		return 0;
	}

	return 0;
}

int MoveDiagonalBackLeft(Desk desk, Moves* moves, KingsPos* kingspos) {
	Figure t = { '_',2 }, tl;
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1, check_f = kingspos->Check_f;

	for (int i = 0; i > moves->dist_y; i--) {
		t_cord_x--;
		t_cord_y++;

		//printf("X:%d Y:%d\n", moves->cord_x, moves->cord_y);
		//printf("%c %d\n", desk[moves->cord_y][moves->cord_x].figure, desk[moves->cord_y][moves->cord_x].color);
		if ((t_cord_y + moves->dist_y == moves->cord_y && t_cord_x - moves->dist_x == moves->cord_x && desk[t_cord_y][t_cord_x].color != desk[moves->cord_y][moves->cord_x].color && t_cord_x >= 0 && t_cord_y <= 7)) {
			if (desk[t_cord_y][t_cord_x].figure == 'K')
				return 2;
			break;
		}
		else if (desk[t_cord_y][t_cord_x].figure != '_' || t_cord_x < 0 || t_cord_y > 7) {
			return 1;
		}
	}

	tl = desk[t_cord_y][t_cord_x];
	desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
	desk[moves->cord_y][moves->cord_x] = t;

	if (desk[t_cord_y][t_cord_x].figure == 'K') {
		if (desk[t_cord_y][t_cord_x].color == 1) {
			kingspos->w_king_x = t_cord_x;
			kingspos->w_king_y = t_cord_y;
		}
		else {
			kingspos->b_king_x = t_cord_x;
			kingspos->b_king_y = t_cord_y;
		}
	}

	if ((kingspos->Check_f != 0 && Check(desk, moves, kingspos) != 0) || (Check(desk, moves, kingspos) != 0 && desk[t_cord_y][t_cord_x].color == kingspos->color))  { //&& Check(desk, moves, kingspos) != 2

		if (desk[t_cord_y][t_cord_x].figure == 'K') {
			if (desk[t_cord_y][t_cord_x].color == 1) {
				kingspos->w_king_x = moves->cord_x;
				kingspos->w_king_y = moves->cord_y;
			}
			else {
				kingspos->b_king_x = moves->cord_x;
				kingspos->b_king_y = moves->cord_y;
			}
		}

		desk[moves->cord_y][moves->cord_x] = desk[t_cord_y][t_cord_x];
		desk[t_cord_y][t_cord_x] = tl;

		return 2;
	}

	if (kingspos->cMate_f == 1) {
		if (desk[t_cord_y][t_cord_x].figure == 'K') {
			if (desk[t_cord_y][t_cord_x].color == 1) {
				kingspos->w_king_x = moves->cord_x;
				kingspos->w_king_y = moves->cord_y;
			}
			else {
				kingspos->b_king_x = moves->cord_x;
				kingspos->b_king_y = moves->cord_y;
			}
		}

		desk[moves->cord_y][moves->cord_x] = desk[t_cord_y][t_cord_x];
		desk[t_cord_y][t_cord_x] = tl;
		return 0;
	}

	return 0;
}

int MoveDiagonalBackRight(Desk desk, Moves* moves, KingsPos* kingspos) {
	Figure t = { '_',2 }, tl;
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1, check_f = kingspos->Check_f;

	for (int i = 0; i > moves->dist_y; i--) {
		t_cord_x++;
		t_cord_y++;

		//printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
		//printf("%c %d\n", desk[t_cord_y][t_cord_x].figure, desk[t_cord_y][t_cord_x].color);
		if ((t_cord_y + moves->dist_y == moves->cord_y && t_cord_x - moves->dist_x == moves->cord_x && desk[t_cord_y][t_cord_x].color != desk[moves->cord_y][moves->cord_x].color && t_cord_x <= 7 && t_cord_y <= 7)) {
			if (desk[t_cord_y][t_cord_x].figure == 'K')
				return 2;
			break;
		}
		else if (desk[t_cord_y][t_cord_x].figure != '_' || t_cord_x > 7 || t_cord_y > 7) {
			return 1;
		}
		
	}

	tl = desk[t_cord_y][t_cord_x];
	desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
	desk[moves->cord_y][moves->cord_x] = t;

	if (desk[t_cord_y][t_cord_x].figure == 'K') {
		if (desk[t_cord_y][t_cord_x].color == 1) {
			kingspos->w_king_x = t_cord_x;
			kingspos->w_king_y = t_cord_y;
		}
		else {
			kingspos->b_king_x = t_cord_x;
			kingspos->b_king_y = t_cord_y;
		}
	}

	if ((kingspos->Check_f != 0 && Check(desk, moves, kingspos) != 0) || (Check(desk, moves, kingspos) != 0 && desk[t_cord_y][t_cord_x].color == kingspos->color))  { //&& Check(desk, moves, kingspos) != 2

		if (desk[t_cord_y][t_cord_x].figure == 'K') {
			if (desk[t_cord_y][t_cord_x].color == 1) {
				kingspos->w_king_x = moves->cord_x;
				kingspos->w_king_y = moves->cord_y;
			}
			else {
				kingspos->b_king_x = moves->cord_x;
				kingspos->b_king_y = moves->cord_y;
			}
		}

		desk[moves->cord_y][moves->cord_x] = desk[t_cord_y][t_cord_x];
		desk[t_cord_y][t_cord_x] = tl;

		return 2;
	}

	if (kingspos->cMate_f == 1) {
		if (desk[t_cord_y][t_cord_x].figure == 'K') {
			if (desk[t_cord_y][t_cord_x].color == 1) {
				kingspos->w_king_x = moves->cord_x;
				kingspos->w_king_y = moves->cord_y;
			}
			else {
				kingspos->b_king_x = moves->cord_x;
				kingspos->b_king_y = moves->cord_y;
			}
		}

		desk[moves->cord_y][moves->cord_x] = desk[t_cord_y][t_cord_x];
		desk[t_cord_y][t_cord_x] = tl;
		return 0;
	}

	return 0;
}

/*Left-Right move Functions*/
int MoveLeft(Desk desk, Moves* moves, KingsPos* kingspos) {
	Figure t = { '_',2 }, tl;
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1, check_f = kingspos->Check_f;

	for (int i = 0; i > moves->dist_x; i--) {
		t_cord_x--;

		//printf("X:%d Y:%d\n", moves->cord_x, moves->cord_y);
		//printf("%c %d\n", desk[moves->cord_y][moves->cord_x].figure, desk[moves->cord_y][moves->cord_x].color);
		if ((t_cord_x - moves->dist_x == moves->cord_x && desk[t_cord_y][t_cord_x].color != desk[moves->cord_y][moves->cord_x].color && t_cord_x >=0 )) {
			if (desk[t_cord_y][t_cord_x].figure == 'K')
				return 2;
			break;
		}
		else if (desk[t_cord_y][t_cord_x].figure != '_' || t_cord_x < 0) {
			return 1;
		}
	}

	tl = desk[t_cord_y][t_cord_x];
	desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
	desk[moves->cord_y][moves->cord_x] = t;

	if (desk[t_cord_y][t_cord_x].figure == 'K') {
		if (desk[t_cord_y][t_cord_x].color == 1) {
			kingspos->w_king_x = t_cord_x;
			kingspos->w_king_y = t_cord_y;
		}
		else {
			kingspos->b_king_x = t_cord_x;
			kingspos->b_king_y = t_cord_y;
		}
	}

	if ((kingspos->Check_f != 0 && Check(desk, moves, kingspos) != 0) || (Check(desk, moves, kingspos) != 0 && desk[t_cord_y][t_cord_x].color == kingspos->color))  { //&& Check(desk, moves, kingspos) != 2

		if (desk[t_cord_y][t_cord_x].figure == 'K') {
			if (desk[t_cord_y][t_cord_x].color == 1) {
				kingspos->w_king_x = moves->cord_x;
				kingspos->w_king_y = moves->cord_y;
			}
			else {
				kingspos->b_king_x = moves->cord_x;
				kingspos->b_king_y = moves->cord_y;
			}
		}

		desk[moves->cord_y][moves->cord_x] = desk[t_cord_y][t_cord_x];
		desk[t_cord_y][t_cord_x] = tl;

		return 2;
	}

	if (kingspos->cMate_f == 1) {
		if (desk[t_cord_y][t_cord_x].figure == 'K') {
			if (desk[t_cord_y][t_cord_x].color == 1) {
				kingspos->w_king_x = moves->cord_x;
				kingspos->w_king_y = moves->cord_y;
			}
			else {
				kingspos->b_king_x = moves->cord_x;
				kingspos->b_king_y = moves->cord_y;
			}
		}

		desk[moves->cord_y][moves->cord_x] = desk[t_cord_y][t_cord_x];
		desk[t_cord_y][t_cord_x] = tl;
		return 0;
	}

	return 0;
}

int MoveRight(Desk desk, Moves* moves, KingsPos* kingspos) {
	Figure t = { '_',2 }, tl;
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1, check_f = kingspos->Check_f;

	for (int i = 1; i <= moves->dist_x; i++) {
		t_cord_x++;

		//printf("X:%d Y:%d\n", moves->cord_x, moves->cord_y);
		//printf("%c %d\n", desk[moves->cord_y][moves->cord_x].figure, desk[moves->cord_y][moves->cord_x].color);
		if ((t_cord_x - moves->dist_x == moves->cord_x && desk[t_cord_y][t_cord_x].color != desk[moves->cord_y][moves->cord_x].color && t_cord_x <= 7)) {
			if (desk[t_cord_y][t_cord_x].figure == 'K')
				return 2;
			break;
		}
		else if (desk[t_cord_y][t_cord_x].figure != '_' || t_cord_x > 7) {
			return 1;
		}
	}

	tl = desk[t_cord_y][t_cord_x];
	desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
	desk[moves->cord_y][moves->cord_x] = t;

	if (desk[t_cord_y][t_cord_x].figure == 'K') {
		if (desk[t_cord_y][t_cord_x].color == 1) {
			kingspos->w_king_x = t_cord_x;
			kingspos->w_king_y = t_cord_y;
		}
		else {
			kingspos->b_king_x = t_cord_x;
			kingspos->b_king_y = t_cord_y;
		}
	}

	if ((kingspos->Check_f != 0 && Check(desk, moves, kingspos) != 0) || (Check(desk, moves, kingspos) != 0 && desk[t_cord_y][t_cord_x].color == kingspos->color))  { //&& Check(desk, moves, kingspos) != 2

		if (desk[t_cord_y][t_cord_x].figure == 'K') {
			if (desk[t_cord_y][t_cord_x].color == 1) {
				kingspos->w_king_x = moves->cord_x;
				kingspos->w_king_y = moves->cord_y;
			}
			else {
				kingspos->b_king_x = moves->cord_x;
				kingspos->b_king_y = moves->cord_y;
			}
		}

		desk[moves->cord_y][moves->cord_x] = desk[t_cord_y][t_cord_x];
		desk[t_cord_y][t_cord_x] = tl;

		return 2;
	}

	if (kingspos->cMate_f == 1) {
		if (desk[t_cord_y][t_cord_x].figure == 'K') {
			if (desk[t_cord_y][t_cord_x].color == 1) {
				kingspos->w_king_x = moves->cord_x;
				kingspos->w_king_y = moves->cord_y;
			}
			else {
				kingspos->b_king_x = moves->cord_x;
				kingspos->b_king_y = moves->cord_y;
			}
		}

		desk[moves->cord_y][moves->cord_x] = desk[t_cord_y][t_cord_x];
		desk[t_cord_y][t_cord_x] = tl;
		return 0;
	}

	return 0;
}

/*Horse move functions*/
int HorseMove(Desk desk, Moves* moves, KingsPos* kingspos) {
	Figure t = { '_',2 }, tl;
	int Flag = 1, check_f = kingspos->Check_f;
		int t_cord_x = moves->cord_x + moves->dist_x;
		int t_cord_y = moves->cord_y - moves->dist_y;

		//printf("X:%d Y:%d\n", t_cord_x, t_cord_y);

		tl = desk[t_cord_y][t_cord_x];
		desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
		desk[moves->cord_y][moves->cord_x] = t;

		if ((kingspos->Check_f != 0 && Check(desk, moves, kingspos) != 0) || (Check(desk, moves, kingspos) != 0 && desk[t_cord_y][t_cord_x].color == kingspos->color))  { //&& Check(desk, moves, kingspos) != 2
			desk[moves->cord_y][moves->cord_x] = desk[t_cord_y][t_cord_x];
			desk[t_cord_y][t_cord_x] = tl;
			return 2;
		}
		if (kingspos->cMate_f == 1) {
			desk[moves->cord_y][moves->cord_x] = desk[t_cord_y][t_cord_x];
			desk[t_cord_y][t_cord_x] = tl;
			return 0;
		}
	return 0;
}

char Taking_on_the_pass(Desk desk, Moves* moves, char quater) {
	if (quater == 1 && (desk[moves->cord_y - 1][moves->cord_x + 1].color == 2 && (moves - 1)->cord_y == 1 && desk[moves->cord_y][moves->cord_x + 1].figure == 'P' && desk[moves->cord_y][moves->cord_x + 1].color == 0)) {
		Figure n = { '_', 2 };
		desk[moves->cord_y][moves->cord_x + 1] = n;
		return 1;
	}
	else if (quater == 2 && (desk[moves->cord_y - 1][moves->cord_x - 1].color == 2 && (moves - 1)->cord_y == 1 && desk[moves->cord_y][moves->cord_x - 1].figure == 'P' && desk[moves->cord_y][moves->cord_x - 1].color == 0)) {
		Figure n = { '_', 2 };
		desk[moves->cord_y][moves->cord_x - 1] = n;
		return 1;
	}
	else if (quater == 3 && (desk[moves->cord_y + 1][moves->cord_x - 1].color == 2 && (moves - 1)->cord_y == 6 && desk[moves->cord_y][moves->cord_x - 1].figure == 'P' && desk[moves->cord_y][moves->cord_x - 1].color == 1)) {
		Figure n = { '_', 2 };
		desk[moves->cord_y][moves->cord_x - 1] = n;
		return 1;
	}
	else if (quater == 4 && (desk[moves->cord_y + 1][moves->cord_x + 1].color == 2 && (moves - 1)->cord_y == 6 && desk[moves->cord_y][moves->cord_x + 1].figure == 'P' && desk[moves->cord_y][moves->cord_x + 1].color == 1)) {
		Figure n = { '_', 2 };
		desk[moves->cord_y][moves->cord_x + 1] = n;
		return 1;
	}
	else
		return 0;
}