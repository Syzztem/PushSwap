/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 11:42:35 by lothieve          #+#    #+#             */
/*   Updated: 2022/01/13 15:51:02 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

uint32_t
	biggest_under(t_stack *stack, uint32_t val)
{
	uint32_t	biggest;

	if (val == 0)
		return (stack_max(stack));
	if (!stack)
		return (UINT_MAX);
	biggest = biggest_under(stack->next, val);
	if ((stack->val > biggest || biggest == UINT_MAX) && stack->val < val)
		return (stack->val);
	return (biggest);
}

uint32_t
	smallest_over(t_stack *stack, uint32_t val)
{
	uint32_t	smallest;

	if (val == 0)
		return (stack_min(stack));
	if (!stack)
		return (UINT_MAX);
	smallest = smallest_over(stack->next, val);
	if (stack->val < smallest && stack->val > val)
		return (stack->val);
	return (smallest);
}

void
	insert(t_stack **a, t_stack **b)
{
	send_to_bottom(a, smallest_over(*a, (*b)->val), ra, rra);
	pa(a, b);
}

void
	insert_b(t_stack **a, t_stack **b)
{
	uint32_t	biggest;

	biggest = biggest_under(*b, (*a)->val);
	if (biggest == UINT_MAX)
		biggest = stack_max(*b);
	send_to_bottom(b, biggest, rb, rrb);
	pb(a, b);
}
