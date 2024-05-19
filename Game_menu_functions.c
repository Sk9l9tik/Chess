#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Allocate.h"

#include "Init.h"
#include "Moves.h"

#include "Menu.h"
#include "Game_menu_functions.h"

void new_game(Moves** game, int* count){


    Desk desk;
    init(desk);

    printDesk(desk);

    //char hod[7];

    for (int i = 0; ; i++) {
        allocate_one(game, count);

        while (printf("Enter turn>"), fflush(stdin), scanf("%s", (*game)[i].hod) != 1, initMoves(&(*game)[i]), (Move(desk, &(*game)[i]) == 1)) { //(Move(desk, &(*game)[i]) == 1 && (*game)[i].hod[0] != '0') || Move(desk, &(*game)[i]) != 1
            if ((*game)[i].hod[0] == '0') {
                free_one(game, count+1);
                return;
            }
            printf("Illegal turn: %s !!!\n\n", (*game)[i].hod);
            printDesk(desk);
        }
        printDesk(desk);
    }
    //return *game;
}

void print_game(Moves* game, int turn, int* size) {

    Desk desk;
    init(desk);

    if (turn == -1) {

        printDesk(desk);
        for (int i = 0; i <= *size && game[i].hod[0] != '0'; i++) {
            printf("Current turn: %s\n", game[i].hod);
            Move(desk, &game[i]);
            printDesk(desk);
        }
    }
    else {
        for (int i = 0; i != turn && i <= *size; i++) {
            Move(desk, &game[i]);
            printf("%d\n", i);
        }
        printDesk(desk);
    }

    //printf("%c %d\n", desk[4][4].figure, desk[4][4].color);
}

void* insert_turn(Moves** game, int* size) {                                     // allocate new memory!!!
    int number;
    
    printf("Number turn>");
    scanf("%d", &number);

    if (number > *size) {
        printf("Error number!!1\n");
        return *game;
    }

    //printf("%s %s\n", (*game)[*size - 2].hod, (*game)[*size-1].hod);

    allocate_one(game, size);

    for (int i = 0; i <= *size; i++) {
        printf("%s ", (*game)[i].hod);
    }
    printf("\n");

    memmove(*game + number + 1, *game + number, sizeof((*game)[0]) * ((*size) - number));

    for (int i = 0; i < *size; i++) {
        printf("%s ", (*game)[i].hod);
    }
    printf("\n");

    printf("Enter turn>");
    scanf("%s", (*game)[number].hod);
    initMoves(&(*game)[number]);

    for (int i = 0; i <= *size; i++) {
        printf("%s ", (*game)[i].hod);
    }
    printf("\n");

    return *game;
}
void* delete_turn(Moves** game, int* size, int flag) {
    int number = flag;
    if (flag == 0) {
        printf("Number turn>");
        scanf("%d", &number);
    }


    if (number > *size || *size == 0) {
        printf("Error number!!1\n");
        return *game;
    }


    memmove(*game + number - 1, *game + number, sizeof((*game)[0]) * ((*size) - number) + 1);

    if(*size >= 1)
        free_one(game, size);
    else 
        strcpy((*game)[*size].hod, "0");

    return *game;
}
void modify_turn(Moves** game, int* size) {
    int number;
    printf("Number turn>");
    scanf("%d", &number);
    if (number > *size) {
        printf("Error number!!1\n");
        return;
    }
    printf("Enter turn>");
    scanf("%s", (*game)[number].hod);
    initMoves(&(*game)[number]);
}

