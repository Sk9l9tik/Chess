#include <stdio.h>

#include "../includes/Moves.h"
#include "../includes/Figures.h"

#include "../includes/CheckMate.h"

int Move(Desk desk, Moves* moves, KingsPos* kingspos) {
	int flag = 0, check_flag = 0;
	
	if (desk[moves->cord_y][moves->cord_x].figure == 'P') {
		flag = Pawn(desk, moves, kingspos);
	}
	else if (desk[moves->cord_y][moves->cord_x].figure == 'N') {
		flag = Knight(desk, moves, kingspos);
	}
	else if (desk[moves->cord_y][moves->cord_x].figure == 'R') {
		flag = Rock(desk, moves, kingspos);
	}
	else if (desk[moves->cord_y][moves->cord_x].figure == 'B') {
		flag = Bishop(desk, moves, kingspos);
	}
	else if (desk[moves->cord_y][moves->cord_x].figure == 'Q') {
		flag = Queen(desk, moves, kingspos);
	}
	else if (desk[moves->cord_y][moves->cord_x].figure == 'K') {
		flag = King(desk, moves, kingspos);
		if (flag != 1) {
			// king pos...
		}
	}
	else {
		flag = 1;
	}
	return flag;
}