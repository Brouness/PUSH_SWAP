/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:38:04 by ybourajl          #+#    #+#             */
/*   Updated: 2026/03/01 14:33:34 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_sort_two(t_Stack **a)
{
	if ((*a)->data > (*a)->next->data)
		sa(a);
	return ;
}

void	ft_sort_three(t_Stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->data;
	second = (*a)->next->data;
	third = (*a)->next->next->data;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third && first > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	ft_push_swap(t_Stack **a, t_Stack **b)
{
	if (ft_lst_size(*a) == 1)
		return ;
	if (ft_lst_size(*a) == 2)
		ft_sort_two(a);
	if (ft_lst_size(*a) == 3)
		ft_sort_three(a);
	if (ft_lst_size(*a) == 4)
		ft_sort_four(a, b);
	if (ft_lst_size(*a) > 4)
		apply_algorithm(a, b);
}
