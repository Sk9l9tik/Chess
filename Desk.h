#pragma once

#ifndef DESK_H
#define DESK_H

typedef int position;
typedef struct Figure {
	char figure;
	char color; // 0 - black, 1 - white
} Figure;
typedef Figure Desk[8][8];

#endif


#ifndef GAME_H
#define GAME_H

typedef struct Game {
	char* name;
	char** game;
} Game;

#endif
