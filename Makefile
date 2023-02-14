##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile create binary for antman and giantman
##

all:
			make -C lib/
			make -C antman/
			make -C giantman/

clean:
			make clean -C lib/
			make clean -C antman/
			make clean -C giantman/

fclean:		clean
			make fclean -C lib/
			make fclean -C antman/
			make fclean -C giantman/

re:			fclean all
