#pragma once


#define MAXTURNS 10

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
	Moves game_moves[MAXTURNS];						//Moves game_moves[MAXTURNS];
} Game;

#endif

