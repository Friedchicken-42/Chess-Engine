#include "engine.h"

EXPORT char rule(char *board, Pos curr, Pos *moves, char *offset) {
    uint position;
    position = curr.y * 8 + curr.x;

    if ((board[position] & PIECE) == PAWN && (board[position] & MOVED) == 0) {
        if (board[position] & WHITE) {
            curr.y -= 2;
        } else if (board[position] & BLACK) {
            curr.y += 2;
        }
        if (check_position(board, curr) == 0 && (board[curr.y * 8 + curr.x] & FULL) == 0) {
            moves[*offset].x = curr.x;
            moves[*offset].y = curr.y;
            (*offset)++;
        }
    }

    return 0;
}
