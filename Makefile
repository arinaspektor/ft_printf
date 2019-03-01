
NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
H_DIR = includes
SRC_DIR = srcs
OBJ_DIR = temp

SRC = ft_printf.c ft_strchr.c ft_strlen.c ft_atoi.c ft_strcmp.c ft_itoa_base.c \
	ft_nbr_len.c parse_spc.c parse_flags.c ft_get_nbr.c ft_get_arg.c \
	ft_print_arg.c handle_wchar.c

SRCS = $(addprefix $(SRC_DIR)/,$(SRC))

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $@ $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p temp
		@$(CC) $(FLAGS) -I $(H_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
