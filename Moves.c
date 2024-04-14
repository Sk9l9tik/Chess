#include <stdio.h>

#include "Moves.h"

/*Forward-Back move functions*/
void MoveForward(Desk desk, int cord_x, int cord_y, int dist_y, char hod[7]) {
	Figure t = { '_',0 };
	int t_cord_x = cord_x;
	int t_cord_y = cord_y;
	int Flag = 1;

	for (int i = 1; i <= dist_y; i++) {
		t_cord_y--;
		//printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
		//printf("%c %d\n", desk[t_cord_y][t_cord_x].figure, desk[t_cord_y][t_cord_x].color);
		if ((t_cord_y + dist_y == cord_y && desk[t_cord_y][t_cord_x].color != desk[cord_y][cord_x].color)) {
			break;
		}
		else if (desk[t_cord_y][t_cord_x].figure != '_') {
			printf("Illegal turn: %s !!!\n\n", hod);
			Flag = 0;
			break;
		}

	}

	if (Flag == 1) {
		desk[t_cord_y][t_cord_x] = desk[cord_y][cord_x];
		desk[cord_y][cord_x] = t;
	}
}

void MoveBack(Desk desk, int cord_x, int cord_y, int dist_y, char hod[7]) {
	Figure t = { '_',0 };
	int t_cord_x = cord_x;
	int t_cord_y = cord_y;
	int Flag = 1;

	for (int i = 0; i > dist_y; i--) {
		t_cord_y++;
		//printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
		//printf("%c %d\n", desk[t_cord_y][t_cord_x].figure, desk[t_cord_y][t_cord_x].color);
		if ((t_cord_y + dist_y == cord_y && desk[t_cord_y][t_cord_x].color != desk[cord_y][cord_x].color && desk[t_cord_y][t_cord_x].color != 2)) {
			break;
		}
		else if (desk[t_cord_y][t_cord_x].figure != '_') {
			printf("Illegal turn: %s !!!\n\n", hod);
			Flag = 0;
			break;
		}
	}

	if (Flag == 1) {
		desk[t_cord_y][t_cord_x] = desk[cord_y][cord_x];
		desk[cord_y][cord_x] = t;
	}
}


/*Diagonal move functions*/
void MoveDiagonalForwardLeft(Desk desk, int cord_x, int cord_y, int dist_x, int dist_y, char hod[7]) {
	Figure t = { '_',0 };
	int t_cord_x = cord_x;
	int t_cord_y = cord_y;
	int Flag = 1;

	for (int i = 1; i <= dist_y; i++) {
		t_cord_x--;
		t_cord_y--;
		if (dist_y > 0) {
			/*
			printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
			printf("%c %d\n", desk[t_cord_y][t_cord_x].figure, desk[t_cord_y][t_cord_x].color);
			printf("X-dX:%d Y-dY:%d\n", t_cord_x - dist_x, t_cord_y+dist_y);
			*/
			if ((t_cord_y + dist_y == cord_y && t_cord_x - dist_x == cord_x && desk[t_cord_y][t_cord_x].color != desk[cord_y][cord_x].color)) {
				break;
			}
			else if (desk[t_cord_y][t_cord_x].figure != '_') {
				printf("Illegal turn: %s !!!\n\n", hod);
				Flag = 0;
				break;
			}
		}
	}

	if (Flag == 1) {
		desk[t_cord_y][t_cord_x] = desk[cord_y][cord_x];
		desk[cord_y][cord_x] = t;
	}

}

void MoveDiagonalForwardRight(Desk desk, int cord_x, int cord_y, int dist_x, int dist_y, char hod[7]) {
	Figure t = { '_',0 };
	int t_cord_x = cord_x;
	int t_cord_y = cord_y;
	int Flag = 1;

	for (int i = 1; i <= dist_y; i++) {
		t_cord_x++;
		t_cord_y--;
		if (dist_x > 0) {
			//printf("X:%d Y:%d\n", cord_x, cord_y);
			//printf("%c %d\n", desk[cord_y][cord_x].figure, desk[cord_y][cord_x].color);
			if ((t_cord_y + dist_y == cord_y && t_cord_x - dist_x == cord_x && desk[t_cord_y][t_cord_x].color != desk[cord_y][cord_x].color)) {
				break;
			}
			else if (desk[t_cord_y][t_cord_x].figure != '_') {
				printf("Illegal turn: %s !!!\n\n", hod);
				Flag = 0;
				break;
			}
		}
	}
	if (Flag == 1) {
		desk[t_cord_y][t_cord_x] = desk[cord_y][cord_x];
		desk[cord_y][cord_x] = t;
	}
}

void MoveDiagonalBackRight(Desk desk, int cord_x, int cord_y, int dist_x, int dist_y, char hod[7]) {
	Figure t = { '_',0 };
	int t_cord_x = cord_x;
	int t_cord_y = cord_y;
	int Flag = 1;

	for (int i = 0; i > dist_y; i--) {
		t_cord_x++;
		t_cord_y++;
		if (dist_y < 0) {
			//printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
			//printf("%c %d\n", desk[t_cord_y][t_cord_x].figure, desk[t_cord_y][t_cord_x].color);
			if ((t_cord_y + dist_y == cord_y && t_cord_x - dist_x == cord_x && desk[t_cord_y][t_cord_x].color != desk[cord_y][cord_x].color)) {
				break;
			}
			else if (desk[t_cord_y][t_cord_x].figure != '_') {
				printf("Illegal turn: %s !!!\n\n", hod);
				Flag = 0;
				break;
			}
		}
	}

	if (Flag == 1) {
		desk[t_cord_y][t_cord_x] = desk[cord_y][cord_x];
		desk[cord_y][cord_x] = t;
	}

}

void MoveDiagonalBackLeft(Desk desk, int cord_x, int cord_y, int dist_x, int dist_y, char hod[7]) {
	Figure t = { '_',0 };
	int t_cord_x = cord_x;
	int t_cord_y = cord_y;
	int Flag = 1;

	for (int i = 0; i > dist_y; i--) {
		t_cord_x--;
		t_cord_y++;
		if (dist_x < 0) {
			//printf("X:%d Y:%d\n", cord_x, cord_y);
			//printf("%c %d\n", desk[cord_y][cord_x].figure, desk[cord_y][cord_x].color);
			if ((t_cord_y + dist_y == cord_y && t_cord_x - dist_x == cord_x && desk[t_cord_y][t_cord_x].color != desk[cord_y][cord_x].color)) {
				break;
			}
			else if (desk[t_cord_y][t_cord_x].figure != '_') {
				printf("Illegal turn: %s !!!\n\n", hod);
				Flag = 0;
				break;
			}
		}
	}
	if (Flag == 1) {
		desk[t_cord_y][t_cord_x] = desk[cord_y][cord_x];
		desk[cord_y][cord_x] = t;
	}
}


/*Left-Right move Functions*/
void MoveRight(Desk desk, int cord_x, int cord_y, int dist_x, char hod[7]) {
	Figure t = { '_',0 };
	int t_cord_x = cord_x;
	int t_cord_y = cord_y;
	int Flag = 1;

	for (int i = 1; i <= dist_x; i++) {
		t_cord_x++;
		//printf("X:%d Y:%d\n", cord_x, cord_y);
		//printf("%c %d\n", desk[cord_y][cord_x].figure, desk[cord_y][cord_x].color);
		if ((t_cord_x - dist_x == cord_x && desk[t_cord_y][t_cord_x].color != desk[cord_y][cord_x].color)) {
			break;
		}
		else if (desk[t_cord_y][t_cord_x].figure != '_') {
			printf("Illegal turn: %s !!!\n\n", hod);
			Flag = 0;
			break;
		}
	}

	if (Flag == 1) {
		desk[t_cord_y][t_cord_x] = desk[cord_y][cord_x];
		desk[cord_y][cord_x] = t;
	}
}

void MoveLeft(Desk desk, int cord_x, int cord_y, int dist_x, char hod[7]) {
	Figure t = { '_',0 };
	int t_cord_x = cord_x;
	int t_cord_y = cord_y;
	int Flag = 1;

	for (int i = 0; i > dist_x; i--) {
		t_cord_x--;
		//printf("X:%d Y:%d\n", cord_x, cord_y);
		//printf("%c %d\n", desk[cord_y][cord_x].figure, desk[cord_y][cord_x].color);
		if ((t_cord_x - dist_x == cord_x && desk[t_cord_y][t_cord_x].color != desk[cord_y][cord_x].color)) {
			break;
		}
		else if (desk[t_cord_y][t_cord_x].figure != '_') {
			printf("Illegal turn: %s !!!\n\n", hod);
			Flag = 0;
			break;
		}

	}

	if (Flag == 1) {
		desk[t_cord_y][t_cord_x] = desk[cord_y][cord_x];
		desk[cord_y][cord_x] = t;
	}
}


/*Horse move functions*/
void HorseMoveForward(Desk desk, int cord_x, int cord_y, int dist_y, int dist_x, char hod[7]) {
	Figure t = { '_',0 };
	if (dist_y > 0) {
		//printf("X:%d Y:%d\n", cord_x, cord_y);
		//printf("%c %d\n", desk[cord_y][cord_x].figure, desk[cord_y][cord_x].color);
		int t_cord_x = cord_x + dist_x;
		int t_cord_y = cord_y - dist_y;
		int Flag = 1;
		//printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
		if (desk[t_cord_y][t_cord_x].color == desk[cord_y][cord_x].color) {
			printf("Illegal turn: %s !!!\n\n", hod);
			Flag = 0;
		}
		else {
			desk[t_cord_y][t_cord_x] = desk[cord_y][cord_x];
			desk[cord_y][cord_x] = t;
		}
	}
	else {
		//printf("X:%d Y:%d\n", cord_x, cord_y);
		//printf("%c %d\n", desk[cord_y][cord_x].figure, desk[cord_y][cord_x].color);
		int t_cord_x = cord_x - dist_x;
		int t_cord_y = cord_y + dist_y;
		int Flag = 1;
		//printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
		if (desk[t_cord_y][t_cord_x].color == desk[cord_y][cord_x].color) {
			printf("Illegal turn: %s !!!\n\n", hod);
			Flag = 0;
		}
		else {
			desk[t_cord_y][t_cord_x] = desk[cord_y][cord_x];
			desk[cord_y][cord_x] = t;
		}
	}
}

void HorseMoveBack(Desk desk, int cord_x, int cord_y, int dist_y, int dist_x, char hod[7]) {
	Figure t = { '_',0 };
	if (dist_y > 0) {
		//printf("X:%d Y:%d\n", cord_x, cord_y);
		//printf("%c %d\n", desk[cord_y][cord_x].figure, desk[cord_y][cord_x].color);
		int t_cord_x = cord_x + dist_x;
		int t_cord_y = cord_y + dist_y;
		int Flag = 1;
		//printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
		if (desk[t_cord_y][t_cord_x].color == desk[cord_y][cord_x].color) {
			printf("Illegal turn: %s !!!\n\n", hod);
			Flag = 0;
		}
		else {
			desk[t_cord_y][t_cord_x] = desk[cord_y][cord_x];
			desk[cord_y][cord_x] = t;
		}
	}
	else {
		//printf("X:%d Y:%d\n", cord_x, cord_y);
		//printf("%c %d\n", desk[cord_y][cord_x].figure, desk[cord_y][cord_x].color);
		int t_cord_x = cord_x + dist_x;
		int t_cord_y = cord_y - dist_y;
		int Flag = 1;
		//printf("X:%d Y:%d\n", t_cord_x, t_cord_y);
		if (desk[t_cord_y][t_cord_x].color == desk[cord_y][cord_x].color) {
			printf("Illegal turn: %s !!!\n\n", hod);
			Flag = 0;
		}
		else {
			desk[t_cord_y][t_cord_x] = desk[cord_y][cord_x];
			desk[cord_y][cord_x] = t;
		}
	}
}