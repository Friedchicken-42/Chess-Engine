#include "engine.h"

EXPORT char rule(char *board, Pos curr, Pos *moves, char *offset) {
    if (board[curr.y * 8 + curr.x] & 1) {
        curr.y -= 1;
    } else if (board[curr.y * 8 + curr.x] & 2) {
        curr.y += 1;
    }
    if (check_position(board, curr) == 0 && (board[curr.y * 8 + curr.x] & 3) == 0) {
        moves[*offset].x = curr.x;
        moves[*offset].y = curr.y;
        (*offset)++;
    }

    return 0;
}