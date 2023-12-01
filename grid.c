#include "utils.h"

void display_grid(char *grid, int size)
{
    for (int i = 0; i < size * 2 + 3; i++)
        printf("+");

    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("| ");
        for (int j = 0; j < size; j++)
        {
            if (grid[i * size + j] >= 'A' && grid[i * size + j] <= 'Z')
            {
                printf("%s%c%s ", RED, grid[i * size + j], RESET);
            }
            else
            {
                printf("%c ", grid[i * size + j]);
            }
        }
        printf("|\n");
    }
    for (int i = 0; i < size * 2 + 3; i++)
        printf("+");

    printf("\n");
}

void uppercase_word_in_grid(char *grid, const int *path, int path_length)
{
    for (int i = 0; i < path_length; i++)
        grid[path[i]] = toupper(grid[path[i]]);
}

void reset_grid_to_lowercase(char *grid, int size)
{
    for (int i = 0; i < size * size; i++)
        grid[i] = tolower(grid[i]);
}