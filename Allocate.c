#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Allocate.h"


void* allocate_one(Moves** game, int* size) {
    Moves* new_game;
    (*size)++;
    new_game = realloc(*game, (*size) * sizeof(Moves));
    if (!new_game)
        printf("Error malloc new turn!!!!!!\n");
    strcpy((*game)[*size].hod, "0");
    *game = new_game;
    
    return *game;
}

void* free_one(Moves** game, int* size){
    Moves* new_game;
    void* t;
    (*size)--;
    memmove(*game + *size, *game + *size +1 , sizeof((*game)[0]) * ((*size) - *size));
    new_game = realloc(*game, (*size) * sizeof(Moves));
    t = new_game;
    if (!t) {
        printf("Error malloc new turn!!!!!!\n");
        (*size)++;
        *game = new_game;
    }
    //strcpy((*game)[*size].hod, "0");
    return *game;
}