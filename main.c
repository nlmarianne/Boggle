#include "utils.h"

int main(int argc, char **argv)
{
    char grid[MAX_GRID_SIZE] = {0};
    int size = 4;
    char word[MAX_WORD_SIZE] = {0};

    parse_args(argc, argv, grid, word, &size);

    while (1)
    {
        if (strlen(word) == 0)
        {
            display_grid(grid, size);
            printf("Enter a word to search (or 'quit' to exit): ");
            if (scanf("%s", word) != 1)
            {
                fprintf(stderr, "Error reading the word.\n");
                continue;
            }
            if (strcmp(word, "quit") == 0)
                return 0;
        }

        if (search_word(grid, size, word))
        {
            display_grid(grid, size);
            printf("The word \"%s\" is found in the grid!\n", word);
            reset_grid_to_lowercase(grid, size);
        }
        else
        {
            printf("The word \"%s\" is not in the grid. Try again.\n", word);
        }
        word[0] = '\0';
    }
}
