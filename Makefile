NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror 

SRCS        = push_swap.c \
              Helper_functions/checking.c \
              Helper_functions/ft_split.c \
              Helper_functions/finding.c \
              Helper_functions/linked_list.c \
              Helper_functions/sorting.c \
              Sort_algorithms/sort_three.c \
              Sort_algorithms/sort_five.c \
              Sort_algorithms/sort_n_items.c \
              Operations/push_operations.c \
              Operations/swap_operations.c \
              Operations/rotate_operations.c \
              Operations/reverse_rotate_operations.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re