#include <stdio.h>

#include "Moves.h"
#include "Figures.h"

void Move(Desk desk, Moves* moves) {
	if (desk[moves->cord_y][moves->cord_x].figure == 'P') {
		Pawn(desk, moves);
	}
	else if (desk[moves->cord_y][moves->cord_x].figure == 'N') {
		Knight(desk, moves);
	}
	else if (desk[moves->cord_y][moves->cord_x].figure == 'R') {
		Rock(desk, moves);
	}
	else if (desk[moves->cord_y][moves->cord_x].figure == 'B') {
		Bishop(desk, moves);
	}
	else if (desk[moves->cord_y][moves->cord_x].figure == 'Q') {
		Queen(desk, moves);
	}
	else if (desk[moves->cord_y][moves->cord_x].figure == 'K') {
		King(desk, moves);
	}
	else {
		printf("Illegal turn: %s !!!\n\n", moves->hod);
		return;
	}
}