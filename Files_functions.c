#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Allocate.h"

#include "Desk.h"

#include "Files_functions.h"

void* import_game(Moves** game, int* count) {
	char* path = malloc(256*sizeof(char));
	printf("Path game>");
	scanf("%s", path);																			
	FILE* GamePath = fopen(path, "r");
	
	Moves* new_game = NULL;
	int i = 0;
	(*count)++;
	if (GamePath) {
		while (fgets((*game)[i].hod, sizeof((*game)[0].hod) / sizeof((*game)[0].hod[0]), GamePath)) {

			allocate_one(game, count);
			if ((*game)[i].hod[2] != '-') {
				free_one(game, count);
				break;
			}
			char* p='\0';
			p = strchr((*game)[i].hod, '\n');
			if (p)	*p = 0;
			printf("%s\n", (*game)[i].hod);
			i++;

		}
		fclose(GamePath);
		//(*count)--;
		strcpy((*game)[*count-1].hod, "0");
		
	}
	else {
		printf("No such file!!!\n");
	}

	free(path);
	return *game;
}
//	./test_games/test_game.txt

void save_game(Moves* game, int count) {
	char* path = malloc(sizeof(char) * 15);
	path = "./SavedGames/";
	char* game_name = malloc(sizeof(char)*256);
	printf("Game name>");
	scanf("%s", game_name);
	strcat(game_name, ".txt");

	size_t len = strlen(path) + strlen(game_name) + 1;
	char* game_path = (char*)malloc(sizeof(char)*len);

	strcpy(game_path, path);
	strcat(game_path, game_name);


	FILE* GamePath = fopen(game_path, "w");

	if (GamePath) {
		for (int i = 0; i <= count && game[i].hod[0] != '0'; i++) {
			fputs(game[i].hod, GamePath);
			fputs("\n", GamePath);
		}
		fclose(GamePath);
		printf("Game has been written\n");
	} 
	else {
		printf("No such file!!!\n");
	}

	free(game_path);
}	