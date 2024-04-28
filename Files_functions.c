#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Desk.h"

#include "Files_functions.h"

int import_game(Moves* game) {
	char path[200];
	printf("Path game>");
	scanf("%s", path);																			
	FILE* GamePath = fopen(path, "r");

	int i = 0;
	if (GamePath) {
		while (fgets(game[i].hod, sizeof(game[0].hod) / sizeof(game[0].hod[0]), GamePath)) {
			char* p='\0';
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

//	./test_games/test_game.txt


void save_game(Moves* game) {
	char* path = malloc(15);
	path = "./SavedGames/";
	char* game_name = malloc(100);
	printf("Game name>");
	scanf("%s", game_name);


	int len = strlen(path) + strlen(game_name) + 1;
	char* game_path = malloc(len);

	strcpy(game_path, path);
	strcat(game_path, game_name);


	FILE* GamePath = fopen(game_path, "w");

	if (GamePath) {
		for (int i = 0; game[i].hod[0] != '\0'; i++) {
			fputs(game[i].hod, GamePath);
			fputs("\n", GamePath);
		}
		fclose(GamePath);
		printf("Game has been written\n");
	}
	else {
		printf("No such file!!!\n");
	}
}