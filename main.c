#include <stdio.h>

#include "board.h"
#include "engine.h"

int main(int argc, char const *argv[]) {
    char *board;
    Pos *moves, current;
    char i;
    char n_moves = 0;
    current.x = 3;
    current.y = 3;

    board = create_board();
    print_board(board);
    board[current.y * 8 + current.x] = WHITE | QUEEN;

    // void (*ruleset[100])(char *, Pos, Pos, char *);
    RULE ruleset[100];
    uint total_ruleset;
    total_ruleset = load_rulesets(ruleset);
    printf("loaded ruleset: %d\n", total_ruleset);

    moves = calculate_moves(board, current, ruleset, total_ruleset, &n_moves);
    printf("possible moves: %d\n", n_moves);

    for (i = 0; i < n_moves; i++) {
        board[moves[i].y * 8 + moves[i].x] = AVAIABLE;
        printf("\t(%d %d) eat: [%2d]\n", moves[i].x, moves[i].y, moves[i].piece_eat & PIECE);
    }
    print_avaiable(board, moves, n_moves);

    return 0;
}
