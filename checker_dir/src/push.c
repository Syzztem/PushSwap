/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:41:32 by lothieve          #+#    #+#             */
/*   Updated: 2021/03/06 14:25:03 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_stack
	*pop_last(t_stack **stack)
{
	t_stack *out;
	t_stack *bef_last;

	if (!(*stack)->next)
	{
		out = *stack;
		*stack = NULL;
		return (out);
	}
	bef_last = before_last(*stack);
	out = bef_last->next;
	bef_last->next = NULL;
	return (out);
}

static void
	push_back(t_stack **stack, t_stack *elem)
{
	if (*stack)
		return (push_back(&(*stack)->next, elem));
	*stack = elem;
}

void	pa(t_stack **a, t_stack **b)
{
	if (!*b)
		return ;
	push_back(a, pop_last(b));
}

void	pb(t_stack **a, t_stack **b)
{
	pa(b, a);
}
