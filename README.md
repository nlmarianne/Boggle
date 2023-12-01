# Boggle
## Description
Boggle is a game that is made up of a grid of arranged letters among ‘abcdefghijklmnopqrstuvwxyz’. The
goal is to find words within this grid. In order to validate a word, the letters must be side to side to one
another.
## Compilation
- `make`: Compiles the project.
- `make re`: Re-compiles the project.
- `make clean`: Removes object files.
- `make fclean`: Cleans all compiled files.
## Usage
Run the program with the following command:
`./boggle -g GRID [-s SIZE] [-w WORD]`
- `-s SIZE`: Sets the size of the grid's side (default is 4).
- `-g GRID`: Specifies a hard-coded grid (mandatory).
- `-w WORD`: Specifies the word to search for in the grid.
You can enter a word to search while programm is running or enter 'quit' to exit.
## Usage example
```
> ./boggle -g "asdsrtfjn" -w "wjd"
The word "wjd" is not in the grid. Try again.
+++++++++
| a s d |
| s r t |
| f j n |
+++++++++
Enter a word to search (or 'quit' to exit): sr
+++++++++
| a S d |
| s R t |
| f j n |
+++++++++
The word "sr" is found in the grid!
+++++++++
| a s d |
| s r t |
| f j n |
+++++++++
Enter a word to search (or 'quit' to exit): quit
```
