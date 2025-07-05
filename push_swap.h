/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:55:44 by totake            #+#    #+#             */
/*   Updated: 2025/07/05 17:28:31 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>  // LONG_MAX LONG_MIN
# include <stdbool.h> // bool
# include <stdlib.h>  // malloc
# include <unistd.h>  // write

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

typedef struct s_data
{
	int				*arr;
	int				*ranks;
	t_stack			a;
	t_stack			b;
}					t_data;

// stack_utils.c
t_node				*create_node(int value, t_data *data);
void				push_top(t_stack *stack, t_node *node);
t_node				*pop_top(t_stack *stack);
void				push_bottom(t_stack *stack, t_node *node);
t_node				*pop_bottom(t_stack *stack);

// stack_ops.c
void				pb(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				sa(t_stack *a);
void				rra(t_stack *a);

// radix_sort.c
void				radix_sort(t_stack *a, t_stack *b);

// ranks_utils.c
int					*create_ranks(int *arr, int size);

// small_sort.c
void				sort_small(t_stack *a, t_stack *b);

// error.c
void				exit_error(t_stack *a, t_stack *b, int *arr, int *ranks);
bool				is_digit_str(char *str);
bool				is_int_range(const char *str);
bool				has_duplicates(int *arr, int size);
bool				is_sorted_array(int *arr, int size);

// free.c
void				free_stack(t_stack *stack);
void				free_all(t_stack *a, t_stack *b, int *arr, int *ranks);

// ft_atoi.c
int					ft_atoi(const char *nptr);

// ft_strcmp.c
int					ft_strcmp(const char *s1, const char *s2);

#endif
