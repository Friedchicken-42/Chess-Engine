#include "board.h"

char *create_board() {
    char *board = (char *)malloc(64);
    if (board == NULL) return NULL;

    uint i, j, p, px;
    for (i = 0; i < 8; i++) {
        switch (i) {
            case 0:
            case 1:
                p = BLACK;
                break;
            case 6:
            case 7:
                p = WHITE;
                break;
            default:
                p = EMPTY;
                break;
        }
        for (j = 0; j < 8; j++) {
            px = p;
            if (i == 0 || i == 7) {
                switch (j) {
                    case 0:
                    case 7:
                        px |= ROOK;
                        break;
                    case 1:
                    case 6:
                        px |= KNIGHT;
                        break;
                    case 2:
                    case 5:
                        px |= BISHOP;
                        break;
                    case 3:
                        px |= QUEEN;
                        break;
                    case 4:
                        px |= KING;
                        break;
                    default:
                        break;
                }
            } else if (i == 1 || i == 6) {
                px |= PAWN;
            }
            board[i * 8 + j] = px;
        }
    }
    return board;
}

void print_board(char *board) {
    uint i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%2d ", board[i * 8 + j] & PIECE);
        }
        printf("\n");
    }
}