#include "engine.h"

EXPORT char rule(char *board, Pos curr, Pos *moves, char *offset) {
    uint position;
    position = curr.y * 8 + curr.x;

    uint side_pos[2] = {-1, 1};
    uint i;
    Pos p;

    if ((board[position] & PIECE) == PAWN) {
        for (i = 0; i < 2; i++) {
            if (board[position] & WHITE) {
                p.y = curr.y - 1;
            } else if (board[position] & BLACK) {
                p.y = curr.y + 1;
            }
            p.x = curr.x + side_pos[i];
            if (check_position(board, p) == 0) {
                if (board[position] & WHITE && board[p.y * 8 + p.x] & BLACK || board[position] & BLACK && board[p.y * 8 + p.x] & WHITE) {
                    memcpy(&moves[*offset], &p, sizeof(Pos));
                    (*offset)++;
                }
            }
        }
    }
    return 0;
}