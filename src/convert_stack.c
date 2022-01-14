/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:34:36 by lothieve          #+#    #+#             */
/*   Updated: 2021/12/28 17:47:05 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_sstack
	*smallest_over_s(t_sstack *stack, int value)
{
	t_sstack	*smallest;

	if (!stack)
		return (NULL);
	smallest = smallest_over_s(stack->next, value);
	if (!smallest && stack->val > value)
		return (stack);
	else if (!smallest || smallest->val < stack->val)
		return (smallest);
	else if (stack->val > value)
		return (stack);
	return (smallest);
}

void	convert_stack_w(t_sstack *stack, int last_val, int i)
{
	t_sstack	*elem;

	elem = smallest_over_s(stack, last_val);
	if (!elem)
		return ;
	convert_stack_w(stack, elem->val, i + 1);
	elem->val = i;
}

void	convert_stack(t_sstack *stack)
{
	convert_stack_w(stack, INT_MIN, 0);
}
