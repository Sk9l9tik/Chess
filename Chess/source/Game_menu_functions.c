#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/Allocate.h"

#include "../includes/Init.h"
#include "../includes/Moves.h"
#include "../includes/CheckMate.h"

#include "../includes/Menu.h"
#include "../includes/Game_menu_functions.h"

//void new_game(Moves** game, int* count) {
//
//
//    Desk desk;
//    init(desk);
//
//    KingsPos kingspos;
//    initKingsPos(&kingspos);
//
//
//    //printDesk(desk);
//
//    //char hod[7];
//
//    for (int i = 0; ; i++) {
//        allocate_one(game, count);
//        // remake check and add "Check func"
//        // on Check you can move only king or any figure to prevent Check
//
//        char color_turn = 1; // 1 - white, 0 - black
//        int flag = 0;
//
//        while (1) {
//
//            if (flag == 2) {
//                printf("Check !!!!\n");
//                printDesk(desk);
//                while (printf("Enter turn>"), fflush(stdin), scanf("%s", (*game)[i].hod) != 1, initMoves(&(*game)[i]), Move(desk, &(*game)[i], &kingspos) != 0 || Check(desk, &(*game)[i], &kingspos) == 2) { //(Move(desk, &(*game)[i]) == 1 && (*game)[i].hod[0] != '0') || Move(desk, &(*game)[i]) != 1  
//                    printf("Check !!! Illegal turn: %s !!!\n", (*game)[i].hod);
//                    printDesk(desk);
//                }
//                //kingspos.Check_f = 0;
//
//            }
//            else {
//                printDesk(desk);
//                printf("Enter turn>");
//                fflush(stdin);
//
//                if (scanf("%s", (*game)[i].hod) != 1) {
//                    printf("Illegal turn: %s !!!\n\n", (*game)[i].hod);
//                    printDesk(desk);
//                    continue;
//                }
//
//                initMoves(&(*game)[i]);
//
//                flag = Move(desk, &(*game)[i], &kingspos);
//                if (flag != 0) {
//                    printf("Illegal turn: %s !!!\n\n", (*game)[i].hod);
//                    printDesk(desk);
//                    continue;
//                }
//            }
//
//            if ((*game)[i].hod[0] == '0') {
//                free_one(game, count + 1);
//                return;
//            }
//
//            //printDesk(desk);
//            flag = Check(desk, (*game)[i].hod, &kingspos);
//        }
//
//    }
//    //return *game;
//}


void new_game(Moves** game, int* count){

    //system("cls");

    Desk desk;
    init(desk);

    KingsPos kingspos;
    initKingsPos(&kingspos);


    //printDesk(desk);

    //char hod[7];
    kingspos.color_turn = 1; // 1 - white, 0 - black
    int flag = 0, mate_flag = 0;
    for (int i = 0; ; i++) {
        
        if (i % 2 == 0) kingspos.color_turn = 1;
        else kingspos.color_turn = 0;

        allocate_one(game, count);

        //printf("%d - %d\n", kingspos.color, kingspos.color_turn);


        flag = Check(desk, (*game)[i].hod, &kingspos);


        mate_flag = Mate(desk, &kingspos, kingspos.color_turn);

        if (mate_flag == 2) {
            if (kingspos.Mate_color == 0) {
                printf("End Game. Win White!!!\n");
                free_one(game, count);
                printDesk(desk);
                (*game)[*count - 1].hod[5] = '#';
                (*game)[*count - 1].hod[6] = 0;
                return;
            }
            else {
                printf("End Game. Win Black!!!\n");
                free_one(game, count);
                printDesk(desk);
                (*game)[*count - 1].hod[5] = '#';
                (*game)[*count - 1].hod[6] = 0;
                return;
            }
        }
        else if (mate_flag == 1) {
            printf("End Game. Draw!!!\n");
            free_one(game, count);
            printDesk(desk);
            (*game)[*count - 1].hod[5] = '=';
            (*game)[*count - 1].hod[6] = 0;
            return;
        }


        if (flag == 2) {
            system("cls");
            printf("Check !!!!\n");
            printDesk(desk);
            while (printf("Enter turn>"), fflush(stdin), scanf("%s", (*game)[i].hod) != 1, initMoves(&(*game)[i], kingspos.color_turn), Move(desk, &(*game)[i], &kingspos) != 0 || Check(desk, &(*game)[i], &kingspos) == 2) { //(Move(desk, &(*game)[i]) == 1 && (*game)[i].hod[0] != '0') || Move(desk, &(*game)[i]) != 1  
                printDesk(desk);
                printf("Check !!! Illegal turn: %s !!!\n\n", (*game)[i].hod);
                printf("Current color turn: %s\n", kingspos.color_turn == 1 ? "WHITE" : "BLACK");
            }
        }
        else {
            system("cls");
            printDesk(desk);
            if(i != 0)
                printf("Last turn: %s\n", (*game)[i-1].hod);
            while (printf("Current color turn: %s\n", kingspos.color_turn == 1 ? "WHITE" : "BLACK"), printf("\nEnter turn>"), fflush(stdin), scanf("%s", (*game)[i].hod) != 1, initMoves(&(*game)[i], kingspos.color_turn), (desk[(*game)[i].cord_y][(*game)[i].cord_x].color != kingspos.color_turn) ? 1 : 0 || Move(desk, &(*game)[i], &kingspos) != 0) { //(Move(desk, &(*game)[i]) == 1 && (*game)[i].hod[0] != '0') || Move(desk, &(*game)[i]) != 1  
                if ((*game)[i].hod[0] == '0') {
                    free_one(game, count);
                    return;
                }
                if (kingspos.Check_f == 2 ) { // && kingspos.color == color_turn
                    system("cls");
                    printDesk(desk);
                    printf("Check !!! Illegal turn: %s !!!\n", (*game)[i].hod);
                    printf("Last turn: %s\n", (*game)[i - 1].hod);
                    //printf("Current color turn: %s\n", kingspos.color_turn == 1 ? "WHITE" : "BLACK");
                }
                else {
                    system("cls");
                    printDesk(desk);
                    printf("Illegal turn: %s !!!\n", (*game)[i].hod);
                    printf("Last turn: %s\n", (*game)[i - 1].hod);
                    //printf("Current color turn: %s\n", kingspos.color_turn == 1 ? "WHITE" : "BLACK");
                }

            }
        }


        // remake check and add "Check func"
        // on Check you can move only king or any figure to prevent Check

    }
    //return *game;
}


void print_game(Moves* game, KingsPos* kingspos, int turn, int* size) {

    Desk desk;
    init(desk);

    if (turn == -1) {

        printDesk(desk);
        for (int i = 0; i < *size && game[i].hod[0] != '0'; i++) {
            printf("Current turn: %s\n", game[i].hod);
            Move(desk, &game[i], kingspos);
            printDesk(desk);
        }
    }
    else {
        for (int i = 0; i != turn && i <= *size; i++) {
            Move(desk, &game[i], kingspos);
            printf("%d\n", i);
        }
        printDesk(desk);
    }

    //printf("%c %d\n", desk[4][4].figure, desk[4][4].color);
}

void* insert_turn(Moves** game, int color_turn, int* size) {                                     // allocate new memory!!!
    int number;
    
    printf("Number turn>");
    scanf("%d", &number);

    if (number > *size) {
        printf("Error number!!1\n");
        return *game;
    }

    //printf("%s %s\n", (*game)[*size - 2].hod, (*game)[*size-1].hod);

    allocate_one(game, size);

    //for (int i = 0; i <= *size; i++) {
    //    printf("%s ", (*game)[i].hod);
    //}
    //printf("\n");

    memmove(*game + number + 1, *game + number, sizeof((*game)[0]) * ((*size) - number));

    for (int i = 0; i < *size; i++) {
        printf("%s ", (*game)[i].hod);
    }
    printf("\n");

    printf("Enter turn>");
    scanf("%s", (*game)[number].hod);
    initMoves(&(*game)[number], color_turn);

    //for (int i = 0; i <= *size; i++) {
    //    printf("%s ", (*game)[i].hod);
    //}
    //printf("\n");

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
void modify_turn(Moves** game, int color_turn, int* size) {
    int number;
    printf("Number turn>");
    scanf("%d", &number);
    if (number > *size) {
        printf("Error number!!1\n");
        return;
    }
    printf("Enter turn>");
    scanf("%s", (*game)[number].hod);
    initMoves(&(*game)[number], color_turn);
}

