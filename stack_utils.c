/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:07:03 by totake            #+#    #+#             */
/*   Updated: 2025/07/03 15:13:30 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value, t_data *data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		exit_error(&data->a, &data->b, data->arr, data->ranks);
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	push_top(t_stack *stack, t_node *node)
{
	node->next = stack->top;
	node->prev = NULL;
	if (stack->top)
		stack->top->prev = node;
	else
		stack->bottom = node;
	stack->top = node;
	stack->size++;
}

t_node	*pop_top(t_stack *stack)
{
	t_node	*node;

	if (!stack->top)
		return (NULL);
	node = stack->top;
	stack->top = node->next;
	if (stack->top)
		stack->top->prev = NULL;
	else
		stack->bottom = NULL;
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}

void	push_bottom(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	node->prev = stack->bottom;
	node->next = NULL;
	if (stack->bottom)
		stack->bottom->next = node;
	else
		stack->top = node;
	stack->bottom = node;
	stack->size++;
}

t_node	*pop_bottom(t_stack *stack)
{
	t_node	*node;

	if (!stack->bottom)
		return (NULL);
	node = stack->bottom;
	stack->bottom = node->prev;
	if (stack->bottom)
		stack->bottom->next = NULL;
	else
		stack->top = NULL;
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}
