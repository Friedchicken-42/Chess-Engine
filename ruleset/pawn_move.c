#include <stdio.h>

#include "engine.h"

EXPORT char rule(char *board, Pos curr, Pos *moves, char *offset) {
    printf("pawn_move\n");  // debug print
    return 0;

    uint position;
    position = curr.y * 8 + curr.x;

    if ((board[position] & PIECE) == PAWN) {
        if (board[position] & WHITE) {
            curr.y -= 1;
        } else if (board[position] & BLACK) {
            curr.y += 1;
        }
        if (check_position(board, curr) == 0 && (board[curr.y * 8 + curr.x] & FULL) == 0) {
            moves[*offset].x = curr.x;
            moves[*offset].y = curr.y;
            (*offset)++;
        }
    }

    return 0;
}