##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

SRC = main.c function.c move_up_and_down.c move_right_and_left.c check_for_error_and_end.c

OBJ = main.o function.o move_up_and_down.o move_right_and_left.o check_for_error_and_end.o

CFLAGS = -W -Wall -Wextra

all: compi

compi: $(OBJ)
	gcc $(OBJ) -o my_sokoban -lncurses

$(OBJ): $(SRC)
	gcc $(CFLAGS) -c $(SRC)

clean:
	rm $(OBJ)

fclean:
	rm my_sokoban

re : clean fclean all