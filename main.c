/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:54:49 by totake            #+#    #+#             */
/*   Updated: 2025/07/05 14:49:54 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *s)
{
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
}

//// Error Handling Policy ////
// If argc == 1 / already sorted → NonDisplay
// If non-numeric / out-of-range integer / duplicates → Free & "Error"
// If internal error (e.g., malloc fails) → Free & "Error"

void	parse_args(int argc, char **argv, int **arr, int *size)
{
	int	i;

	if (argc == 1)
		exit(0);
	*size = argc - 1;
	*arr = (int *)malloc(sizeof(int) * (*size));
	if (!*arr)
		exit_error(NULL, NULL, NULL, NULL);
	i = 0;
	while (i < *size)
	{
		if (!is_digit_str(argv[i + 1]) || !is_int_range(argv[i + 1]))
			exit_error(NULL, NULL, *arr, NULL);
		(*arr)[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (has_duplicates(*arr, *size))
		exit_error(NULL, NULL, *arr, NULL);
	if (is_sorted_array(*arr, *size))
	{
		free(*arr);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		size;
	int		i;

	init_stack(&data.a);
	init_stack(&data.b);
	parse_args(argc, argv, &data.arr, &size);
	data.ranks = create_ranks(data.arr, size);
	i = size - 1;
	while (i >= 0)
	{
		push_top(&data.a, create_node(data.ranks[i], &data));
		i--;
	}
	if (size <= 20)
		sort_small(&data.a, &data.b);
	else
		radix_sort(&data.a, &data.b);
	free_all(&data.a, &data.b, data.arr, data.ranks);
	return (0);
}
