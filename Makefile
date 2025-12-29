NAME = push_swap
CHECKER = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

COMMON_SRCS = checking.c \
              ft_split.c \
              finding.c \
              linked_list.c \
              sorting.c \
              push_operations.c \
              swap_operations.c \
              rotate_operations.c \
              reverse_rotate_operations.c \
              sort_three.c \
              sort_five.c \
              sort_n_items.c

MANDATORY_SRCS = push_swap.c
BONUS_ONLY_SRCS = checker_bonus.c \
                  get_next_line.c \
                  get_next_line_utils.c

COMMON_OBJS     = $(COMMON_SRCS:.c=.o)
MANDATORY_OBJS  = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS      = $(BONUS_ONLY_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(COMMON_OBJS) $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(MANDATORY_OBJS) -o $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(COMMON_OBJS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(BONUS_OBJS) -o $(CHECKER)

clean:
	rm -f $(COMMON_OBJS) $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re