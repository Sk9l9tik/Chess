#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "Init.h"
#include "Moves.h"

#include "Menu.h"
#include "Game_menu_functions.h"

int new_game(Moves* game){

    int count = 0;

    Desk desk;
    init(desk);

    printDesk(desk);

    //char hod[7];

    for (int i = 0; i < MAXTURNS; i++) {
        printf("Enter turn>");
        scanf("%s", game[i].hod);
        initMoves(&game[i]);
        Move(desk, &game[i]);
        printDesk(desk);
        count++;
    }
    return count;
}

void print_game(Moves* game, int turn, int* size) {

    Desk desk;
    init(desk);

    if (turn == -1) {

        printDesk(desk);
        for (int i = 0; i <= *size; i++) {
            printf("Current turn: %s\n", game[i].hod);
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

