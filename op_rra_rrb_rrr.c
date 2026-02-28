/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rra_rrb_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 13:13:02 by ybourajl          #+#    #+#             */
/*   Updated: 2026/02/27 15:07:28 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write (1, "rra\n", 4);
}

void	rrb(t_Stack **b)
{
	reverce_rotate(b);
	write (1, "rrb\n", 4);
}

void	rrr(t_Stack **a, t_Stack **b)
{
	reverce_rotate(b);
	reverce_rotate(a);
	write (1, "rrr\n", 4);
}
