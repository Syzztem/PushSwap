/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:36:44 by lothieve          #+#    #+#             */
/*   Updated: 2022/01/13 14:12:45 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	swap(t_stack *stack)
{
	int	sw;

	if (stack_size(stack) < 2)
		return ;
	sw = stack->val;
	stack->val = stack->next->val;
	stack->next->val = sw;
}

void	sa(t_stack **a, t_stack **b)
{
	ft_puts("sa");
	(void)b;
	swap(*a);
}

void	sb(t_stack **a, t_stack **b)
{
	ft_puts("sb");
	(void)a;
	swap(*b);
}

void	ss(t_stack **a, t_stack **b)
{
	ft_puts("ss");
	swap(*a);
	swap(*b);
}
