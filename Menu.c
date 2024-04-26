#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "Desk.h"
#include "Menu.h"
#include "Game_menu_functions.h"

void game_menu(Moves* game, int* size) {
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

        if (scanf("%d", &k) != 1) k = -1;
        fflush(stdin);



        switch (k) {
        case 0:
            games_list(game);
            break;
        case 1:
            print_game(game, -1, size);
            break;
        case 2:
            //int sz_game = sizeof(*game) / sizeof(*game[0]);
            //printf("%d\n", sz_game);
            while (printf("Number turn>"),
                fflush(stdin),
                scanf("%d", &number) != 1) number = -2;                 //|| number > sz_game
            print_game(game, number, size);
            break;
        case 3:                                                         // make it 
            insert_turn(game, size);
            break;
        case 4:                                                         // make it func
            delete_turn(game, size);
            break;
        case 5:                                                         // make it func
            modify_turn(game);
            break;
        }
    } while (k);

}

void games_list(Moves* lastgame) {
    int k, size = 0;

    char gameMoves[MAXTURNS][7] = { "e2-e4", "e7-e5", "\0" };
    //* gameMoves2[MAXTURNS] = { "a2-a4", "h7-h5", NULL };

    Moves game[MAXTURNS] = { 0 };

    for (int i = 0; gameMoves[i][0] != '\0'; i++) {
        memcpy(game[i].hod, gameMoves[i], sizeof(gameMoves[0]));
        initMoves(&game[i]);
        size++;
    }

    //printf("%s\n", game[0].hod);
    Game games_list[10] = { '\0' };
    char gamename[31] = "game1";
    memcpy(&games_list[0].game_name, &gamename, sizeof(gamename));
    memcpy(&games_list[0].game_moves, &game[0], sizeof(game));

    if (lastgame->hod[0] == 0) {
        printf("%s\n", "empty!");
    }


    /*
    Moves game2[MAXTURNS] = { NULL };
    for (int i = 0; gameMoves2[i] != NULL; i++) {
        initMoves(&game2[i], gameMoves2[i]);
    }
    */



    printf("To choice game input game number\n");
    for (int i = 0; i < MAXTURNS && games_list[i].game_name[0] != '\0'; i++) {
        printf("\t%d: %s\n", i + 1, games_list[i].game_name);
    }


    printf("\t0: Return back\n");
    while (printf(">"),
        fflush(stdin),
        scanf("%d", &k) != 1)
        k = -1;

    if (k == 0)
        return;
    else {
        //printf("%s\n", games_list[k - 1].game_moves->hod);
        //printf("%lld\n", sizeof(games_list[k - 1].game_moves) / sizeof(games_list[k - 1].game_moves[0]));

        game_menu(games_list[k - 1].game_moves, &size);
    }

}

void main_menu() {

    Moves game[MAXTURNS] = { 0 };

    int k;
    do {
        printf("Choice one and input option number\n"
            "\t1: New game\n"
            "\t2: Import game\n"
            "\t3: Choice game\n"
            "\t4: Save last game\n"
            "\t0: Exit\n"
            ">");

        fflush(stdin);
        if (scanf("%d", &k) != 1) k = -1;

        switch (k) {
        case 0:
            return;
        case 1:
            new_game(game);
            break;
        case 2:
            //import_game(path);
            break;
        case 3:
            games_list(game);
            break;
        case 4:
            //foo(game);
            //save_game(game);
            break;
        }
    } while (k);
}
