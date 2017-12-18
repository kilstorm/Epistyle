##
## EPITECH PROJECT, 2017
## Push_swap
## File description:
## Makefile push_swap
##

NAME		= codingstyle

CC		= clang

RM		= rm -rf

SRC		= main.c	\
		  Layout.c	\
		  utils.c	\
		  Layout2.c

OBJ		= $(addprefix src/, $(SRC:.c=.o))
OBJS 		= $(addprefix obj/, $(SRC:.c=.o))

LIBS	= -Llib/my -lmy
LIB	= lib/my/libmy.a
LIB2 	= lib/my/
MAKELIB	= make -C lib/my/

CFLAGS		= -Weverything
CFLAGS		+= -Iinclude/		\
		   -Ilib/my/include/
CFLAGS	+= $(LIBS)

all: $(LIB) $(NAME)

$(NAME):	$(OBJ)
		$(CC) -g $(OBJ) -o $(NAME) $(CFLAGS)
		mv $(OBJ) ./obj
$(LIB):
		$(MAKELIB)

clean:
		$(RM) $(OBJS)
		$(RM) $(NAME)
		@make clean -C $(LIB2)

fclean:		clean
		@make fclean -C $(LIB2)

re:		fclean all

.PHONY:		all clean fclean re
