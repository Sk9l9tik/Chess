
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
void new_game(char** game);
//void game_menu(Moves* game);
void games_list();
/*
void print_game(Moves* game, int turn);
char* insert_turn(char** gmae, int number, char turn[7]);
void delete_turn(char** game, int number);
void modify_turn(char** game, int number);
*/



int main() {
    main_menu();
    return 0;
}

/*game function*/
/*
void print_game(Moves* game, int turn) {

    Desk desk;
    init(desk);
    
    if (turn == -1) {

        printDesk(desk);
        for (int i = 0; i < sizeof(game)/sizeof(game[0]); i++) {
            printf("%s\n", game[i].hod);
            //Move(desk, game[i]);
            printDesk(desk);
        }
    }
    else {
        for (int i = 0; i != turn && i < sizeof(game) / sizeof(game[0]); i++) {
            //Move(desk, game[i]);
            printf("%d\n", i);
        }
        printDesk(desk);
    }
    
                                                                    //printf("%c %d\n", desk[4][4].figure, desk[4][4].color);
}

char* insert_turn(char** game, int number, char hod[7]) {

    size_t len = 0;
    for (int i = 0; game[i] != NULL; i++) {
        len++;
    }  
    printf("%lld\n", len);

    //printf("%p %p %s %s\n", game+number-1, game+number, game[number-1], game[number]);

    memmove(game + number + 1, game + number, sizeof(game[0]) * len);

    game[number] = hod;

    

    //debug print
    //printf("%s\n", *(game + number));
    printf("%p %p %s %s\n", game + number-1, game + number, game[number - 1], game[number]);
    printf("%p %p %s %s\n", game + number, game + number + 1, game[number], game[number + 1]);
    printf("%p %p %s %s\n", game + number+1, game + number + 2, game[number+1], game[number + 2]);
    printf("%p %p %s %s\n", game + number + 2, game + number + 3, game[number + 2], game[number + 3]);

    for (int i = 0; game[i] != 0; i++) {
        printf("%s ", game[i]);
    }
    printf("\n");

    return hod;
}
void delete_turn(char** game, int number) {
    
    size_t len = 0;
    for (int i = 0; game[i] != NULL; i++) {
        len++;
    }
    printf("%lld\n", len);
    

    memmove(game + number, game + number + 1, sizeof(game[0])*len);


    //debug print
    printf("%p %p %s %s\n", game + number - 1, game + number, game[number - 1], game[number]);
    printf("%p %p %s %s\n", game + number, game + number + 1, game[number], game[number + 1]);
    printf("%p %p %s %s\n", game + number + 1, game + number + 2, game[number + 1], game[number + 2]);
    printf("%p %p %s %s\n", game + number + 2, game + number + 3, game[number + 2], game[number + 3]);

    for (int i = 0; game[i] != 0; i++) {
        printf("%s ", game[i]);
    }
    printf("\n");
}
void modify_turn(char** game, int number) {
    char turn[7];
    printf("Enter turn>");
    scanf("%s", turn);

    game[number] = turn;

    //debug print
    printf("%p %p %s %s\n", game + number - 1, game + number, game[number - 1], game[number]);
    printf("%p %p %s %s\n", game + number, game + number + 1, game[number], game[number + 1]);
    printf("%p %p %s %s\n", game + number + 1, game + number + 2, game[number + 1], game[number + 2]);
    printf("%p %p %s %s\n", game + number + 2, game + number + 3, game[number + 2], game[number + 3]);

    for (int i = 0; game[i] != 0; i++) {
        printf("%s ", game[i]);
    }
    printf("\n");

}


void new_game(char** game) {
    //char* game[MAXTURNS] = { 0 };

    Desk desk;
    init(desk);

    printDesk(desk);

    char hod[7];

    for (int i = 0; i < MAXTURNS; i++) {
        game[i] = input(hod);
        Move(desk, hod);
        printf("%s %s\n", hod, game[i]);
        printDesk(desk);
    }
}


//import_game()
//save_game()
*/

void game_menu(Moves* game) {
    int k, number, a;
    char hod[7];


    /*
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
            print_game(game, -1);
            break;
        case 2:
                                                                        //int sz_game = sizeof(*game) / sizeof(*game[0]);
                                                                        //printf("%d\n", sz_game);
            while (printf("Number turn>"),                                
                fflush(stdin),
                scanf("%d", &number) != 1) number = -2;                 //|| number > sz_game
            //print_game(game, number);
            break;
        case 3:
            printf("Number turn>");
            scanf("%d", &number);
            input(hod);
            //insert_turn(game, number, hod);

            printf("-----\n");

            //debug print

            break;
        case 4:
            printf("Number turn>");
            a = scanf("%d", &number);
            //delete_turn(game, number);
            break;
        case 5:
            printf("Number turn>");
            a = scanf("%d", &number);
            //modify_turn(game, number);

            //debug print
            /*
            printf("%p %p %s %s\n", game + number - 1, game + number, game[number - 1], game[number]);
            printf("%p %p %s %s\n", game + number, game + number + 1, game[number], game[number + 1]);
            printf("%p %p %s %s\n", game + number + 1, game + number + 2, game[number + 1], game[number + 2]);
            printf("%p %p %s %s\n", game + number + 2, game + number + 3, game[number + 2], game[number + 3]);
            */
            /*
            for (int i = 0; ; i++) {
                printf("%s ", game[i]);
            }
            printf("\n");

            break;
        }
    } while (k);
    */
}


void games_list() {                                                 
    int k;
    
    char* gameMoves[MAXTURNS] = {"e2-e4", "e7-e5", NULL};
    char* gameMoves2[MAXTURNS] = { "a2-a4", "h7-h5", NULL };

    char* hod = gameMoves[0];

    Moves game[MAXTURNS] = { NULL };
    for (int i = 0; gameMoves[i] != NULL; i++) {
        initMoves(&game[i], gameMoves[i]);
    }
    /*
    Moves game2[MAXTURNS] = { NULL };
    for (int i = 0; gameMoves2[i] != NULL; i++) {
        initMoves(&game2[i], gameMoves2[i]);
    }
    */

    /*Dbug print
    for (int i = 0; gameMoves[i] != NULL; i++) {
        printf("%s\n", game[i].hod);
    }
    */

    Game games_list[] = { { "game", game } };

    
    printf("To choice game input game number\n");
    
    for (int i = 0; i < sizeof(games_list)/sizeof(games_list[0]); i++) {
        printf("\t%d: %s\n", i + 1, games_list[i].game_name);
    }
   
    printf("%s\n", games_list[0].game_moves.hod);

    //printf("%d\n", game[0].cord_x);

    /*
    printf("\t0: Return back\n");
    while (printf(">"),
        fflush(stdin),
        scanf("%d", &k) != 1)
        k = -1;

    if (k == 0)
        return;
    else
        printf("%s\n", games_list[k - 1].game_moves.hod);
        game_menu(&games_list[k - 1].game_moves);
        */
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

