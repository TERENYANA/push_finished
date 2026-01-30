NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       parsing/parser.c \
       parsing/errors.c \
       stack/init_stack.c \
       stack/stack_utils.c \
       operations/push.c \
       operations/swap.c \
       operations/rotate.c \
       operations/reverse.c \
       algorithm/turk.c \
       algorithm/sort_small.c \
       algorithm/targets.c \
       algorithm/costs.c \
       algorithm/execute.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I includes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re