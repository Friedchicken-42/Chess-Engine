#include <stdio.h>

#include "board.h"
#include "engine.h"

int main(int argc, char const *argv[]) {
    char *board;
    board = create_board();
    print_board(board);

    Pos moves[100], current;
    char i;
    char n_moves = 0;
    current.x = 1;
    current.y = 1;

    // void (*ruleset[100])(char *, Pos, Pos, char *);
    RULE ruleset[100];
    uint total_ruleset;
    total_ruleset = load_rulesets(ruleset);
    printf("total_ruleset: %d\n", total_ruleset);

    for (i = 0; i < total_ruleset; i++) {
        printf("rule %d:\t", i);
        ruleset[i](NULL, current, current, NULL);
    }

    // calculate_moves(board, current, ruleset, moves, &n_moves);
    // printf("%d\n", n_moves);
    // for (i = 0; i < n_moves; i++) {
    //     printf("%d %d\n", moves[i].y, moves[i].x);
    // }
    return 0;
}
