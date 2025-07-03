/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:15:04 by totake            #+#    #+#             */
/*   Updated: 2025/07/03 17:35:00 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(t_stack *a, t_stack *b, int *arr, int *ranks)
{
	write(2, "Error\n", 6);
	if (arr)
		free(arr);
	if (ranks)
		free(ranks);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	exit(1);
}

bool	is_digit_str(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (false);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

bool	is_int_range(const char *str)
{
	int	sign;
	int	len;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	len = 0;
	while (*str == '0')
		str++;
	while (str[len])
		len++;
	if (len >= 11)
		return (false);
	if (len <= 9)
		return (true);
	if (len == 10 && sign == 1)
		return (ft_strcmp(str, "2147483647") <= 0);
	else
		return (ft_strcmp(str, "2147483648") <= 0);
}

bool	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	is_sorted_array(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (false);
		i++;
	}
	return (true);
}
