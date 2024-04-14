#include <stdio.h>
#include <stdlib.h>

#include "Figures.h"
#include "Moves.h"

/*functions figures*/
void Pawn(Desk desk, int cord_x, int cord_y, int dist_x, int dist_y, char hod[7]) {

	if (((abs(dist_y) == 2 && cord_y == 1) || (abs(dist_y) == 2 && (cord_y == 6)) || (abs(dist_y) == 1 && dist_x == 0) || (abs(dist_y) == 1 && abs(dist_x) == 1))) {
		if (abs(dist_x) == dist_y && dist_x < 0) {
			MoveDiagonalForwardLeft(desk, cord_x, cord_y, dist_x, dist_y, hod);
		}
		else if (abs(dist_x) == dist_y && dist_x > 0) {
			MoveDiagonalForwardRight(desk, cord_x, cord_y, dist_x, dist_y, hod);
		}
		else if (dist_y > 0 && desk[cord_y - 1][cord_x].figure == '_') {
			//printf("%c %d\n\n", desk[cord_y-1][cord_x].figure, desk[cord_y-1][cord_x].color);
			MoveForward(desk, cord_x, cord_y, dist_y, hod);
		}
		else if (dist_y < 0 && desk[cord_y + 1][cord_x].figure == '_') {
			MoveBack(desk, cord_x, cord_y, dist_y, hod);
		}

		else {
			printf("Illegal turn: %s !!!\n\n", hod);
			return;
		}



	}
	else {
		printf("Illegal turn: %s !!!\n\n", hod);
		return;
	}
}

void Knight(Desk desk, int cord_x, int cord_y, int dist_x, int dist_y, char hod[7]) {
	if (dist_x == 0) {
		if (dist_y > 0)
			MoveForward(desk, cord_x, cord_y, dist_y, hod);
		else
			MoveBack(desk, cord_x, cord_y, dist_y, hod);
	}
	else if (dist_y == 0) {
		if (dist_x > 0)
			MoveRight(desk, cord_x, cord_y, dist_x, hod);
		else
			MoveLeft(desk, cord_x, cord_y, dist_x, hod);
	}
	else {
		printf("Illegal turn: %s !!!\n\n", hod);
		return;
	}
}

void Rock(Desk desk, int cord_x, int cord_y, int dist_x, int dist_y, char hod[7]) {
	if (dist_x == 0) {
		if (dist_y > 0)
			MoveForward(desk, cord_x, cord_y, dist_y, hod);
		else
			MoveBack(desk, cord_x, cord_y, dist_y, hod);
	}
	else if (dist_y == 0) {
		if (dist_x > 0)
			MoveRight(desk, cord_x, cord_y, dist_x, hod);
		else
			MoveLeft(desk, cord_x, cord_y, dist_x, hod);
	}
	else {
		printf("Illegal turn: %s !!!\n\n", hod);
		return;
	}
}

void Bishop(Desk desk, int cord_x, int cord_y, int dist_x, int dist_y, char hod[7]) {
	if (abs(dist_x) == dist_y && dist_x < 0) {
		MoveDiagonalForwardLeft(desk, cord_x, cord_y, dist_x, dist_y, hod);
	}
	else if (dist_x == dist_y && dist_x > 0 && dist_y > 0) {
		MoveDiagonalForwardRight(desk, cord_x, cord_y, dist_x, dist_y, hod);
	}
	else if (dist_x == abs(dist_y) && dist_y < 0) {
		MoveDiagonalBackRight(desk, cord_x, cord_y, dist_x, dist_y, hod);
	}
	else if (dist_x == dist_y && dist_x < 0 && dist_y < 0) {
		MoveDiagonalBackLeft(desk, cord_x, cord_y, dist_x, dist_y, hod);
	}
	else {
		printf("Illegal turn: %s !!!\n\n", hod);
		return;
	}
}

void Queen(Desk desk, int cord_x, int cord_y, int dist_x, int dist_y, char hod[7]) {
	if (dist_x == 0) {
		if (dist_y > 0)
			MoveForward(desk, cord_x, cord_y, dist_y, hod);
		else
			MoveBack(desk, cord_x, cord_y, dist_y, hod);
	}
	else if (dist_y == 0) {
		if (dist_x > 0)
			MoveRight(desk, cord_x, cord_y, dist_x, hod);
		else
			MoveLeft(desk, cord_x, cord_y, dist_x, hod);
	}
	else if (abs(dist_x) == dist_y && dist_x < 0) {
		MoveDiagonalForwardLeft(desk, cord_x, cord_y, dist_x, dist_y, hod);
	}
	else if (dist_x == dist_y && dist_x > 0 && dist_y > 0) {
		MoveDiagonalForwardRight(desk, cord_x, cord_y, dist_x, dist_y, hod);
	}
	else if (dist_x == abs(dist_y) && dist_y < 0) {
		MoveDiagonalBackRight(desk, cord_x, cord_y, dist_x, dist_y, hod);
	}
	else if (dist_x == dist_y && dist_x < 0 && dist_y < 0) {
		MoveDiagonalBackLeft(desk, cord_x, cord_y, dist_x, dist_y, hod);
	}
	else {
		printf("Illegal turn: %s !!!\n\n", hod);
		return;
	}
}

void King(Desk desk, int cord_x, int cord_y, int dist_x, int dist_y, char hod[7]) {
	if (abs(dist_x) > 1 && abs(dist_y) > 1) {
		printf("Illegal turn: %s !!!\n\n", hod);
		return;
	}
	else {
		if (dist_x == 0) {
			if (dist_y > 0)
				MoveForward(desk, cord_x, cord_y, dist_y, hod);
			else
				MoveBack(desk, cord_x, cord_y, dist_y, hod);
		}
		else if (dist_y == 0) {
			if (dist_x > 0)
				MoveRight(desk, cord_x, cord_y, dist_x, hod);
			else
				MoveLeft(desk, cord_x, cord_y, dist_x, hod);
		}
		else if (abs(dist_x) == dist_y && dist_x < 0) {
			MoveDiagonalForwardLeft(desk, cord_x, cord_y, dist_x, dist_y, hod);
		}
		else if (dist_x == dist_y && dist_x > 0 && dist_y > 0) {
			MoveDiagonalForwardRight(desk, cord_x, cord_y, dist_x, dist_y, hod);
		}
		else if (dist_x == abs(dist_y) && dist_y < 0) {
			MoveDiagonalBackRight(desk, cord_x, cord_y, dist_x, dist_y, hod);
		}
		else if (dist_x == dist_y && dist_x < 0 && dist_y < 0) {
			MoveDiagonalBackLeft(desk, cord_x, cord_y, dist_x, dist_y, hod);
		}
		else {
			printf("Illegal turn: %s !!!\n\n", hod);
			return;
		}
	}
}
