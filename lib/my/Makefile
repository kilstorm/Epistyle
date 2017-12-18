##
## EPITECH PROJECT, 2017
## my_printf
## File description:
##	__DESCRIPTION__
##

C = gcc

NAME = libmy.a

FLAGS = -Wall -Wextra

LIB = ./lib/my

DIR_S = src

DIR_O = obj

HEADER = ./include

SOURCES = my_printf.c \
		  parse_arguments.c \
		  hnd_nbr.c \
		  hnd_str.c \
		  bonus_functions.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB)
	@cp ./lib/my/libmy.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIB)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB)

re: fclean all
