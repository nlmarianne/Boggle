#include "utils.h"

bool search_word(char *grid, int size, const char *word)
{
    int visited[MAX_GRID_SIZE] = {0};
    int path[MAX_GRID_SIZE] = {0};

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (grid[i * size + j] == word[0] && dfs(grid, size, word, i, j, 0, visited, path))
            {
                uppercase_word_in_grid(grid, path, strlen(word));
                return true;
            }
        }
    }

    return false;
}

bool is_valid(int x, int y, int size)
{
    return x >= 0 && x < size && y >= 0 && y < size;
}

bool dfs(char *grid, int size, const char *word, int x, int y, int word_index, int *visited, int *path)
{
    if (word_index == (int)strlen(word))
    {
        return true;
    }

    if (!is_valid(x, y, size) || visited[x * size + y] || grid[x * size + y] != word[word_index])
    {
        return false;
    }

    visited[x * size + y] = 1;
    path[word_index] = x * size + y;

    int xdir[] = {-1, 1, 0, 0};
    int ydir[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++)
    {
        if (dfs(grid, size, word, x + xdir[i], y + ydir[i], word_index + 1, visited, path))
            return true;
    }

    visited[x * size + y] = 0;
    return false;
}