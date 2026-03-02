/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:06:25 by ybourajl          #+#    #+#             */
/*   Updated: 2026/03/01 12:24:22 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_Stack **a, t_Stack **b)
{
	t_Stack	*pop;

	if (!*b)
		return ;
	pop = *b;
	*b = (*b)->next;
	pop->next = *a;
	*a = pop;
	write(1, "pb\n", 3);
}

void	pa(t_Stack **b, t_Stack **a)
{
	t_Stack	*pop;

	if (!*a)
		return ;
	pop = *a;
	*a = (*a)->next;
	pop->next = *b;
	*b = pop;
	write (1, "pa\n", 3);
}
