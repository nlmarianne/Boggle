CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
INCLUDES = -I.
LFLAGS = -L.
LIBS = -lm
SRCS = main.c args_parser.c word_finder.c grid.c
OBJS = $(SRCS:.c=.o)
MAIN = boggle

.PHONY: clean fclean re all

all: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	rm -f *.o *~

fclean: clean
	rm -f $(MAIN)

re: fclean all