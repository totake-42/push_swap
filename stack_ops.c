/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:04:29 by totake            #+#    #+#             */
/*   Updated: 2025/07/03 17:39:23 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	if (a->size == 0)
		return ;
	push_top(b, pop_top(a));
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return ;
	push_top(a, pop_top(b));
	write(1, "pa\n", 3);
}

void	ra(t_stack *a)
{
	if (a->size <= 1)
		return ;
	push_bottom(a, pop_top(a));
	write(1, "ra\n", 3);
}

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (a->size <= 1)
		return ;
	first = pop_top(a);
	second = pop_top(a);
	push_top(a, first);
	push_top(a, second);
	write(1, "sa\n", 3);
}

void	rra(t_stack *a)
{
	if (a->size <= 1)
		return ;
	push_top(a, pop_bottom(a));
	write(1, "rra\n", 4);
}
