/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:14:43 by ybourajl          #+#    #+#             */
/*   Updated: 2026/03/01 15:23:58 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_signe(const char *str, int i)
{
	if (str[i] == '-')
		return (-1);
	return (1);
}

static int	ft_return(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	return (i);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		s;
	long	r;

	if (str == NULL)
		return (0);
	r = 0;
	i = ft_return(str);
	s = ft_signe(str, i);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		r = r * 10 + (str[i] - '0');
		if (r < 0)
		{
			if (s > 0)
				return (2147483648);
			return (-2147483649);
		}
		i++;
	}
	if (str[i] != '\0')
		return (2147483648);
	return (r * s);
}

int	over_check(long atoi)
{
	if (2147483647 < atoi || -2147483648 > atoi)
		return (1);
	return (0);
}
