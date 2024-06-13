cmake_minimum_required(VERSION 3.11)
project("Chess")

#enable_testing()

SET(SRCS
	source/Allocate.c
	source/CheckMate.c
	source/Figures.c
	source/Files_functions.c
	source/Game_menu_functions.c
	source/Init.c
	source/Main.c
	source/Main_Moves.c
	source/Menu.c
	source/Moves.c
	source/MovesCheck.c
)

add_library(clib STATIC ${SRCS})
target_include_directories(clib PUBLIC "includes")

add_executable(Chess source/Main.c)
target_link_libraries(Chess clib)
