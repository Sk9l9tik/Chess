#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/Allocate.h"

#include "../includes/Desk.h"

#include "../includes/Files_functions.h" // include .h file

void* import_game(Moves** game, int* count) {
	char* path = malloc(256 * sizeof(char));
	printf("Path game>");
	scanf("%s", path);	// input path file																
	FILE* GamePath = fopen(path, "r"); // make path pointer

	Moves* new_game = NULL;
	int i = 0;
	//(*count)++;
	if (GamePath) {
		printf("The file was opened successfully\n");
		while (allocate_one(game, count), fgets((*game)[i].hod, sizeof((*game)[0].hod) / sizeof((*game)[0].hod[0]), GamePath)) { // reading string from file
			//if ((*game)[i].hod[2] != '-') { // An almost useless check
			//	printf("Wrong turn: %s\n", (*game)[i].hod);
			//	free_one(game, count);
			//	break;
			//}
			char* p = '\0';
			p = strchr((*game)[i].hod, '\n'); // Mashing the newline character
			if (p)	*p = 0;
			printf("%s\n", (*game)[i].hod); // printing readed turn
			i++;

		}
		fclose(GamePath); // Close file
		//(*count)--;
		strcpy((*game)[*count - 1].hod, "0"); // Check end game
	}
	else {
		printf("No such file!!!\n"); // print error readed file
	}

	free(path);
	return *game;
}
//	./test_games/test_game.txt

void save_game(Moves* game, int count) {
	if (!game) {
		printf("No game to save!!!\n");
		return;
	}

	char* path = malloc(sizeof(char) * 15);
	system("mkdir SavedGames");
	path = "./SavedGames/"; // path saved folder
	char* game_name = malloc(sizeof(char) * 256);
	printf("Game name>");
	scanf("%s", game_name); // input name file
	strcat(game_name, ".txt"); // add file extention

	size_t len = strlen(path) + strlen(game_name) + 1;
	char* game_path = (char*)malloc(sizeof(char) * len);

	strcpy(game_path, path);
	strcat(game_path, game_name); // concatinate path folder and name file


	FILE* GamePath = fopen(game_path, "w"); // make path pointer

	if (GamePath) {
		for (int i = 0; i < count && game[i].hod[0] != '0'; i++) {
			fputs(game[i].hod, GamePath); // print game turn in file
			fputs("\n", GamePath); // print newline character
		}
		fclose(GamePath); // close file
		printf("Game has been written\n"); // print success write
	}
	else {
		printf("No such file!!!\n"); // print wrong open file
	}

	free(game_path);
}