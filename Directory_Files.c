#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "Desk.h"

#define EXT ".txt"
#define ELEN 4

int list_of_games_files(Game* games_list) {
    DIR* dp = opendir("./SavedGames/");
    if (!dp) {
        fprintf(stderr, "Can't open current directory!\n");
        return 1;
    }

    struct dirent* de;
    while ((de = readdir(dp))) {
        size_t nlen = strlen(de->d_name);
        if (nlen > ELEN && strcmp((de->d_name) + nlen - ELEN, EXT) == 0)
            printf("%s\n", de->d_name);
    }

    closedir(dp);

    return 0;
}