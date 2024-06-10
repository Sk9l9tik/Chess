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
	char cord_x;
	char cord_y;
	char dist_x;
	char dist_y;
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
	char w_king_x;
	char w_king_y;
	char b_king_x;
	char b_king_y;

	char Check_f;
	char cMate_f;
	char Mate_color;

	char color;
	char color_turn;

	char wk_count;
	char bk_count;
	char wrl_count;
	char wrr_count;
	char brl_count;
	char brr_count;

} KingsPos;

#endif