#include <stdio.h>
#include <stdlib.h>

#include "Figures.h"
#include "Moves.h"

/*functions figures*/
int Pawn(Desk desk, Moves* moves) {

	if (((abs(moves->dist_y) == 2 && moves->cord_y == 1) || (abs(moves->dist_y) == 2 && (moves->cord_y == 6)) || (abs(moves->dist_y) == 1 && moves->dist_x == 0) || (abs(moves->dist_y) == 1 && abs(moves->dist_x) == 1))) {
		if (abs(moves->dist_x) == moves->dist_y && moves->dist_x < 0) {
			MoveDiagonalForwardLeft(desk, moves);
		}
		else if (abs(moves->dist_x) == moves->dist_y && moves->dist_x > 0) {
			MoveDiagonalForwardRight(desk, moves);
		}
		else if (moves->dist_x == abs(moves->dist_y) && moves->dist_y < 0) {
			MoveDiagonalBackRight(desk, moves);
		}
		else if (moves->dist_x == moves->dist_y && moves->dist_x < 0 && moves->dist_y < 0) {
			MoveDiagonalBackLeft(desk, moves);
		}
		else if (moves->dist_y > 0 && desk[moves->cord_y - 1][moves->cord_x].figure == '_') {
			//printf("%c %d\n\n", desk[moves->cord_y-1][moves->cord_x].figure, desk[moves->cord_y-1][moves->cord_x].color);
			MoveForward(desk, moves);
		}
		else if (moves->dist_y < 0 && desk[moves->cord_y + 1][moves->cord_x].figure == '_') {
			MoveBack(desk, moves);
		}
		else {
			//printf("Illegal turn: %s !!!\n\n", moves->hod);
			return 1;
		}
	}
	else {
		//printf("Illegal turn: %s !!!\n\n", moves->hod);
		return 1;
	}
	return 0;
}

int Knight(Desk desk, Moves* moves) {
	if (moves->dist_x == 0) {
		if (moves->dist_y > 0)
			MoveForward(desk, moves);
		else
			MoveBack(desk, moves);
	}
	else if (moves->dist_y == 0) {
		if (moves->dist_x > 0)
			MoveRight(desk, moves);
		else
			MoveLeft(desk, moves);
	}
	else {
		//printf("Illegal turn: %s !!!\n\n", moves->hod);
		return 1;
	}
	return 0;
}

int Rock(Desk desk, Moves* moves) {
	if (moves->dist_x == 0) {
		if (moves->dist_y > 0)
			MoveForward(desk, moves);
		else
			MoveBack(desk, moves);
	}
	else if (moves->dist_y == 0) {
		if (moves->dist_x > 0)
			MoveRight(desk, moves);
		else
			MoveLeft(desk, moves);
	}
	else {
		//printf("Illegal turn: %s !!!\n\n", moves->hod);
		return 1;
	}
	return 0;
}

int Bishop(Desk desk, Moves* moves) {
	if (abs(moves->dist_x) == moves->dist_y && moves->dist_x < 0) {
		MoveDiagonalForwardLeft(desk, moves);
	}
	else if (moves->dist_x == moves->dist_y && moves->dist_x > 0 && moves->dist_y > 0) {
		MoveDiagonalForwardRight(desk, moves);
	}
	else if (moves->dist_x == abs(moves->dist_y) && moves->dist_y < 0) {
		MoveDiagonalBackRight(desk, moves);
	}
	else if (moves->dist_x == moves->dist_y && moves->dist_x < 0 && moves->dist_y < 0) {
		MoveDiagonalBackLeft(desk, moves);
	}
	else {
		//printf("Illegal turn: %s !!!\n\n", moves->hod);
		return 1;
	}
	return 0;
}

int Queen(Desk desk, Moves* moves) {
	if (moves->dist_x == 0) {
		if (moves->dist_y > 0)
			MoveForward(desk, moves);
		else
			MoveBack(desk, moves);
	}
	else if (moves->dist_y == 0) {
		if (moves->dist_x > 0)
			MoveRight(desk, moves);
		else
			MoveLeft(desk, moves);
	}
	else if (abs(moves->dist_x) == moves->dist_y && moves->dist_x < 0) {
		MoveDiagonalForwardLeft(desk, moves);
	}
	else if (moves->dist_x == moves->dist_y && moves->dist_x > 0 && moves->dist_y > 0) {
		MoveDiagonalForwardRight(desk, moves);
	}
	else if (moves->dist_x == abs(moves->dist_y) && moves->dist_y < 0) {
		MoveDiagonalBackRight(desk, moves);
	}
	else if (moves->dist_x == moves->dist_y && moves->dist_x < 0 && moves->dist_y < 0) {
		MoveDiagonalBackLeft(desk, moves);
	}
	else {
		//printf("Illegal turn: %s !!!\n\n", moves->hod);
		return 1;
	}
	return 0;
}

int King(Desk desk, Moves* moves) {
	if (abs(moves->dist_x) > 1 && abs(moves->dist_y) > 1) {
		//printf("Illegal turn: %s !!!\n\n", moves->hod);
		return 1;
	}
	else {
		if (moves->dist_x == 0) {
			if (moves->dist_y > 0)
				MoveForward(desk, moves);
			else
				MoveBack(desk, moves);
		}
		else if (moves->dist_y == 0) {
			if (moves->dist_x > 0)
				MoveRight(desk, moves);
			else
				MoveLeft(desk, moves);
		}
		else if (abs(moves->dist_x) == moves->dist_y && moves->dist_x < 0) {
			MoveDiagonalForwardLeft(desk, moves);
		}
		else if (moves->dist_x == moves->dist_y && moves->dist_x > 0 && moves->dist_y > 0) {
			MoveDiagonalForwardRight(desk, moves);
		}
		else if (moves->dist_x == abs(moves->dist_y) && moves->dist_y < 0) {
			MoveDiagonalBackRight(desk, moves);
		}
		else if (moves->dist_x == moves->dist_y && moves->dist_x < 0 && moves->dist_y < 0) {
			MoveDiagonalBackLeft(desk, moves);
		}
		else {
			//printf("Illegal turn: %s !!!\n\n", moves->hod);
			return 1;
		}
	}
	return 0;
}
