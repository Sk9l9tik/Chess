#include <stdio.h>

#include "Moves.h"

/*Forward-Back move functions*/
int MoveForward(Desk desk, Moves* moves, KingsPos* kingspos) {
	Figure t = { '_',0 };
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1; //check_f = kingspos->Check_f;

	for (int i = 1; i <= moves->dist_y; i++) {
		t_cord_y--;
		//printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
		//printf("%c %d\n", desk[t_cord_y][t_cord_x].figure, desk[t_cord_y][t_cord_x].color);
		if ((t_cord_y + moves->dist_y == moves->cord_y && desk[t_cord_y][t_cord_x].color != desk[moves->cord_y][moves->cord_x].color)) {
			if (desk[t_cord_y][t_cord_x].figure == 'K') 
				return 1;
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
		return 0;
	}
}

int MoveBack(Desk desk, Moves* moves, KingsPos* kingspos) {
	Figure t = { '_',0 };
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1, check_f = kingspos->Check_f;

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
int MoveDiagonalForwardLeft(Desk desk, Moves* moves, KingsPos* kingspos) {
	Figure t = { '_',0 };
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1, check_f = kingspos->Check_f;

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

int MoveDiagonalForwardRight(Desk desk, Moves* moves, KingsPos* kingspos) {
	Figure t = { '_',0 };
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1, check_f = kingspos->Check_f;

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

int MoveDiagonalBackRight(Desk desk, Moves* moves, KingsPos* kingspos) {
	Figure t = { '_',0 };
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1, check_f = kingspos->Check_f;

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

int MoveDiagonalBackLeft(Desk desk, Moves* moves, KingsPos* kingspos) {
	Figure t = { '_',0 };
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1, check_f = kingspos->Check_f;

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
int MoveRight(Desk desk, Moves* moves, KingsPos* kingspos) {
	Figure t = { '_',0 };
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1, check_f = kingspos->Check_f;

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

int MoveLeft(Desk desk, Moves* moves, KingsPos* kingspos) {
	Figure t = { '_',0 };
	int t_cord_x = moves->cord_x;
	int t_cord_y = moves->cord_y;
	int Flag = 1, check_f = kingspos->Check_f;

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
int HorseMoveForward(Desk desk, Moves* moves, KingsPos* kingspos) {
	Figure t = { '_',0 };
	int Flag = 1, check_f = kingspos->Check_f;
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

int HorseMoveBack(Desk desk, Moves* moves, KingsPos* kingspos) {
	Figure t = { '_',0 };
	int Flag = 1, check_f = kingspos->Check_f;
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