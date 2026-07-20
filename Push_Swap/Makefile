NAME = push_swap

SRCS = push_swap.c check_options.c choose_option.c chunk_based.c \
		disorder.c ft_atol.c ft_index.c ft_radix.c init_ops.c \
		init_stack.c push.c reverse.c rotate.c selection_sort.c swap.c \
		ft_print_lower_hex.c ft_print_ptr.c ft_print_unsigned.c ft_print_upper_hex.c \
		ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c \

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
