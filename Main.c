
#define _CRT_SECURE_NO_WARNINGS
#define MAXTURNS 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//#include "Console_Resize.h"
#include "Desk.h"
#include "Init.h"
#include "Figures.h"
#include "Moves.h"

void main_menu();
//void new_game(char** game);
void game_menu(Moves* game, int* size);
void games_list();

void print_game(Moves* game, int turn, int* size);

void insert_turn(Moves* game, int* size);

void delete_turn(Moves* game, int* size);
void modify_turn(Moves* game);



int main() {
    main_menu();
    return 0;
}

/*game function*/

void print_game(Moves* game, int turn, int* size) {

    Desk desk;
    init(desk);
    
    if (turn == -1) {

        printDesk(desk);
        for (int i = 0; i < *size; i++) {
            printf("%s\n", game[i].hod);
            Move(desk, &game[i]);
            printDesk(desk);
        }
    }
    else {
        for (int i = 0; i != turn && i < *size; i++) {
            Move(desk, &game[i]);
            printf("%d\n", i);
        }
        printDesk(desk);
    }
    
                                                                    //printf("%c %d\n", desk[4][4].figure, desk[4][4].color);
}


void insert_turn(Moves* game, int* size) {                                     //game - massiv of struct turns
    int number;
    printf("Number turn>");
    scanf("%d", &number);
    memmove(game + number + 1, game + number, sizeof(game[0]) * (*size) - number);
    printf("Enter turn>");
    scanf("%s", game[number].hod);
    initMoves(&game[number]);
    (*size)++;    
}

void delete_turn(Moves* game, int* size) {
    int number;
    printf("Number turn>");
    scanf("%d", &number);
    memmove(game + number, game + number + 1, sizeof(game[0]) * (*size) - number);
    (*size)--;
}

void modify_turn(Moves* game) {
    int number;
    printf("Number turn>");
    scanf("%d", &number);
    printf("Enter turn>");
    scanf("%s", game[number].hod);
    initMoves(&game[number]);
}


void new_game(char** game) {
    //char* game[MAXTURNS] = { 0 };

    Desk desk;
    init(desk);

    printDesk(desk);

    char hod[7];

    for (int i = 0; i < MAXTURNS; i++) {
        game[i] = input(hod);
        //Move(desk, hod);
        printf("%s %s\n", hod, game[i]);
        printDesk(desk);
    }
}


//import_game()
//save_game()


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
            games_list();
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

void games_list() {                                                 
    int k, size=0;
    
    char gameMoves[MAXTURNS][7] = {"e2-e4", "e7-e5", "\0"};
    //* gameMoves2[MAXTURNS] = { "a2-a4", "h7-h5", NULL };

    Moves game[MAXTURNS] = { 0 };

    for (int i = 0; gameMoves[i][0] != '\0'; i++) {
        memcpy(game[i].hod, gameMoves[i], sizeof(gameMoves[0]));
        initMoves(&game[i]);
        size++;
    }

    //printf("%s\n", game[0].hod);
    Game games_list[10] = {'\0'};
    char gamename[31] = "game1";
    memcpy(&games_list[0].game_name, &gamename, sizeof(gamename));
    memcpy(&games_list[0].game_moves, &game[0], sizeof(game));
    //printf("%s\n", games_list[0].game_moves[0].hod);

    /*
    Moves game2[MAXTURNS] = { NULL };
    for (int i = 0; gameMoves2[i] != NULL; i++) {
        initMoves(&game2[i], gameMoves2[i]);
    }
    */



    printf("To choice game input game number\n");
    for (int i = 0;  i < MAXTURNS && games_list[i].game_name[0] != '\0'; i++) {
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

    //char* game[MAXTURNS];

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
            //new_game(game);
            break;
        case 2:
            //import_game(path);
            break;
        case 3:
            games_list();
            break;
        case 4:
            //foo(game);
            //save_game(game);
            break;
        }
    } while (k);
}
