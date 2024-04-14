#include <stdio.h>

#include "Moves.h"
#include "Figures.h"

void Move(Desk desk, char hod[7]) {

	//printf("%c\n", hod[4]);
	/*au?eneaiea eii?aeiao oeao?u ii iioaoee*/
	int cord_x = (hod[0] - 'a');
	int cord_y = 8 - (hod[1] - '0');

	//printf("finX: %d finY: %d\n", hod[3] - 'a', hod[4] - '0');
	int dist_y = hod[4] - (hod[1]);  // au?eneaiey ?anniyiey ii o
	int dist_x = hod[3] - (hod[0]);	 // au?eneaiey ?anniyiey ii o
	/*
		printf("dX:%d dY:%d\n", dist_x, dist_y); // ia?aou iooe oeao?u
		printf("X:%d Y:%d\n", cord_x, cord_y);   // ia?aou eii?aeia oeao?u
		printf("%c %d\n\n", desk[cord_y][cord_x].figure, desk[cord_y][cord_x].color); // ia?aou oeao?u e aa oaaoa
	*/
	if (desk[cord_y][cord_x].figure == 'P') {
		Pawn(desk, cord_x, cord_y, dist_x, dist_y, hod);
	}
	else if (desk[cord_y][cord_x].figure == 'N') {
		Knight(desk, cord_x, cord_y, dist_x, dist_y, hod);
	}
	else if (desk[cord_y][cord_x].figure == 'R') {
		Rock(desk, cord_x, cord_y, dist_x, dist_y, hod);
	}
	else if (desk[cord_y][cord_x].figure == 'B') {
		Bishop(desk, cord_x, cord_y, dist_x, dist_y, hod);
	}
	else if (desk[cord_y][cord_x].figure == 'Q') {
		Queen(desk, cord_x, cord_y, dist_x, dist_y, hod);
	}
	else if (desk[cord_y][cord_x].figure == 'K') {
		King(desk, cord_x, cord_y, dist_x, dist_y, hod);
	}
	else {
		printf("Illegal turn: %s !!!\n\n", hod);
		return;
	}
}