#include <stdio.h>

#include "engine.h"

EXPORT char rule(char *board, Pos curr, Pos *moves, char *offset) {
    printf("pawn_eat\n");  // debug print
    return 0;

    uint position;
    position = curr.y * 8 + curr.x;

    uint side_pos[2] = {-1, 1};
    uint i;
    Pos p;

    if ((board[position] & PIECE) == PAWN) {
        if (board[position] & WHITE) {
            p.y = curr.y - 1;
            for (i = 0; i < 2; i++) {
                p.x = curr.x + side_pos[i];
                if (check_position(board, p) == 0 && board[p.y * 8 + p.x] & BLACK) {
                    memcpy(&moves[*offset], &p, sizeof(Pos));
                }
            }
        } else if (board[position] & BLACK) {
        }
    }
    return 0;
}