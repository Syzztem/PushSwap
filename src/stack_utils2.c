/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:58:48 by lothieve          #+#    #+#             */
/*   Updated: 2022/01/13 16:14:27 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	chunk_to_b(t_stack **a, t_stack **b, uint32_t start, uint32_t chunk_size)
{
	uint32_t	end;

	end = start + chunk_size;
	while (chunk_size--)
	{
		while ((*a)->val < start || (*a)->val >= end)
			rra(a, b);
		insert_b(a, b);
	}
}

uint32_t
	index_of(t_stack *stack, uint32_t val)
{
	uint32_t	index;

	if (!stack)
		return (UINT_MAX);
	if (stack->val == val)
		return (0);
	index = index_of(stack->next, val);
	if (index == UINT_MAX)
		return (index);
	return (index + 1);
}

void
	send_to_bottom(t_stack **stack, uint32_t val, t_instruct r, t_instruct rr)
{
	t_instruct	move;
	uint32_t	index;

	index = index_of(*stack, val);
	if (index == UINT_MAX)
		return ;
	if (index < stack_size(*stack) / 2)
		move = r;
	else
		move = rr;
	while ((*stack)->val != val)
		move(stack, stack);
}

uint32_t
	stack_min(t_stack *s)
{
	uint32_t	val;

	if (!s)
		return (UINT_MAX);
	val = stack_min(s->next);
	if (s->val < val)
		return (s->val);
	return (val);
}

uint32_t
	stack_max(t_stack *s)
{
	uint32_t	val;

	if (!s)
		return (0);
	val = stack_max(s->next);
	if (s->val > val)
		return (s->val);
	return (val);
}
