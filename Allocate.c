#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Allocate.h"


void* allocate_one(Moves** game, int* size) {
    Moves* new_game; // create tmp pointer
    (*size)++; // raise size
    new_game = realloc(*game, (*size) * sizeof(Moves)); // reallocate memory with new size
    if (!new_game){ // check nullprt
        printf("Error malloc new turn!!!!!!\n");
        return NULL;
    }
    //strcpy((*game)[*size].hod, "0"); // end game
    *game = new_game; // assigment new pointer
    
    return *game; // return new ptr
}

void* free_one(Moves** game, int* size){
    Moves* new_game; // create tmp pointer
    void* t; // create tmp pointer
    (*size)--;
    //memmove(*game + *size, *game + *size +1 , sizeof((*game)[0]) * ((*size) - *size)); // move data
    new_game = realloc(*game, (*size) * sizeof(Moves)); // reallocate memory with new size
    t = new_game; // check nullprt
    if (!t) {
        printf("Error malloc new turn!!!!!!\n");
        (*size)++;
        return *game;
    }
    
    *game = new_game; // assigment new pointer

    //strcpy((*game)[*size].hod, "0");
    return *game; // return new ptr
}