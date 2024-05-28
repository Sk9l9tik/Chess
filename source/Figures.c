#include <stdio.h>
#include <stdlib.h>

#include "../includes/Figures.h"
#include "../includes/Moves.h"

/*functions figures*/
int Pawn(Desk desk, Moves* moves, KingsPos* kingspos) {
	int check_f = 0;
	if (((abs(moves->dist_y) == 2 && moves->cord_y == 1) || (abs(moves->dist_y) == 2 && (moves->cord_y == 6)) || (abs(moves->dist_y) == 1 && moves->dist_x == 0) || (abs(moves->dist_y) == 1 && abs(moves->dist_x) == 1))) {
		if (abs(moves->dist_x) == moves->dist_y && moves->dist_x < 0) {
			check_f = MoveDiagonalForwardLeft(desk, moves, kingspos);
		}
		else if (abs(moves->dist_x) == moves->dist_y && moves->dist_x > 0) {
			check_f = MoveDiagonalForwardRight(desk, moves, kingspos);
		}
		else if (moves->dist_x == abs(moves->dist_y) && moves->dist_y < 0) {
			check_f = MoveDiagonalBackRight(desk, moves, kingspos);
		}
		else if (moves->dist_x == moves->dist_y && moves->dist_x < 0 && moves->dist_y < 0) {
			check_f = MoveDiagonalBackLeft(desk, moves, kingspos);
		}
		else if (moves->dist_y > 0 && desk[moves->cord_y - 1][moves->cord_x].figure == '_') {
			//printf("%c %d\n\n", desk[moves->cord_y-1][moves->cord_x].figure, desk[moves->cord_y-1][moves->cord_x].color);
			check_f = MoveForward(desk, moves, kingspos);
		}
		else if (moves->dist_y < 0 && desk[moves->cord_y + 1][moves->cord_x].figure == '_') {
			check_f = MoveBack(desk, moves, kingspos);
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
	if (check_f)
		return 2; // Check !!!
	return 0;
}

int Knight(Desk desk, Moves* moves, KingsPos* kingspos) {
	int check_f = 0;
	/*if (moves->dist_x == 0) {*/
	if (moves->dist_y > 0 && ((abs(moves->dist_y == 2) && abs(moves->dist_x) == 1) || (abs(moves->dist_x == 2) && abs(moves->dist_y) == 1)))
		check_f = HorseMoveForward(desk, moves, kingspos);
	else if (moves->dist_y < 0 && ((abs(moves->dist_y == 2) && abs(moves->dist_x) == 1) || (abs(moves->dist_x == 2) && abs(moves->dist_y) == 1)))
		check_f = HorseMoveBack(desk, moves, kingspos);
	else
		return 1;
	//}
	//else if (moves->dist_y == 0) {
	//	if (moves->dist_x > 0)
	//		check_f = MoveRight(desk, moves, kingspos);
	//	else
	//		check_f = MoveLeft(desk, moves, kingspos);
	//}
	//else {
	//	//printf("Illegal turn: %s !!!\n\n", moves->hod);
	//	return 1;
	//}
	if (check_f)
		return 2; // Check !!!
	return 0;
}

int Rock(Desk desk, Moves* moves, KingsPos* kingspos) {
	int check_f = 0;

	if (moves->dist_x == 0) {
		if (moves->dist_y > 0)
			check_f = MoveForward(desk, moves, kingspos);
		else
			check_f = MoveBack(desk, moves, kingspos);
	}
	else if (moves->dist_y == 0) {
		if (moves->dist_x > 0)
			check_f = MoveRight(desk, moves, kingspos);
		else
			check_f = MoveLeft(desk, moves, kingspos);
	}
	else {
		return 1;
	}
	if (check_f)
		return 2; // Check !!!
	return 0;
}

int Bishop(Desk desk, Moves* moves, KingsPos* kingspos) {
	int check_f = 0;
	if (abs(moves->dist_x) == moves->dist_y && moves->dist_x < 0) {
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
	if (check_f)
		return 2; // Check !!!
	return 0;
}

int Queen(Desk desk, Moves* moves, KingsPos* kingspos) {
	int check_f = 0;
	if (moves->dist_x == 0) {
		if (moves->dist_y > 0)
			check_f = MoveForward(desk, moves, kingspos);
		else
			check_f = MoveBack(desk, moves, kingspos);
	}
	else if (moves->dist_y == 0) {
		if (moves->dist_x > 0)
			check_f = MoveRight(desk, moves, kingspos);
		else
			check_f = MoveLeft(desk, moves, kingspos);
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
	if (check_f)
		return 2; // Check !!!
	return 0;
}

int King(Desk desk, Moves* moves, KingsPos* kingspos) {
	int check_f = 0;
	if (abs(moves->dist_x) > 1 && abs(moves->dist_y) > 1) {
		//printf("Illegal turn: %s !!!\n\n", moves->hod);
		return 1;
	}
	else {
		if (moves->dist_x == 0) {
			if (moves->dist_y > 0)
				check_f = MoveForward(desk, moves, kingspos);
			else
				check_f = MoveBack(desk, moves, kingspos);
		}
		else if (moves->dist_y == 0) {
			if (moves->dist_x > 0)
				check_f = MoveRight(desk, moves, kingspos);
			else
				check_f = MoveLeft(desk, moves, kingspos);
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
		if (check_f)
			return 2; // Check !!!
	}
	return 0;
}
