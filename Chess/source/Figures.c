#include <stdio.h>
#include <stdlib.h>

#include "../includes/Figures.h"
#include "../includes/Moves.h"

/*functions figures*/
int Pawn(Desk desk, Moves* moves, KingsPos* kingspos) {
	Figure Qw = { 'Q', 1 }, Qb = {'Q', 0};
	int check_f = 0;
	//printf("%s\n", (moves - 1)->hod);
	if ((moves->dist_y == -2 && moves->cord_y == 1 && moves->dist_x == 0) || (moves->dist_y == 2 && moves->cord_y == 6 && moves->dist_x == 0) || (abs(moves->dist_y) == 1 && moves->dist_x == 0) || (abs(moves->dist_y) == 1 && abs(moves->dist_x) == 1)) {
		if (moves->dist_x == -1 && moves->dist_y == 1 && ((desk[moves->cord_y-1][moves->cord_x-1].color != 2 && desk[moves->cord_y - 1][moves->cord_x - 1].color != desk[moves->cord_y][moves->cord_x].color) || (Taking_on_the_pass(desk, moves, 2))) && desk[moves->cord_y][moves->cord_x].color == 1 /*&& moves->cord_x + moves->dist_x >= 0 && moves->cord_y + moves->dist_y >= 0 */) {
			check_f = MoveDiagonalForwardLeft(desk, moves, kingspos);
		}
		else if (moves->dist_x == 1 && moves->dist_y == 1 && ((desk[moves->cord_y - 1][moves->cord_x + 1].color != 2 && desk[moves->cord_y - 1][moves->cord_x + 1].color != desk[moves->cord_y][moves->cord_x].color) || (Taking_on_the_pass(desk, moves, 1))) && desk[moves->cord_y][moves->cord_x].color == 1 /*&& moves->cord_x + moves->dist_x <= 7 && moves->cord_y + moves->dist_y >= 0 */) {
			check_f = MoveDiagonalForwardRight(desk, moves, kingspos);
		}
		else if (moves->dist_x == -1 && moves->dist_y == -1 && ((desk[moves->cord_y + 1][moves->cord_x - 1].color != 2 && desk[moves->cord_y + 1][moves->cord_x - 1].color != desk[moves->cord_y][moves->cord_x].color) || (Taking_on_the_pass(desk, moves, 3))) && desk[moves->cord_y][moves->cord_x].color == 0 /*&& moves->cord_x + moves->dist_x >= 0 && moves->cord_y + moves->dist_y <= 7 */) {
			check_f = MoveDiagonalBackLeft(desk, moves, kingspos);
		}
		else if (moves->dist_x == 1 && moves->dist_y == -1 && ((desk[moves->cord_y + 1][moves->cord_x + 1].color != 2 && desk[moves->cord_y + 1][moves->cord_x + 1].color != desk[moves->cord_y][moves->cord_x].color) || (Taking_on_the_pass(desk, moves, 3))) && desk[moves->cord_y][moves->cord_x].color == 0 /*&& moves->cord_x + moves->dist_x <= 7 && moves->cord_y + moves->dist_y <= 7 */) {
			check_f = MoveDiagonalBackRight(desk, moves, kingspos);
		}
		else if (moves->dist_y > 0 && moves->dist_x == 0 && desk[moves->cord_y - moves->dist_y][moves->cord_x].figure == '_' && desk[moves->cord_y][moves->cord_x].color == 1) {
			//printf("%c %d\n\n", desk[moves->cord_y-1][moves->cord_x].figure, desk[moves->cord_y-1][moves->cord_x].color);
			check_f = MoveForward(desk, moves, kingspos);
		}
		else if (moves->dist_y < 0 && moves->dist_x == 0 && desk[moves->cord_y - moves->dist_y][moves->cord_x].figure == '_' && desk[moves->cord_y][moves->cord_x].color == 0) {
			check_f = MoveBack(desk, moves, kingspos);
		}
		else {
			return 1;
		}
	}
	else {
		return 1;
	}

	if (desk[0][moves->cord_x + moves->dist_x].figure == 'P' && desk[0][moves->cord_x + moves->dist_x].color == 1)
		desk[0][moves->cord_x + moves->dist_x] = Qw;
	else if (desk[7][moves->cord_x + moves->dist_x].figure == 'P' && desk[7][moves->cord_x + moves->dist_x].color == 0)
		desk[7][moves->cord_x + moves->dist_x] = Qb;

	return check_f;
}

int Knight(Desk desk, Moves* moves, KingsPos* kingspos) {
	int check_f = 0;

	if (((moves->dist_y == 2 && abs(moves->dist_x) == 1) || ((abs(moves->dist_x) == 2) && moves->dist_y == 1)) && moves->cord_x + moves->dist_x <= 7 && moves->cord_x + moves->dist_x >= 0 && moves->cord_y - moves->dist_y >= 0 )
		if (moves->dist_y == 2 && moves->dist_x == 1 && desk[moves->cord_y - 2][moves->cord_x + 1].color == desk[moves->cord_y][moves->cord_x].color) return 1;
		else if (moves->dist_y == 1 && moves->dist_x == 2 && desk[moves->cord_y - 1][moves->cord_x + 2].color == desk[moves->cord_y][moves->cord_x].color) return 1;
		else if (moves->dist_y == 2 && moves->dist_x == -1 && desk[moves->cord_y - 2][moves->cord_x - 1].color == desk[moves->cord_y][moves->cord_x].color) return 1;
		else if (moves->dist_y == 1 && moves->dist_x == -2 && desk[moves->cord_y - 1][moves->cord_x - 2].color == desk[moves->cord_y][moves->cord_x].color) return 1;
		else
			check_f = HorseMove(desk, moves, kingspos);

	else if (((moves->dist_y == -2 && abs(moves->dist_x) == 1) || ((abs(moves->dist_x) == 2) && moves->dist_y == -1)) && moves->cord_x + moves->dist_x <= 7 && moves->cord_x + moves->dist_x >= 0 && moves->cord_y + moves->dist_y <= 7)
		if (moves->dist_y == -2 && moves->dist_x == 1 && desk[moves->cord_y + 2][moves->cord_x + 1].color == desk[moves->cord_y][moves->cord_x].color) return 1;
		else if (moves->dist_y == -1 && moves->dist_x == 2 && desk[moves->cord_y + 1][moves->cord_x + 2].color == desk[moves->cord_y][moves->cord_x].color) return 1;
		else if (moves->dist_y == -2 && moves->dist_x == -1 && desk[moves->cord_y + 2][moves->cord_x - 1].color == desk[moves->cord_y][moves->cord_x].color) return 1;
		else if (moves->dist_y == -1 && moves->dist_x == -2 && desk[moves->cord_y + 1][moves->cord_x - 2].color == desk[moves->cord_y][moves->cord_x].color) return 1;
		else
			check_f = HorseMove(desk, moves, kingspos);
	else
		return 1;
	return check_f;
}

int Rock(Desk desk, Moves* moves, KingsPos* kingspos) {
	int check_f = 0;

	if (moves->dist_x == 0) {
		if (moves->dist_y > 0 && moves->cord_y - moves->dist_y >= 0) //if (t_cord_y < 0) return -1;
			check_f = MoveForward(desk, moves, kingspos);
		else if (moves->dist_y < 0 && moves->cord_y + moves->dist_y <= 7) //if (t_cord_y > 7) return -1;
			check_f = MoveBack(desk, moves, kingspos);
		else return 1;
	}
	else if (moves->dist_y == 0) {
		if (moves->dist_x > 0 && moves->cord_x + moves->dist_x <= 7) //if (t_cord_x > 7) return -1;
			check_f = MoveRight(desk, moves, kingspos);
		else if (moves->dist_x < 0 && moves->cord_x + moves->dist_x >= 0) //if (t_cord_x < 0) return -1;
			check_f = MoveLeft(desk, moves, kingspos);
		else return 1;
	}
	else {
		return 1;
	}

	if (desk[moves->cord_y + moves->dist_y][moves->cord_x + moves->dist_x].color == 1)
		if (desk[moves->cord_y][moves->cord_x].figure == '_' && moves->cord_x == 7)
			kingspos->wrr_count++;
		else if (desk[moves->cord_y][moves->cord_x].figure == '_' && moves->cord_x == 0)
			kingspos->wrl_count++;
	else 
		if (desk[moves->cord_y][moves->cord_x].figure == '_' && moves->cord_x == 7)
			kingspos->brr_count++;
		else if (desk[moves->cord_y][moves->cord_x].figure == '_' && moves->cord_x == 0)
			kingspos->brl_count++;

	return check_f;
}

int Bishop(Desk desk, Moves* moves, KingsPos* kingspos) {
	int check_f = 0;
	if (abs(moves->dist_x) == moves->dist_y && moves->dist_x < 0 && moves->cord_x + moves->dist_x >= 0 && moves->cord_y + moves->dist_y >= 0) { //if (t_cord_y < 0 || t_cord_x < 0) return -1; x-- y--
		check_f = MoveDiagonalForwardLeft(desk, moves, kingspos);
	}
	else if (moves->dist_x == moves->dist_y && moves->dist_x > 0 && moves->dist_y > 0 && moves->cord_x + moves->dist_x <= 7 && moves->cord_y + moves->dist_y >= 0) { // if (t_cord_y < 0 || t_cord_x > 7) return -1; x++ y--
		check_f = MoveDiagonalForwardRight(desk, moves, kingspos);
	}
	else if (moves->dist_x == moves->dist_y && moves->dist_x < 0 && moves->dist_y < 0 && moves->cord_x + moves->dist_x >= 0 && moves->cord_y + moves->dist_y <= 7) { // if (t_cord_y > 7 || t_cord_x < 0) return -1; x-- y++
		check_f = MoveDiagonalBackLeft(desk, moves, kingspos);
	}
	else if (moves->dist_x == abs(moves->dist_y) && moves->dist_y < 0 && moves->cord_x + moves->dist_x <= 7 && moves->cord_y + moves->dist_y <= 7) { // if (t_cord_y > 7 || t_cord_x > 7) return -1; x++ y++
		check_f = MoveDiagonalBackRight(desk, moves, kingspos);
	}
	else {
		//printf("Illegal turn: %s !!!\n\n", moves->hod);
		return 1;
	}
	return check_f;
}

int Queen(Desk desk, Moves* moves, KingsPos* kingspos) {
	int check_f = 0;
	if (moves->dist_x == 0) {
		if (moves->dist_y > 0 && moves->cord_y - moves->dist_y >= 0) //if (t_cord_y < 0) return -1;
			check_f = MoveForward(desk, moves, kingspos);
		else if (moves->dist_y < 0 && moves->cord_y + moves->dist_y <= 7) //if (t_cord_y > 7) return -1;
			check_f = MoveBack(desk, moves, kingspos);
		else 
			return 1;
	}
	else if (moves->dist_y == 0) {
		if (moves->dist_x > 0 && moves->cord_x + moves->dist_x <= 7) //if (t_cord_x > 7) return -1;
			check_f = MoveRight(desk, moves, kingspos);
		else if (moves->dist_x < 0 && moves->cord_x + moves->dist_x >= 0) //if (t_cord_x < 0) return -1;
			check_f = MoveLeft(desk, moves, kingspos);
		else
			return 1;
	}
	else if (abs(moves->dist_x) == moves->dist_y && moves->dist_x < 0 && moves->cord_x + moves->dist_x >= 0 && moves->cord_y + moves->dist_y >= 0) { //if (t_cord_y < 0 || t_cord_x < 0) return -1; x-- y--
		check_f = MoveDiagonalForwardLeft(desk, moves, kingspos);
	}
	else if (moves->dist_x == moves->dist_y && moves->dist_x > 0 && moves->dist_y > 0 && moves->cord_x + moves->dist_x <= 7 && moves->cord_y + moves->dist_y >= 0) { // if (t_cord_y < 0 || t_cord_x > 7) return -1; x++ y--
		check_f = MoveDiagonalForwardRight(desk, moves, kingspos);
	}
	else if (moves->dist_x == moves->dist_y && moves->dist_x < 0 && moves->dist_y < 0 && moves->cord_x + moves->dist_x >= 0 && moves->cord_y + moves->dist_y <= 7) { // if (t_cord_y > 7 || t_cord_x < 0) return -1; x-- y++
		check_f = MoveDiagonalBackLeft(desk, moves, kingspos);
	}
	else if (moves->dist_x == abs(moves->dist_y) && moves->dist_y < 0 && moves->cord_x + moves->dist_x <= 7 && moves->cord_y + moves->dist_y <= 7) { // if (t_cord_y > 7 || t_cord_x > 7) return -1; x++ y++
		check_f = MoveDiagonalBackRight(desk, moves, kingspos);
	}
	else {
		//printf("Illegal turn: %s !!!\n\n", moves->hod);
		return 1;
	}
	return check_f;
}

int King(Desk desk, Moves* moves, KingsPos* kingspos) {
	int check_f = 0;
	Figure t = { '_', 2 };
	if (moves->hod[0] == 'O' && kingspos->color_turn == 1 && kingspos->wk_count == 0 && ((kingspos->wrr_count == 0 && desk[7][7].figure == 'R') || (kingspos->wrl_count == 0 && desk[7][0].figure == 'R')) && desk[7][4].color == 1 && desk[7][4].figure == 'K') {
		if (moves->dist_x == 2 && desk[7][7].figure == 'R' && MoveRight(desk, moves, kingspos) == 0) {
			/*desk[moves->cord_y][moves->cord_x - 1] = desk[moves->cord_y][moves->cord_x + 1];
			desk[moves->cord_y][moves->cord_x + 1] = t;*/
			desk[7][5] = desk[7][7];
			desk[7][7] = t;
		}
		else if (moves->dist_x == -2 && desk[7][0].figure == 'R' && MoveLeft(desk, moves, kingspos) == 0) {
			desk[7][3] = desk[7][0];
			desk[7][0] = t;
		}
		else 
			return 1;
	}
	else if (moves->hod[0] == 'O' && kingspos->color_turn == 0 && kingspos->bk_count == 0 && ((kingspos->brr_count == 0 && desk[0][7].figure == 'R') || (kingspos->brl_count == 0 && desk[0][0].figure == 'R')) && desk[0][4].color == 0 && desk[7][4].figure == 'K') {
		if (moves->dist_x == 2 && desk[0][7].figure == 'R' && MoveRight(desk, moves, kingspos) == 0) {
			/*desk[moves->cord_y][moves->cord_x - 1] = desk[moves->cord_y][moves->cord_x + 1];
			desk[moves->cord_y][moves->cord_x + 1] = t;*/
			desk[0][5] = desk[0][7];
			desk[0][7] = t;
		}
		else if (moves->dist_x == -2 && desk[0][0].figure == 'R' && MoveLeft(desk, moves, kingspos) == 0) {
			desk[0][3] = desk[0][0];
			desk[0][0] = t;
		}
		else
			return 1;
	}

	else if (abs(moves->dist_x) > 1 || abs(moves->dist_y) > 1) {
		//printf("Illegal turn: %s !!!\n\n", moves->hod);
		return 1;
	}
	else {

		if (moves->dist_x == 0) {
			if (moves->dist_y > 0)
				check_f = MoveForward(desk, moves, kingspos);
			else if (moves->dist_y < 0)
				check_f = MoveBack(desk, moves, kingspos);
			else
				return 1;
		}
		else if (moves->dist_y == 0) {
			if (moves->dist_x > 0)
				check_f = MoveRight(desk, moves, kingspos);
			else if (moves->dist_x < 0)
				check_f = MoveLeft(desk, moves, kingspos);
			else
				return 1;

		}
		else if (abs(moves->dist_x) == moves->dist_y && moves->dist_x < 0) {
			check_f = MoveDiagonalForwardLeft(desk, moves, kingspos);
		}
		else if (moves->dist_x == moves->dist_y && moves->dist_x > 0 && moves->dist_y > 0) {
			check_f = MoveDiagonalForwardRight(desk, moves, kingspos);
		}
		else if (moves->dist_x == abs(moves->dist_y) && moves->dist_y < 0) {
			check_f = MoveDiagonalBackRight(desk, moves, kingspos);
		}
		else if (moves->dist_x == moves->dist_y && moves->dist_x < 0 && moves->dist_y < 0) {
			check_f = MoveDiagonalBackLeft(desk, moves, kingspos);
		}
		else {
			//printf("Illegal turn: %s !!!\n\n", moves->hod);
			return 1;
		}
		if (check_f == 2)
			return 2; // Check !!!
	}
	
	if (desk[moves->cord_y + moves->dist_y][moves->cord_x + moves->dist_x].color == 1) kingspos->wk_count++;
	else kingspos->bk_count++;

	return check_f;
}
