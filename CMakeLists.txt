cmake_minimum_required(VERSION 3.11)
project("Chess")

#enable_testing()

SET(SRCS
	Chess/source/Allocate.c
	Chess/source/CheckMate.c
	Chess/source/Figures.c
	Chess/source/Files_functions.c
	Chess/source/Game_menu_functions.c
	Chess/source/Init.c
	Chess/source/Main.c
	Chess/source/Main_Moves.c
	Chess/source/Menu.c
	Chess/source/Moves.c
	Chess/source/MovesCheck.c
)

add_library(clib STATIC ${SRCS})
target_include_directories(clib PUBLIC "Chess/includes")

add_executable(Chess Chess/source/Main.c)
target_link_libraries(Chess clib)
