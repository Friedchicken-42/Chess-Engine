#include "engine.h"

EXPORT char rule(char *board, Pos curr, Pos *moves, char *offset) {
    uint position;
    position = curr.y * 8 + curr.x;
    curr.piece_eat = EMPTY;

    if ((board[position] & PIECE) == PAWN) {
        if (board[position] & WHITE) {
            curr.y -= 1;
        } else if (board[position] & BLACK) {
            curr.y += 1;
        }
        if (check_position(board, curr) == 0 && (board[curr.y * 8 + curr.x] & FULL) == 0) {
            memcpy(&moves[*offset], &curr, sizeof(Pos));
            (*offset)++;
        }
    }

    return 0;
}