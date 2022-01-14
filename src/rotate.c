/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:44:20 by lothieve          #+#    #+#             */
/*   Updated: 2022/01/13 14:57:39 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	rotate(t_stack **first, t_stack *last)
{
	if (last->next)
		return (rotate(first, last->next));
	last->next = *first;
	*first = (*first)->next;
	last->next->next = NULL;
}

void	ra(t_stack **a, t_stack **b)
{
	if (!*a || !(*a)->next)
		return ;
	ft_puts("ra");
	(void)b;
	rotate(a, *a);
}

void	rb(t_stack **a, t_stack **b)
{
	if (!*b || !(*b)->next)
		return ;
	ft_puts("rb");
	(void)a;
	rotate(b, *b);
}

void	rr(t_stack **a, t_stack **b)
{
	ft_puts("rr");
	if (stack_size(*a) >= 2)
		rotate(a, *a);
	if (stack_size(*b) >= 2)
		rotate(b, *b);
}
