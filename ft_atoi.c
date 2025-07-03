/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:44:11 by totake            #+#    #+#             */
/*   Updated: 2025/07/03 17:44:14 by totake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_isspace(const char *str, int *i)
{
	while (str[*i] != '\0')
	{
		if (str[*i] == ' ' || str[*i] == '\f' || str[*i] == '\n'
			|| str[*i] == '\r' || str[*i] == '\t' || str[*i] == '\v')
			*i = *i + 1;
		else
			return ;
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// The previous digit is always changed by
// subtracting the value that over LONG_MAX.
int	ft_atoi(const char *nptr)
{
	int			i;
	long long	nbr;
	long long	sign;
	int			digit;

	i = 0;
	nbr = 0;
	ft_isspace(nptr, &i);
	if (nptr[i] == '-')
		sign = -1;
	else
		sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		digit = nptr[i] - '0';
		if (sign == 1 && (nbr > (LONG_MAX - digit) / 10))
			return ((int)LONG_MAX);
		if (sign == -1 && (-nbr < (LONG_MIN + digit) / 10))
			return ((int)LONG_MIN);
		nbr = nbr * 10 + digit;
		i++;
	}
	return ((int)(nbr * sign));
}
