#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "../includes/Desk.h"
#include "../includes/Init.h"

#include "../includes/Menu.h"
#include "../includes/Game_menu_functions.h"

#include "../includes/Files_functions.h"      

#include "../includes/Directory_files.h"

#include "../includes/OnlineConnection.h"


void game_menu(Moves** game,KingsPos* kingspos, int* size) {
    system("cls");

    int k, number;
   
    do {
        printf("Choice one and input option number\n"
            "\t1: Watch game\n"
            "\t2: Watch game turn\n"
            "\t3: Insert turn\n"
            "\t4: Delete turn\n"
            "\t5: Modify turn\n"
            "\t0: Return back\n"
            ">");

        fflush(stdin);
        if (scanf("%d", &k) != 1) k = -1;
        

        switch (k) {
        case 0:
            return;
            //games_list(game, 0);
            break;
        case 1:
            print_game(*game, kingspos, -1, size);
            break;
        case 2:
            //int sz_game = sizeof(*game) / sizeof(*game[0]);
            //printf("%d\n", sz_game);
            while (printf("Number turn>"),
                fflush(stdin),
                scanf("%d", &number) != 1) number = -2;                 //|| number > sz_game
            print_game(*game, kingspos, number, size);
            break;
        case 3:                                                          
            //printf("%s %s\n", (*game)[*size - 2].hod, (*game)[*size - 1].hod);
            insert_turn(game, kingspos->color_turn, size);
            //printf("%s %s %s\n", (*game)[*size - 3].hod, (*game)[*size - 2].hod, (*game)[*size-1].hod);
            break;
        case 4:                                                         
            delete_turn(game, size, 0);
            break;
        case 5:                                                         
            modify_turn(game, kingspos->color_turn, size);
            break;
        }
    } while (k);
}

void* games_list(Moves* lastgame, int* lastgame_size) {
    system("cls");
    KingsPos kingspos;
    initKingsPos(&kingspos);

    int k, size = 0, cnt = 0;

    char gameMoves[MAXTURNS][7] = { "e2-e4", "e7-e5", "0" };
    //Moves game[MAXTURNS] = { 0 };
    Moves* game = (Moves*)malloc(sizeof(Moves) * MAXTURNS);
    for (int i = 0; gameMoves[i][0] != '0'; i++) {
        memcpy(game[i].hod, gameMoves[i], sizeof(gameMoves[0]));
        initMoves(&game[i], kingspos.color_turn);
        size++;
    }


    Game games_list[10] = { '\0' };
    //Game* games_list = (Game*)malloc(10 * sizeof(Game));

    char gamename[31] = "game1";
    memcpy(&games_list[0].game_name, gamename, sizeof(gamename));
    //memcpy(&games_list[0].game_moves, game, sizeof(game));
    games_list[0].game_moves = game;
    games_list[0].game_size = &size;
    cnt++;





    if (lastgame != NULL) {
        if (lastgame->hod[0] != 0) {
            for (int i = 0; i <= *lastgame_size /*(lastgame)[i].hod[0] != '0'*/; i++) {
                initMoves(&(lastgame[i]), kingspos.color_turn);
            }
            //printf("---%d---\n", *lastgame_size);
            char lastgamename[31] = "last_game";
            memcpy(&games_list[cnt].game_name, lastgamename, sizeof(lastgamename));
            games_list[cnt].game_moves = lastgame;
            games_list[cnt].game_size = lastgame_size;
        }
    }

    printf("To choice game input game number\n");
    int i;
    for (i = 0; games_list[i].game_name[0] != '\0'; i++) {
        printf("\t%d: %s\n", i + 1, games_list[i].game_name);
    }
    printf("\t0: Return back\n");

    while (printf(">"),
        fflush(stdin),
        scanf("%d", &k) != 1 || k > i || k < 0) {
        printf("Innvalin game number!\n");
        printf("To choice game input game number\n");
        int i;
        for (i = 0; games_list[i].game_name[0] != '\0'; i++) {
            printf("\t%d: %s\n", i + 1, games_list[i].game_name);
        }
        printf("\t0: Return back\n");
    }

    if (k == 0) {
        //free(game);
        return games_list[k - 1].game_moves;
    }
    else {
        game_menu(&games_list[k - 1].game_moves, &kingspos, games_list[k - 1].game_size);
        //printf("%d %s %s %s\n", size, (games_list[k - 1].game_moves)[size - 3].hod, (games_list[k - 1].game_moves)[size - 2].hod, (games_list[k - 1].game_moves)[size - 1].hod);
        return games_list[k - 1].game_moves;
    }
}

void OnlineGameMenu(Moves** game, int* count) {
    int k;
    do {
        system("cls");
        printf("Choice one and input option number\n"
            "\t1: Create game (server)\n"
            "\t2: Connect to game (client)\n"
            "\t0: Exit\n"
            ">");

        fflush(stdin);
        if (scanf("%d", &k) != 1) k = -1;

        switch (k) {
        case 0:
            free(game);
            return;
        case 1:
            Server();
            break;
        case 2:
            Client();
            break;
        }
    } while (k);
}

void main_menu() {
    
    Moves* game = NULL;

    int k, count=0;
    do {
        system("cls");
        printf("Choice one and input option number\n"
            "\t1: New game\n"
            "\t2: Online game\n"
            "\t3: Import game\n"
            "\t4: Choice game to edit\n"
            "\t5: Save last game\n"
            "\t0: Exit\n"
            ">");

        fflush(stdin);
        if (scanf("%d", &k) != 1) k = -1;

        switch (k) {
        case 0:
            free(game);
            return;
        case 1:
            count = 0;
            new_game(&game, &count);
            break;
        case 2:
            OnlineGameMenu(&game, &count);
        case 3:
            count = 0;
            game = import_game(&game, &count);
            //printf("---%d---\n", count);
            break;
        case 4:
            game = games_list(game, &count);
            break;
        case 5:
            save_game(game, count);
            break;
        }
    } while (k);
}
