/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:54:34 by lothieve          #+#    #+#             */
/*   Updated: 2021/12/02 17:08:34 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve_3cases(t_stack **a, t_stack **b, int *a_stack)
{
	if (a_stack[0] > a_stack[1])
	{
		if (a_stack[0] > a_stack[2])
			sa(a, b);
		else
			ra(a, b);
	}
	else if (a_stack[0] > a_stack[2])
	{
		sa(a, b);
		ra(a, b);
	}
	else if (a_stack[1] > a_stack[2])
	{
		rra(a, b);
	}
	else
	{
		sa(a, b);
		rra(a, b);
	}
}

void	solve_small(t_stack **a, t_stack **b)
{
	unsigned	size;
	int			a_stack[3];

	size = stack_size(*a);
	while (size-- > 3)
		pb(a, b);
	a_stack[0] = (*a)->val;
	a_stack[1] = (*a)->next->val;
	a_stack[2] = (*a)->next->next->val;
	solve_3cases(a, b, a_stack);
	if (is_sorted(*a))
		puts("succes");
}
