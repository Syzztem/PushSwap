/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:36:44 by lothieve          #+#    #+#             */
/*   Updated: 2021/03/06 11:18:01 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void
	swap(t_stack *stack)
{
	int sw;

	if (stack_size(stack) < 2)
		return ;
	if (stack->next->next)
		return (swap(stack->next));
	sw = stack->val;
	stack->val = stack->next->val;
	stack->next->val = sw;
}

void	sa(t_stack **a, t_stack **b)
{
	(void)b;
	swap(*a);
}

void	sb(t_stack **a, t_stack **b)
{
	(void)a;
	swap(*b);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(*a);
	swap(*b);
}
