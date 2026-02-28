/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:20:00 by ybourajl          #+#    #+#             */
/*   Updated: 2026/02/28 15:34:46 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rot_both(t_Stack **a, t_Stack **b, t_Stack *cheapt)
{
	while (cheapt->cost_a > 0 && cheapt->cost_b > 0)
	{
		rr(a, b);
		cheapt->cost_a--;
		cheapt->cost_b--;
	}
	while (cheapt->cost_a < 0 && cheapt->cost_b < 0)
	{
		rrr(a, b);
		cheapt->cost_a++;
		cheapt->cost_b++;
	}
}

static void	rot_a(t_Stack **a, t_Stack *cheapt)
{
	while (cheapt->cost_a > 0)
	{
		ra(a);
		cheapt->cost_a--;
	}
	while (cheapt->cost_a < 0)
	{
		rra(a);
		cheapt->cost_a++;
	}
}

static void	rot_b(t_Stack **b, t_Stack *cheapt)
{
	while (cheapt->cost_b > 0)
	{
		rb(b);
		cheapt->cost_b--;
	}
	while (cheapt->cost_b < 0)
	{
		rrb(b);
		cheapt->cost_b++;
	}
}

void	exec(t_Stack **a, t_Stack **b, t_Stack *cheapt)
{
	rot_both(a, b, cheapt);
	rot_a(a, cheapt);
	rot_b(b, cheapt);
}
