#if !defined(BOARD)
#define BOARD

#include <stdio.h>
#include <stdlib.h>

#include "engine.h"

char *create_board();
void print_board(char *board);
void print_avaiable(char *board, Pos *moves, uint n_moves);

#endif
