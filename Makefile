# ==== Compiler ====
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
# CFLAGS	= -g -Wall -Wextra -Werror

# ==== Project ====
NAME	= push_swap

# ==== Source Files ====
SRCS	= main.c radix_sort.c stack_ops.c stack_utils.c ranks_utils.c error.c free.c small_sort.c ft_strcmp.c ft_atoi.c
OBJS	= $(SRCS:.c=.o)

# ==== Includes ====
INCLUDES = -I.

# ==== Rules ====

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
