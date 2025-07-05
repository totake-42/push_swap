/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:38:20 by totake            #+#    #+#             */
/*   Updated: 2025/07/05 17:15:20 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->top->value;
	y = a->top->next->value;
	z = a->bottom->value;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

static int	get_min_index(t_stack *a)
{
	t_node	*cur;
	int		min;
	int		min_index;
	int		i;

	cur = a->top;
	min = cur->value;
	min_index = 0;
	i = 0;
	while (cur)
	{
		if (cur->value < min)
		{
			min = cur->value;
			min_index = i;
		}
		cur = cur->next;
		i++;
	}
	return (min_index);
}

static void	rotate_to_min_top(t_stack *a, int min_index)
{
	if (min_index <= a->size / 2)
		while (min_index-- > 0)
			ra(a);
	else
	{
		min_index = a->size - min_index;
		while (min_index-- > 0)
			rra(a);
	}
}

void	sort_small(t_stack *a, t_stack *b)
{
	int	min_index;

	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 20)
	{
		while (a->size > 3)
		{
			min_index = get_min_index(a);
			rotate_to_min_top(a, min_index);
			pb(a, b);
		}
		sort_three(a);
		while (b->size > 0)
			pa(a, b);
	}
}
