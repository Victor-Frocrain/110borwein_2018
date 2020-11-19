##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	sources/main.c			\
		sources/borwein.c		\
		sources/compute_integrals.c	\

OBJ	=	$(SRC:%.c=%.o)

NAME	=	110borwein

CFLAGS	=	-I ./include/ -W

CC	=	gcc

LIB	=	-L lib/my/ -lgnl -lm

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	make -C lib/my/ clean
	rm -f $(OBJ)

fclean:		clean
	make -C lib/my/ fclean
	rm -f $(NAME)

re:	fclean all
	make -C lib/my/ re
