/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:46:41 by lothieve          #+#    #+#             */
/*   Updated: 2021/12/02 14:32:33 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	rrotate(t_stack **first, t_stack *last)
{
	if (last->next)
		return (rrotate(first, last->next));
	last->next = *first;
	*first = (*first)->next;
	last->next->next = NULL;
}

void	rra(t_stack **a, t_stack **b)
{
	ft_puts("rra");
	(void)b;
	if (stack_size(*a) < 2)
		return ;
	rrotate(a, *a);
}

void	rrb(t_stack **a, t_stack **b)
{
	ft_puts("rrb");
	(void)a;
	if (stack_size(*b) < 2)
		return ;
	rrotate(b, *b);
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_puts("rrr");
	if (stack_size(*a) >= 2)
		rrotate(a, *a);
	if (stack_size(*b) >= 2)
		rrotate(b, *b);
}
