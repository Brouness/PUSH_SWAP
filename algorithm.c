/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:32:24 by ybourajl          #+#    #+#             */
/*   Updated: 2026/03/01 14:22:39 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Stack	*min_node(t_Stack *a)
{
	t_Stack	*tmp;
	t_Stack	*min_node;
	int		min_idx;

	tmp = a;
	min_node = tmp;
	min_idx = tmp->data;
	while (tmp)
	{
		if (tmp->data < min_idx)
		{
			min_node = tmp;
			min_idx = tmp->data;
		}
		tmp = tmp->next;
	}
	return (min_node);
}

t_Stack	*find_target_node(t_Stack **a, t_Stack **b)
{
	int		diff;
	t_Stack	*best_match;
	t_Stack	*tmp;
	int		min_diff;

	best_match = NULL;
	min_diff = 2147483647;
	tmp = *a;
	while (tmp)
	{
		if (tmp->data > (*b)->data)
		{
			diff = tmp->data - (*b)->data;
			if (diff < min_diff)
			{
				best_match = tmp;
				min_diff = diff;
			}
		}
		tmp = tmp->next;
	}
	if (best_match)
		return (best_match);
	return (min_node(*a));
}

void	cost_calculation(t_Stack **a, t_Stack **b, t_Stack **b_list)
{
	int	size_a;
	int	size_b;
	int	pos_a;
	int	pos_b;

	pos_a = (*b)->target->pos;
	pos_b = (*b)->pos;
	size_a = ft_lst_size(*a);
	size_b = ft_lst_size(*b_list);
	if (pos_b <= size_b / 2)
		(*b)->cost_b = pos_b;
	else
		(*b)->cost_b = pos_b - size_b;
	if (pos_a <= size_a / 2)
		(*b)->cost_a = pos_a;
	else
		(*b)->cost_a = pos_a - size_a;
	if (((*b)->cost_a > 0 && (*b)->cost_b > 0)
		|| ((*b)->cost_a < 0 && (*b)->cost_b < 0))
		(*b)->total_cost = max(ft_abs((*b)->cost_a), ft_abs((*b)->cost_b));
	else
		(*b)->total_cost = ft_abs((*b)->cost_a) + ft_abs((*b)->cost_b);
}

void	apply_algorithm(t_Stack **a, t_Stack **b)
{
	t_Stack	*tmp;
	t_Stack	*cheapest;

	while (ft_lst_size(*a) > 3)
	{
		pb(b, a);
	}
	ft_sort_three(a);
	while (*b)
	{
		initialise_stack_pos(a);
		initialise_stack_pos(b);
		tmp = *b;
		while (tmp)
		{
			tmp->target = find_target_node(a, &tmp);
			cost_calculation(a, &tmp, b);
			tmp = tmp->next;
		}
		cheapest = find_cheapest(b);
		exec(a, b, cheapest);
		pa(a, b);
	}
	rot_smaller(a);
}
