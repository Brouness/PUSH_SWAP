/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:43:48 by ybourajl          #+#    #+#             */
/*   Updated: 2026/03/01 14:20:21 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else if (a < b)
		return (b);
	return (a);
}

int	ft_abs(int x)
{
	if (x < 0)
		return (x = x * -1);
	return (x);
}

t_Stack	*find_cheapest(t_Stack **b)
{
	t_Stack	*tmp;
	t_Stack	*cheapest;

	if (!*b)
		return (NULL);
	tmp = *b;
	cheapest = tmp;
	while (tmp)
	{
		if (tmp->total_cost < cheapest->total_cost)
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}

void	final_rotation(t_Stack **a)
{
	t_Stack	*min;
	int		size;
	int		pos;
	int		reverse;

	if (!a || !*a)
		return ;
	initialise_stack_pos(a);
	min = min_node(*a);
	pos = min->pos;
	size = ft_lst_size(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		reverse = size - pos;
		while (reverse-- > 0)
			rra(a);
	}
}

void	rot_smaller(t_Stack **a)
{
	t_Stack	*smller;
	int		size;

	smller = min_node(*a);
	size = ft_lst_size(*a);
	initialise_stack_pos(a);
	while (smller->pos)
	{
		if (smller->pos <= size / 2)
			ra(a);
		else
			rra(a);
		initialise_stack_pos(a);
	}
}
