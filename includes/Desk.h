#pragma once 

#ifndef MAXTURNS_H
#define MAXTURNS_H
#define MAXTURNS 3
#endif


#ifndef DESK_H
#define DESK_H

typedef struct Figure {
	char figure;
	char color; // 0 - black, 1 - white
} Figure;

typedef Figure Desk[8][8];

#endif

#ifndef MOVES_H
#define MOVES_H

typedef struct Moves {
	int cord_x;
	int cord_y;
	int dist_x;
	int dist_y;
	char hod[7];
} Moves;

#endif

#ifndef GAME_H
#define GAME_H

typedef struct Game {
	char game_name[31];
	Moves* game_moves;						//Moves game_moves[MAXTURNS];
	int* game_size;
} Game;

#endif

#ifndef KigsPos_H
#define KigsPos_H

typedef struct KingsPos {
	int w_king_x;
	int w_king_y;
	int b_king_x;
	int b_king_y;

	char Check_f;
	char Mate_f;

	char color;
	char color_turn;

	int wk_count;
	int bk_count;
	int wrl_count;
	int wrr_count;
	int brl_count;
	int brr_count;


	int check_figure_x;
	int check_figure_y;
	int dfigure_x;
	int dfigure_y;

} KingsPos;

#endif