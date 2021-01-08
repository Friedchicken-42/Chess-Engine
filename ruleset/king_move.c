#include "engine.h"

EXPORT char rule(char *board, Pos curr, Pos *moves, char *offset) {
    uint i;
    Pos direction[8] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
    Pos next;

    if ((board[curr.y * 8 + curr.x] & PIECE) == KING) {
        for (i = 0; i < 8; i++) {
            next.x = curr.x + direction[i].x;
            next.y = curr.y + direction[i].y;
            if (check_position(board, next) == 0 && (board[next.y * 8 + next.x] & FULL) != (board[curr.y * 8 + curr.x] & FULL)) {
                next.piece_eat = board[next.y * 8 + next.x];
                memcpy(&moves[*offset], &next, sizeof(Pos));
                (*offset)++;
            }
        }
    }
    return 0;
}