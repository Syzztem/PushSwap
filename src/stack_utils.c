/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:01:24 by lothieve          #+#    #+#             */
/*   Updated: 2021/12/02 17:03:46 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int
	stack_size(const t_stack *stack)
{
	if (stack)
		return (stack_size(stack->next) + 1);
	return (0);
}

int
	is_sorted(const t_stack *stack)
{
	if (!stack)
		return (1);
	if (stack->next)
	{
		if (stack->val > stack->next->val)
			return (is_sorted(stack->next));
		return (0);
	}
	return (1);
}

void
	print_both_stacks(t_stack *a, t_stack *b)
{
	if (a || b)
	{
		if (a && b)
			print_both_stacks(a->next, b->next);
		else if (a)
			print_both_stacks(a->next, b);
		else
			print_both_stacks(a, b->next);
	}
	else
		return ;
	if (a && b)
		printf("|%10d||%-10d|\n", a->val, b->val);
	else if (a)
		printf("|%10d||%-10s|\n", a->val, "");
	else
		printf("|%10s||%-10d|\n", "", b->val);
}

t_stack
	*last(t_stack *stack)
{
	if (stack && stack->next)
		return (before_last(stack->next));
	return (stack);
}

t_stack
	*before_last(t_stack *stack)
{
	if (stack && stack->next && stack->next->next)
		return (before_last(stack->next));
	return (stack);
}
