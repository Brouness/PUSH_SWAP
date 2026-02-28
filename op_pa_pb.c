/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 12:06:25 by ybourajl          #+#    #+#             */
/*   Updated: 2026/02/28 13:59:21 by ybourajl         ###   ########.fr       */
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
// int main()
// {
// 	t_Stack *a;
// 	t_Stack *b;
// 	t_Stack *tmpa,*tmpb;
// 	a = NULL;
// 	b = NULL;
// 	int i = 0;
// 	while (i < 5)
// 	{
// 		ft_t_Stack_addback(&a, ft_new_list(i + 1));
// 		ft_t_Stack_addback(&b, ft_new_list(i));
// 		i++;
// 	}
// 	int bp = b->data;
// 	tmpa = a;
// 	tmpb = b;
// 	while (tmpa)
// 	{
// 		printf ("|  t_Stack a: %d  |  Stack b: %d  |\n", tmpa->data, tmpb->data);
// 		tmpa = tmpa->next;
// 		tmpb = tmpb->next;
// 	}
// 	pa(&a,&b);pa(&a,&b);pa(&a,&b);pa(&a,&b);pa(&a,&b);
// 	tmpa = a;
// 	printf ("_____________________________\n");
// 	while (tmpa)
// 	{
// 		printf ("|  t_Stack a: %d  |\n", tmpa->data);
// 		tmpa = tmpa->next;
// 	}
// 	ra(&a);ra(&a);ra(&a);
// 	tmpa = a;
// 	printf ("_____________________________\n");
// 	while (tmpa)
// 	{
// 		printf ("|  t_Stack a: %d  |\n", tmpa->data);
// 		tmpa = tmpa->next;
// 	}
// }
