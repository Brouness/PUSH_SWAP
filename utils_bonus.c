/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:13:12 by ybourajl          #+#    #+#             */
/*   Updated: 2026/03/01 14:33:51 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	find_min(t_Stack *a)
{
	int	min;

	min = a->data;
	while (a)
	{
		if (a->data < min)
			min = a->data;
		a = a->next;
	}
	return (min);
}

static void	push_min(t_Stack **a, t_Stack **b)
{
	int	min;

	min = find_min(*a);
	while ((*a)->data != min)
		ra(a);
	pb(b, a);
}

void	ft_sort_four(t_Stack **a, t_Stack **b)
{
	push_min(a, b);
	ft_sort_three(a);
	pa(a, b);
}

void	initialise_stack_pos(t_Stack **a)
{
	int		pos;
	t_Stack	*tmp;

	tmp = *a;
	pos = 0;
	while (tmp)
	{
		tmp->pos = pos;
		pos++;
		tmp = tmp->next;
	}
}
