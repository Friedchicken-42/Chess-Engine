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

char check_position(char *board, Pos p) {
    if (p.x < 0 || p.x > 7) return 1;
    if (p.y < 0 || p.y > 7) return 2;
    return 0;
}