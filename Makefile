# ==== Compiler ====
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

# ==== Project ====
NAME	= push_swap

# ==== Libft ====
LIBFT_DIR	= libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

# ==== Source Files ====
SRCS	= main.c radix_sort.c stack_ops.c stack_utils.c input_utils.c error.c free.c
OBJS	= $(SRCS:.c=.o)

# ==== Includes ====
INCLUDES = -I. -I$(LIBFT_DIR)

# ==== Rules ====

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT_A) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_A):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

# bonus:
# 	make -C $(LIBFT_DIR) bonus

.PHONY: all clean fclean re bonus
