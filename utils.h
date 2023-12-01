#ifndef BOGGLE_UTILS_H
#define BOGGLE_UTILS_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define MAX_GRID_SIZE 1000
#define MAX_WORD_SIZE 1000
#define RED "\033[0;31m"
#define RESET "\033[0m"

void parse_args(int argc, char **argv, char *grid, char *word, int *size);
bool search_word(char *grid, int size, const char *word);
void display_grid(char *grid, int size);
void uppercase_word_in_grid(char *grid, const int *path, int path_length);
void reset_grid_to_lowercase(char *grid, int size);
bool dfs(char *grid, int size, const char *word, int x, int y, int word_index, int *visited, int *path);

#endif //BOGGLE_UTILS_H
