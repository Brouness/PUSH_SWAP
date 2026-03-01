/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:14:35 by ybourajl          #+#    #+#             */
/*   Updated: 2026/02/28 23:44:05 by ybourajl         ###   ########.fr       */
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
	t_Stack	*test;

	test = a;
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
			if (!a)
				return (1);
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

// int	main(int ac, char **av)
// {
// 	t_Stack	*a;
// 	t_Stack	*b;

// 	a = NULL;
// 	b = NULL;
// 	if (ac == 1)
// 		return (write(1, "Error\n", 6));
// 	else
// 	{
// 		if (!handle_arguments(&a, av))
// 		{
// 			return (ft_free_stack(a), write(1, "Error\n", 6), 0);
// 		}
// 	}
// 	ft_push_swap(&a, &b);
// 	ft_free_stack(a);
// 	ft_free_stack(b);
// 	return (0);
// }
