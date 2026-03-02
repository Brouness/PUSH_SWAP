/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rra_rrb_rrr_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:13:02 by ybourajl          #+#    #+#             */
/*   Updated: 2026/03/01 12:19:10 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reverce_rotate(t_Stack **stack)
{
	t_Stack	*parser;
	t_Stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	parser = *stack;
	while (parser->next)
	{
		tmp = parser;
		parser = parser->next;
	}
	tmp->next = NULL;
	ft_add_front(stack, parser);
}

void	rra(t_Stack **a)
{
	reverce_rotate(a);
}

void	rrb(t_Stack **b)
{
	reverce_rotate(b);
}

void	rrr(t_Stack **a, t_Stack **b)
{
	reverce_rotate(b);
	reverce_rotate(a);
}
