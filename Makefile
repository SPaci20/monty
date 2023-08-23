CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99
SRC = main.c push.c pall.c
OBJ = $(SRC:.c=.o)
EXEC = monty

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all
