#include <stdio.h>

#include "Moves.h"

/*Forward-Back move functions*/
void MoveForward(Desk desk, Moves* moves) {
	Figure t = { '_',0 };
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1;

	for (int i = 1; i <= moves->dist_y; i++) {
		t_cord_y--;
		//printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
		//printf("%c %d\n", desk[t_cord_y][t_cord_x].figure, desk[t_cord_y][t_cord_x].color);
		if ((t_cord_y + moves->dist_y == moves->cord_y && desk[t_cord_y][t_cord_x].color != desk[moves->cord_y][moves->cord_x].color)) {
			break;
		}
		else if (desk[t_cord_y][t_cord_x].figure != '_') {
			printf("Illegal turn: %s !!!\n\n", moves->hod);
			Flag = 0;
			break;
		}

	}

	if (Flag == 1) {
		desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
		desk[moves->cord_y][moves->cord_x] = t;
	}
}

void MoveBack(Desk desk, Moves* moves) {
	Figure t = { '_',0 };
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1;

	for (int i = 0; i > moves->dist_y; i--) {
		t_cord_y++;
		//printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
		//printf("%c %d\n", desk[t_cord_y][t_cord_x].figure, desk[t_cord_y][t_cord_x].color);
		if ((t_cord_y + moves->dist_y == moves->cord_y && desk[t_cord_y][t_cord_x].color != desk[moves->cord_y][moves->cord_x].color && desk[t_cord_y][t_cord_x].color != 2)) {
			break;
		}
		else if (desk[t_cord_y][t_cord_x].figure != '_') {
			printf("Illegal turn: %s !!!\n\n", moves->hod);
			Flag = 0;
			break;
		}
	}

	if (Flag == 1) {
		desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
		desk[moves->cord_y][moves->cord_x] = t;
	}
}


/*Diagonal move functions*/
void MoveDiagonalForwardLeft(Desk desk, Moves* moves) {
	Figure t = { '_',0 };
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1;

	for (int i = 1; i <= moves->dist_y; i++) {
		t_cord_x--;
		t_cord_y--;
		if (moves->dist_y > 0) {
			/*
			printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
			printf("%c %d\n", desk[t_cord_y][t_cord_x].figure, desk[t_cord_y][t_cord_x].color);
			printf("X-dX:%d Y-dY:%d\n", t_cord_x - moves->dist_x, t_cord_y+moves->dist_y);
			*/
			if ((t_cord_y + moves->dist_y == moves->cord_y && t_cord_x - moves->dist_x == moves->cord_x && desk[t_cord_y][t_cord_x].color != desk[moves->cord_y][moves->cord_x].color)) {
				break;
			}
			else if (desk[t_cord_y][t_cord_x].figure != '_') {
				printf("Illegal turn: %s !!!\n\n", moves->hod);
				Flag = 0;
				break;
			}
		}
	}

	if (Flag == 1) {
		desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
		desk[moves->cord_y][moves->cord_x] = t;
	}

}

void MoveDiagonalForwardRight(Desk desk, Moves* moves) {
	Figure t = { '_',0 };
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1;

	for (int i = 1; i <= moves->dist_y; i++) {
		t_cord_x++;
		t_cord_y--;
		if (moves->dist_x > 0) {
			//printf("X:%d Y:%d\n", moves->cord_x, moves->cord_y);
			//printf("%c %d\n", desk[moves->cord_y][moves->cord_x].figure, desk[moves->cord_y][moves->cord_x].color);
			if ((t_cord_y + moves->dist_y == moves->cord_y && t_cord_x - moves->dist_x == moves->cord_x && desk[t_cord_y][t_cord_x].color != desk[moves->cord_y][moves->cord_x].color)) {
				break;
			}
			else if (desk[t_cord_y][t_cord_x].figure != '_') {
				printf("Illegal turn: %s !!!\n\n", moves->hod);
				Flag = 0;
				break;
			}
		}
	}
	if (Flag == 1) {
		desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
		desk[moves->cord_y][moves->cord_x] = t;
	}
}

void MoveDiagonalBackRight(Desk desk, Moves* moves) {
	Figure t = { '_',0 };
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1;

	for (int i = 0; i > moves->dist_y; i--) {
		t_cord_x++;
		t_cord_y++;
		if (moves->dist_y < 0) {
			//printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
			//printf("%c %d\n", desk[t_cord_y][t_cord_x].figure, desk[t_cord_y][t_cord_x].color);
			if ((t_cord_y + moves->dist_y == moves->cord_y && t_cord_x - moves->dist_x == moves->cord_x && desk[t_cord_y][t_cord_x].color != desk[moves->cord_y][moves->cord_x].color)) {
				break;
			}
			else if (desk[t_cord_y][t_cord_x].figure != '_') {
				printf("Illegal turn: %s !!!\n\n", moves->hod);
				Flag = 0;
				break;
			}
		}
	}

	if (Flag == 1) {
		desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
		desk[moves->cord_y][moves->cord_x] = t;
	}

}

void MoveDiagonalBackLeft(Desk desk, Moves* moves) {
	Figure t = { '_',0 };
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1;

	for (int i = 0; i > moves->dist_y; i--) {
		t_cord_x--;
		t_cord_y++;
		if (moves->dist_x < 0) {
			//printf("X:%d Y:%d\n", moves->cord_x, moves->cord_y);
			//printf("%c %d\n", desk[moves->cord_y][moves->cord_x].figure, desk[moves->cord_y][moves->cord_x].color);
			if ((t_cord_y + moves->dist_y == moves->cord_y && t_cord_x - moves->dist_x == moves->cord_x && desk[t_cord_y][t_cord_x].color != desk[moves->cord_y][moves->cord_x].color)) {
				break;
			}
			else if (desk[t_cord_y][t_cord_x].figure != '_') {
				printf("Illegal turn: %s !!!\n\n", moves->hod);
				Flag = 0;
				break;
			}
		}
	}
	if (Flag == 1) {
		desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
		desk[moves->cord_y][moves->cord_x] = t;
	}
}


/*Left-Right move Functions*/
void MoveRight(Desk desk, Moves* moves) {
	Figure t = { '_',0 };
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1;

	for (int i = 1; i <= moves->dist_x; i++) {
		t_cord_x++;
		//printf("X:%d Y:%d\n", moves->cord_x, moves->cord_y);
		//printf("%c %d\n", desk[moves->cord_y][moves->cord_x].figure, desk[moves->cord_y][moves->cord_x].color);
		if ((t_cord_x - moves->dist_x == moves->cord_x && desk[t_cord_y][t_cord_x].color != desk[moves->cord_y][moves->cord_x].color)) {
			break;
		}
		else if (desk[t_cord_y][t_cord_x].figure != '_') {
			printf("Illegal turn: %s !!!\n\n", moves->hod);
			Flag = 0;
			break;
		}
	}

	if (Flag == 1) {
		desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
		desk[moves->cord_y][moves->cord_x] = t;
	}
}

void MoveLeft(Desk desk, Moves* moves) {
	Figure t = { '_',0 };
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1;

	for (int i = 0; i > moves->dist_x; i--) {
		t_cord_x--;
		//printf("X:%d Y:%d\n", moves->cord_x, moves->cord_y);
		//printf("%c %d\n", desk[moves->cord_y][moves->cord_x].figure, desk[moves->cord_y][moves->cord_x].color);
		if ((t_cord_x - moves->dist_x == moves->cord_x && desk[t_cord_y][t_cord_x].color != desk[moves->cord_y][moves->cord_x].color)) {
			break;
		}
		else if (desk[t_cord_y][t_cord_x].figure != '_') {
			printf("Illegal turn: %s !!!\n\n", moves->hod);
			Flag = 0;
			break;
		}

	}

	if (Flag == 1) {
		desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
		desk[moves->cord_y][moves->cord_x] = t;
	}
}


/*Horse move functions*/
void HorseMoveForward(Desk desk, Moves* moves) {
	Figure t = { '_',0 };
	int Flag = 1;
	if (moves->dist_y > 0) {
		//printf("X:%d Y:%d\n", moves->cord_x, moves->cord_y);
		//printf("%c %d\n", desk[moves->cord_y][moves->cord_x].figure, desk[moves->cord_y][moves->cord_x].color);
		int t_cord_x = moves->cord_x + moves->dist_x;
		int t_cord_y = moves->cord_y - moves->dist_y;
		 
		//printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
		if (desk[t_cord_y][t_cord_x].color == desk[moves->cord_y][moves->cord_x].color) {
			printf("Illegal turn: %s !!!\n\n", moves->hod);
			Flag = 0;
		}
		else {
			desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
			desk[moves->cord_y][moves->cord_x] = t;
		}
	}
	else {
		//printf("X:%d Y:%d\n", moves->cord_x, moves->cord_y);
		//printf("%c %d\n", desk[moves->cord_y][moves->cord_x].figure, desk[moves->cord_y][moves->cord_x].color);
		int t_cord_x = moves->cord_x - moves->dist_x;
		int t_cord_y = moves->cord_y + moves->dist_y;
		 
		//printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
		if (desk[t_cord_y][t_cord_x].color == desk[moves->cord_y][moves->cord_x].color) {
			printf("Illegal turn: %s !!!\n\n", moves->hod);
			Flag = 0;
		}
		else {
			desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
			desk[moves->cord_y][moves->cord_x] = t;
		}
	}
}

void HorseMoveBack(Desk desk, Moves* moves) {
	Figure t = { '_',0 };
	int Flag = 1;
	if (moves->dist_y > 0) {
		//printf("X:%d Y:%d\n", moves->cord_x, moves->cord_y);
		//printf("%c %d\n", desk[moves->cord_y][moves->cord_x].figure, desk[moves->cord_y][moves->cord_x].color);
		int t_cord_x = moves->cord_x + moves->dist_x;
		int t_cord_y = moves->cord_y + moves->dist_y;
		 
		//printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
		if (desk[t_cord_y][t_cord_x].color == desk[moves->cord_y][moves->cord_x].color) {
			printf("Illegal turn: %s !!!\n\n", moves->hod);
			Flag = 0;
		}
		else {
			desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
			desk[moves->cord_y][moves->cord_x] = t;
		}
	}
	else {
		//printf("X:%d Y:%d\n", moves->cord_x, moves->cord_y);
		//printf("%c %d\n", desk[moves->cord_y][moves->cord_x].figure, desk[moves->cord_y][moves->cord_x].color);
		int t_cord_x = moves->cord_x + moves->dist_x;
		int t_cord_y = moves->cord_y - moves->dist_y;
		 
		//printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
		if (desk[t_cord_y][t_cord_x].color == desk[moves->cord_y][moves->cord_x].color) {
			printf("Illegal turn: %s !!!\n\n", moves->hod);
			Flag = 0;
		}
		else {
			desk[t_cord_y][t_cord_x] = desk[moves->cord_y][moves->cord_x];
			desk[moves->cord_y][moves->cord_x] = t;
		}
	}
}