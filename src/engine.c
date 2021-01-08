#include "engine.h"

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

char check_position(char *board, Pos p) {
    if (p.x < 0 || p.x > 7) return 1;
    if (p.y < 0 || p.y > 7) return 2;
    return 0;
}

RULE load_ruleset(char filename[1024]) {
    RULE current;

#if defined(_WIN32)
    HMODULE hDll = LoadLibrary(filename);
    if (hDll == NULL) {
        printf(" FileNotFound");
        return NULL;
    }
    current = (RULE)GetProcAddress(hDll, "rule");

#elif defined(__linux__)
#endif
    return current;
}

uint load_rulesets(RULE *ruleset) {
    RULE current_rule;
    uint offset;
    DIR *d;
    struct dirent *ruleset_file;
    char filename[1024];

    offset = 0;

    d = opendir(".dynamic_ruleset");
    if (d == NULL) {
        printf("folder not found\n");
        return 0;
    }

    printf("loading rulesets:\n");

    while ((ruleset_file = readdir(d)) != NULL) {
        if (ruleset_file->d_namlen > 2) {
            strcpy(filename, ".dynamic_ruleset/");
            strcat(filename, ruleset_file->d_name);

            printf("[     ] %s", filename);
            current_rule = load_ruleset(filename);

            if (current_rule != NULL) {
                printf("\r[load ] %s\n", filename);
                ruleset[offset] = current_rule;
                offset++;
            } else {
                printf("\r[error] %s\n", filename);
            }
        }
    }
    return offset;
}

Pos *calculate_moves(char *board, Pos curr, RULE ruleset[100], uint total_ruleset, char *offset) {
    if (board == NULL) return NULL;
    if (board[curr.y * 8 + curr.x] & FULL == 0) return NULL;

    Pos *moves;
    moves = malloc(sizeof(Pos) * 100);

    uint i;

    for (i = 0; i < total_ruleset; i++) {
        ruleset[i](board, curr, moves, offset);
    }

    return moves;
}