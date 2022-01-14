/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:41:32 by lothieve          #+#    #+#             */
/*   Updated: 2022/01/13 16:04:47 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*save;

	save = *src;
	*src = save->next;
	save->next = *dest;
	*dest = save;
}

void	pa(t_stack **a, t_stack **b)
{
	ft_puts("pa");
	if (!*b)
		return ;
	push(a, b);
}

void	pb(t_stack **a, t_stack **b)
{
	ft_puts("pb");
	if (!*a)
		return ;
	push(b, a);
}
