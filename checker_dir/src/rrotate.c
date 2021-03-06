/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:46:41 by lothieve          #+#    #+#             */
/*   Updated: 2021/03/05 15:48:24 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void
	rrotate(t_stack **stack)
{
	(void)stack;
}

void	rra(t_stack **a, t_stack **b)
{
	(void)b;
	rrotate(a);
}

void	rrb(t_stack **a, t_stack **b)
{
	(void)a;
	rrotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rrotate(a);
	rrotate(b);
}
