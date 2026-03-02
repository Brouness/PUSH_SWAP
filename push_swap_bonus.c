/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:14:35 by ybourajl          #+#    #+#             */
/*   Updated: 2026/03/01 13:15:09 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check(char **s)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!s[i])
		return (1);
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == '+' || s[i][j] == '-')
				j++;
			if (s[i][j] > '9' || s[i][j] < '0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_dup_check(t_Stack *a)
{	
	int		tmp;
	t_Stack	*temp;

	tmp = a->data;
	a = a->next;
	while (a)
	{
		temp = a;
		while (temp)
		{
			if (tmp == temp->data)
				return (1);
			temp = temp->next;
		}
		tmp = a->data;
		a = a->next;
	}
	return (0);
}

static void	ft_free(char	**str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		free(str[idx]);
		idx++;
	}
	free(str);
}

int	handle_arguments(t_Stack **a, char **av)
{
	char	**str;
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		j = 0;
		str = ft_split(av[i], ' ');
		if (ft_check(str))
			return (ft_free(str), 0);
		while (str[j])
		{
			ft_stack_addback(a, ft_new_list(ft_atoi(str[j])));
			if (!*a || over_check(ft_atoi(str[j])))
				return (free(str[j]), free(str), 0);
			free(str[j]);
			j++;
		}
		free(str);
		i++;
		if (ft_dup_check(*a))
			return (0);
	}
	return (1);
}
