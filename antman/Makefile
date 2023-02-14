##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile create binary for antman
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	antman

CFLAGS	=	-I./../include -g3

all:		$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ) -L./../lib/ -lmy

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
