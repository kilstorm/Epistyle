##
## EPITECH PROJECT, 2017
## my_printf
## File description:
##	__DESCRIPTION__
##

C = gcc

NAME = libmy.a

FLAGS = -Wall -Wextra

HEADER = ../include/

LIBFILES = $(SRC:.c=.o)

SRC = my_atoi.c \
	  my_bzero.c \
	  my_memchr.c \
	  my_memcpy.c \
	  my_memset.c \
	  my_pow.c \
	  my_strchr.c \
	  my_strchri.c \
	  my_strlen.c \
	  my_strncmp.c \
	  my_wcharlen.c \
	  my_wstrlen.c

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC) -I $(HEADER)
	@ar rc $(NAME) $(LIBFILES)
	@ranlib $(NAME)

clean:
	@rm -f $(LIBFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
