#include <stdio.h>
#include <stdlib.h>

#include "Init.h"


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
}

void printDesk(Desk desk) {
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
}


char* input(char hod[7]) {
	printf(">");
	int a = scanf("%s", hod);
	printf("\n");
	return hod;
}
