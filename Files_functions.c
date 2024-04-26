#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "Desk.h"

#include "Files_functions.h"

int import_game(Moves* game) {
	char path[200];
	printf("Path game>");
	scanf("%s", path);																			//!!!!!!!!!!!!!!!!!!!!!!!
	FILE* GamePath = fopen(path, "r");

	int i = 0;
	if (GamePath) {
		while (fgets(game[i].hod, sizeof(game[0].hod) / sizeof(game[0].hod[0]), GamePath)) {
			char* p='0';
			p = strchr(game[i].hod, '\n');
			if (p)	*p = 0;
			printf("%s\n", game[i].hod);
			i++;
		}
		fclose(GamePath);
	}
	else {
		printf("No such file!!!\n");
	}
	return i;
}

// ./test_games/test_game.txt