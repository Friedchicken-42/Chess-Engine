#include "engine.h"

EXPORT char rule(char *board, Pos curr, Pos *moves, char *offset) {
    uint position;
    position = curr.y * 8 + curr.x;

    /* specify piece type */
    if ((board[position] & PIECE) == PAWN) {
        /*  calculate next position
            check_position(board, next_pos):
                if next_pos is avaiable
                add move to array of possible moves

                    memcpy(&moves[*offset], &next_pos, sizeof(Pos));
                    (*offset)++;

        */
    }
    return 0;
}