#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>


//#include "Console_Resize.h"
#include "../includes/Menu.h"
#include "../includes/Game_menu_functions.h"
#include "../includes/CheckMate.h"

#include "../includes/Desk.h"
#include "../includes/Init.h"
#include "../includes/Figures.h"
#include "../includes/Moves.h"


int main() {
    setlocale(LC_ALL, "");

    main_menu(); 

    return 0;
}
