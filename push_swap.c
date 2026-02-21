/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:14:35 by ybourajl          #+#    #+#             */
/*   Updated: 2026/02/20 13:17:07 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check(char **s)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!s[i])
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

int	ft_dup_check(Stack *a)
{	
	int	tmp;
	Stack	*temp;
	Stack	*test;
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
static void	ft_free(char	**str, int idx)
{
	while (idx > 0)
	{
		free(str[idx - 1]);
		idx--;
	}
	free(str);
}

int	handle_arguments(Stack **a, char **av)
{
	char	**str;
	int		i;
	int 	j;
	int		delevery;

	i = 1;
	while (av[i])
	{
		str = ft_split(av[i], ' ');
		if (!*str)
			return(free(str), 0);
		j = 0;
		if (ft_check(str))
			return (free(str), 0);
			while (str[j])
			{
				delevery = ft_atoi(str[j]);
				ft_stack_addback( a, ft_new_list(delevery));
				j++;
			}
			ft_free(str, j);
			i++;
		if (ft_dup_check(*a))
			return (0);
	}
	return (1);
}
void ft_free_stack(Stack *a)
{
	Stack	*tmp;
	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}

int main(int ac, char **av)
{
	char	**str;
	Stack	*a;
	Stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (write(1, "Error\n", 6));
	else
	{
		if (!handle_arguments(&a, av))
		{

			return (write(1, "Error\n", 6), 0);
		}
	}
	while (a)
	{
		printf("%d\n", a->data);
		a = a->next;
	}
	ft_free_stack(a);
	return (0);
}
