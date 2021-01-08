#include "engine.h"

EXPORT char rule(char *board, Pos curr, Pos *moves, char *offset) {
    uint i, stopped;
    Pos direction[4] = {{-1, -1}, {1, -1}, {1, 1}, {-1, 1}};
    Pos position;

    if ((board[curr.y * 8 + curr.x] & PIECE) == BISHOP || (board[curr.y * 8 + curr.x] & PIECE) == QUEEN) {
        for (i = 0; i < 4; i++) {
            position.x = curr.x + direction[i].x;
            position.y = curr.y + direction[i].y;
            stopped = 0;
            while (check_position(board, position) == 0 && !stopped) {
                if ((board[position.y * 8 + position.x] & FULL) == (board[curr.y * 8 + curr.x] & FULL)) {
                    stopped = 1;
                } else {
                    position.piece_eat = board[position.y * 8 + position.x];
                    if (board[position.y * 8 + position.x] != EMPTY) {
                        stopped = 1;
                    }
                    memcpy(&moves[*offset], &position, sizeof(Pos));
                    (*offset)++;
                    position.x += direction[i].x;
                    position.y += direction[i].y;
                }
            }
        }
    }

    return 0;
}