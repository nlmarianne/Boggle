#include "utils.h"

void parse_args(int argc, char **argv, char *grid, char *word, int *size)
{
    int opt, grid_is_present = 0, size_is_present = 0;
    while ((opt = getopt(argc, argv, "g:s:w:")) != -1)
    {
        switch (opt)
        {
            case 'g':
                if (strlen(optarg) >= MAX_GRID_SIZE)
                {
                    fprintf(stderr, "Error: grid size exceeds maximum (%d).\n", MAX_GRID_SIZE);
                    exit(84);
                }
                strncpy(grid, optarg, MAX_GRID_SIZE);
                grid_is_present = 1;
                break;
            case 's':
                *size = atoi(optarg);
                if ((*size) * (*size) > MAX_GRID_SIZE)
                {
                    fprintf(stderr, "Error: grid size exceeds maximum (%d).\n", MAX_GRID_SIZE);
                    exit(84);
                }
                size_is_present = 1;
                break;
            case 'w':
                if (strlen(optarg) >= MAX_WORD_SIZE)
                {
                    fprintf(stderr, "Error: word size exceeds maximum (%d).\n", MAX_WORD_SIZE);
                    exit(84);
                }
                strncpy(word, optarg, MAX_WORD_SIZE);
                break;
            default:
                fprintf(stderr, "Usage: %s -g GRID [-s SIZE] [-w WORD]\n", argv[0]);
                exit(84);
        }
    }

    if (!grid_is_present)
    {
        fprintf(stderr, "Error: grid (-g) is mandatory.\n");
        exit(84);
    }

    if (!size_is_present)
    {
        *size = (int)sqrt((double)strlen(grid));
    }

    if ((*size) * (*size) != strlen(grid))
    {
        fprintf(stderr, "Error: grid does not contain the correct number of characters.\n");
        exit(84);
    }
}
