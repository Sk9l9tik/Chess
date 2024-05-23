#include <stdio.h>

#include "Moves.h"
#include "Figures.h"

#include "CheckMate.h"

int Move(Desk desk, Moves* moves, KingsPos* kingspos) {
	int flag = 0, check_flag = 0;
	
	if (desk[moves->cord_y][moves->cord_x].figure == 'P') {
		flag = Pawn(desk, moves);
	}
	else if (desk[moves->cord_y][moves->cord_x].figure == 'N') {
		flag = Knight(desk, moves);
	}
	else if (desk[moves->cord_y][moves->cord_x].figure == 'R') {
		flag = Rock(desk, moves);
	}
	else if (desk[moves->cord_y][moves->cord_x].figure == 'B') {
		flag = Bishop(desk, moves);
	}
	else if (desk[moves->cord_y][moves->cord_x].figure == 'Q') {
		flag = Queen(desk, moves);
	}
	else if (desk[moves->cord_y][moves->cord_x].figure == 'K') {
		flag = King(desk, moves);
	}
	else {
		flag = 1;
	}
	return flag;
}