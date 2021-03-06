/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:44:20 by lothieve          #+#    #+#             */
/*   Updated: 2021/03/06 12:04:54 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void
	rotate(t_stack **first, t_stack *last)
{
	if (last->next->next)
		return (rotate(first, last->next));
	last->next->next = *first;
	*first = last->next;
	last->next = NULL;
}

void	ra(t_stack **a, t_stack **b)
{
	(void)b;
	if (stack_size(*a) < 2)
		return ;
	rotate(a, *a);
}

void	rb(t_stack **a, t_stack **b)
{
	(void)a;
	if (stack_size(*b) < 2)
		return ;
	rotate(b, *b);
}

void	rr(t_stack **a, t_stack **b)
{
	if (stack_size(*a) >= 2)
		rotate(a, *a);
	if (stack_size(*b) >= 2)
		rotate(b, *b);
}
