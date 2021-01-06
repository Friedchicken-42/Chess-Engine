#include "engine.h"

#include <stdio.h>
#include <stdlib.h>

char check_position(char *board, Pos p) {
    if (p.x < 0 || p.x > 7) return 1;
    if (p.y < 0 || p.y > 7) return 2;
    return 0;
}

void load_rulesets() {
    RULE ruleset[100];
    uint offset;
    offset = 0;

#if defined(_WIN32)
    HMODULE hDll = LoadLibrary(".dynamic_ruleset/pawn_move.dll");
    if (hDll == NULL) return;
    ruleset[0] = (RULE)GetProcAddress(hDll, "rule");

#elif defined(__linux__)

#endif
}

char calculate_moves(char *board, Pos curr, void *ruleset, Pos *moves, char *offset) {
    if (board == NULL) return 0;
    if (board[curr.y * 8 + curr.x] & FULL == 0) return 0;

    switch (board[curr.y * 8 + curr.x] & PIECE) {
        case PAWN:
            // pawn_move(board, curr, moves, offset);
            // pawn_first_move(board, curr, moves, offset);
            // pawn_eat(board, curr, moves, offset);
            break;

        default:
            break;
    }
    return 1;
}