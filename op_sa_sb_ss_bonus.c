/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sa_sb_ss_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 10:42:59 by ybourajl          #+#    #+#             */
/*   Updated: 2026/02/28 15:36:59 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_Stack **stack)
{
	t_Stack	*s;

	if (!*stack || !(*stack)->next)
		return ;
	s = (*stack)->next;
	(*stack)->next = s->next;
	s->next = *stack;
	*stack = s;
}

void	sa(t_Stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_Stack **b)
{
	swap(b);
	write (1, "sb\n", 3);
}

void	ss(t_Stack **a, t_Stack **b)
{
	swap(a);
	swap(b);
	write (1, "ss\n", 3);
}
