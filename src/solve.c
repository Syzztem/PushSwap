/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:53:49 by lothieve          #+#    #+#             */
/*   Updated: 2022/01/13 16:07:47 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_stack **a, t_stack **b)
{
	int			i;
	uint32_t	size;

	size = stack_size(*a);
	i = 0;
	while (*a)
	{
		++i;
		send_to_bottom(a, i, ra, rra);
		pb(a, b);
	}
	while (*b)
		pa(a, b);
	send_to_bottom(a, 0, ra, rra);
}

void	chunked_sort(t_stack **a, t_stack **b, uint32_t size)
{
	uint32_t	chunk_size;
	uint32_t	i;

	if (size == 100)
		chunk_size = 20;
	else
		chunk_size = 50;
	i = size;
	while (i > 0)
	{
		i -= chunk_size;
		chunk_to_b(a, b, i, chunk_size);
		send_to_bottom(b, stack_max(*b), rb, rrb);
		send_to_bottom(a, i + chunk_size, ra, rra);
		while (*b)
			pa(a, b);
	}
	send_to_bottom(a, stack_min(*a), ra, rra);
}

void	solve_big(t_stack **a, t_stack **b)
{
	uint32_t	size;

	size = stack_size(*a);
	if (size == 100 || size == 500)
		chunked_sort(a, b, size);
	else
		insertion_sort(a, b);
}

void	solve(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (is_sorted(*a))
		return ;
	if (stack_size(*a) <= 5)
		return (solve_small(a, &b));
	return (solve_big(a, &b));
}
