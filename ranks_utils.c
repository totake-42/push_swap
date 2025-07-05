/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:09:12 by totake            #+#    #+#             */
/*   Updated: 2025/07/05 17:24:45 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	*copy_array(int *arr, int size)
{
	int	*iarr;
	int	i;

	iarr = (int *)malloc(sizeof(int) * size);
	if (!iarr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		iarr[i] = arr[i];
		i++;
	}
	return (iarr);
}

static void	selection_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	*build_ranks(int *arr, int *sorted, int size)
{
	int	*ranks;
	int	i;
	int	j;

	ranks = (int *)malloc(sizeof(int) * size);
	if (!ranks)
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == sorted[j])
				ranks[i] = j;
			j++;
		}
		i++;
	}
	return (ranks);
}

int	*create_ranks(int *arr, int size)
{
	int	*sorted;
	int	*ranks;

	sorted = copy_array(arr, size);
	if (!sorted)
		exit_error(NULL, NULL, arr, NULL);
	selection_sort(sorted, size);
	ranks = build_ranks(arr, sorted, size);
	if (!ranks)
		exit_error(NULL, NULL, arr, sorted);
	free(sorted);
	return (ranks);
}
