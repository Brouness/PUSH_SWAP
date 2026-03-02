/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ra_rb_rr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:48:19 by ybourajl          #+#    #+#             */
/*   Updated: 2026/03/01 12:18:55 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reverce(t_Stack **stack)
{
	t_Stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_stack_addback(stack, tmp);
}

void	ra(t_Stack **a)
{
	reverce(a);
}

void	rb(t_Stack **b)
{
	reverce(b);
}

void	rr(t_Stack **a, t_Stack **b)
{
	reverce(a);
	reverce(b);
}
