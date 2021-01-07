#if !defined(ENGINE)
#define ENGINE

/*
Piece:
    type: pawn = 1, rook = 2, knight = 3, bishop = 4, queen = 5, king = 6
    color: white = 1, black = 2
    cell: empty = 0, full = 1-2
    move: first_move = 0, other = 1

00 0 00 000
*/
typedef struct Position Pos;

struct Position {
    char x;
    char y;
};

#if defined(_WIN32)
#include <windows.h>
#define EXPORT __declspec(dllexport)
typedef char(__cdecl *RULE)(char *, Pos, Pos, char *);

#elif defined(__linux__)
#include <dlfcn.h>
#define EXPORT __attribute__((visibility("default")))
typedef char (*RULE)(char *, Pos, Pos, char *);

#else
#define EXPORT
#endif

typedef unsigned int uint;

enum {
    PAWN = 1,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING,
    PIECE = 7,
    WHITE = 1 << 3,
    BLACK = 1 << 4,
    EMPTY = 0,
    FULL = WHITE | BLACK,
    MOVED = 1 << 5,
} Type;

uint load_rulesets(RULE *ruleset);
char calculate_moves(char *board, Pos curr, void *ruleset, Pos *moves, char *offset);
char check_position(char *board, Pos p);

#endif
