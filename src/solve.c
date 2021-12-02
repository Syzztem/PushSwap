/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:53:49 by lothieve          #+#    #+#             */
/*   Updated: 2021/12/02 16:36:51 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (is_sorted(*a))
		return ;
	if (stack_size(*a) <= 5)
		solve_small(a, &b);
}
