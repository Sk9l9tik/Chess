#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/Init.h"


void init(Desk desk) {
	Figure P = { 'P',0 }, B = { 'B',0 }, R = { 'R',0 }, N = { 'N',0 }, Q = { 'Q',0 }, K = { 'K',0 }, n = { '_',2 };
	desk[0][0] = R;
	desk[0][7] = R;
	desk[0][1] = N;
	desk[0][6] = N;
	desk[0][2] = B;
	desk[0][5] = B;
	desk[0][3] = Q;
	desk[0][4] = K;



	P.color = B.color = R.color = N.color = Q.color = K.color = 1;
	desk[7][0] = R;
	desk[7][7] = R;
	desk[7][1] = N;
	desk[7][6] = N;
	desk[7][2] = B;
	desk[7][5] = B;
	desk[7][3] = Q;
	desk[7][4] = K;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i == 1) {
				P.color = 0;
				desk[i][j] = P;
			}
			else if (i == 6) {
				P.color = 1;
				desk[i][j] = P;
			}
			else if (i != 0 && i != 7)
				desk[i][j] = n;
		}
	}

	//desk[1][3] = n;
	//K.color = 0;
	//desk[3][5] = K;

	//Q.color = 0;
	//desk[1][5] = n;
}

int printDesk(Desk desk) {
	for (int i = 0; i < 8; i++) {
		printf("%d|", 8 - i);
		for (int j = 0; j < 8; j++) {
			printf("%c ", desk[i][j].figure);
		}
		printf("\n");
	}
	printf("  ---------------\n");
	printf("  A B C D E F G H\n\n");
	//printf("\n");
	return 0;
}

void initMoves(Moves* moves, int color_turn) {
	//printf("%c\n", hod[4]);
	char* hod;

	if (color_turn == 1 && moves->hod[0] == 'O' && moves->hod[1] == '-' && moves->hod[2] == 'O' && moves->hod[3] != '-')
		hod = "e1-g1";
	else if (color_turn == 1 && moves->hod[0] == 'O' && moves->hod[1] == '-' && moves->hod[2] == 'O' && moves->hod[3] == '-' && moves->hod[4] == 'O' && moves->hod[5] != '-')
		hod = "e1-c1";
	else if (color_turn == 0 && moves->hod[0] == 'O' && moves->hod[1] == '-' && moves->hod[2] == 'O' && moves->hod[3] != '-')
		hod = "e8-g8";
	else if (color_turn == 0 && moves->hod[0] == 'O' && moves->hod[1] == '-' && moves->hod[2] == 'O' && moves->hod[3] == '-' && moves->hod[4] == 'O' && moves->hod[5] != '-')
		hod = "e8-c8";
	else
		hod = moves->hod;

	moves->cord_x = (hod[0] - 'a');
	moves->cord_y = 8 - (hod[1] - '0');

	//printf("finX: %d finY: %d\n", hod[3] - 'a', hod[4] - '0');

	moves->dist_x = hod[3] - (hod[0]);
	moves->dist_y = hod[4] - (hod[1]);		

	//memcpy(moves, hod, sizeof(*hod));


	/*
		printf("%s\n", hod);
		printf("dX:%d dY:%d\n", dist_x, dist_y); // ia?aou iooe oeao?u
		printf("X:%d Y:%d\n", moves->cord_x, moves->cord_y);   // ia?aou eii?aeia oeao?u
		printf("%c %d\n\n", desk[moves->cord_y][moves->cord_x].figure, desk[moves->cord_y][moves->cord_x].color); // ia?aou oeao?u e aa oaaoa
	*/
}

void initKingsPos(KingsPos* kingspos) {
	//white
	
	kingspos->w_king_x = 4;
	kingspos->w_king_y = 7;

	//black
	kingspos->b_king_x = 4; // 4
	kingspos->b_king_y = 0; // 0

	kingspos->cMate_f = 0;
	kingspos->Check_f = 0;

	kingspos->wk_count = 0;
	kingspos->bk_count = 0;
	kingspos->wrl_count = 0;
	kingspos->brl_count = 0;
	kingspos->wrr_count = 0;
	kingspos->brr_count = 0;

}
