/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:18:23 by totake            #+#    #+#             */
/*   Updated: 2025/07/03 15:17:43 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*cur;
	t_node	*next;

	cur = stack->top;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	free_all(t_stack *a, t_stack *b, int *arr, int *ranks)
{
	if (arr)
		free(arr);
	if (ranks)
		free(ranks);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
}
