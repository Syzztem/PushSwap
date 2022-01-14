/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:54:34 by lothieve          #+#    #+#             */
/*   Updated: 2022/01/13 15:02:41 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	solve_3cases(t_stack **a, t_stack **b, uint32_t *a_stack)
{
	if (a_stack[0] > a_stack[1])
	{
		if (a_stack[1] > a_stack[2])
		{
			sa(a, b);
			rra(a, b);
		}
		else if (a_stack[0] > a_stack[2])
			ra(a, b);
		else
			sa(a, b);
	}
	else if (a_stack[1] > a_stack[2])
	{
		if (a_stack[0] < a_stack[2])
		{
			sa(a, b);
			ra(a, b);
		}
		else
			rra(a, b);
	}
}

void
	solve_small(t_stack **a, t_stack **b)
{
	uint32_t	size;
	uint32_t	a_stack[3];

	size = stack_size(*a);
	while (size-- > 3)
		pb(a, b);
	a_stack[0] = (*a)->val;
	a_stack[1] = (*a)->next->val;
	a_stack[2] = (*a)->next->next->val;
	if (!is_sorted(*a))
		solve_3cases(a, b, a_stack);
	if (stack_size(*b) == 2 && (*b)->val < (*b)->next->val)
		sb(a, b);
	if (*b)
	{
		while (*b)
			insert(a, b);
		send_to_bottom(a, stack_min(*a), ra, rra);
	}
}
