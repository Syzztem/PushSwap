/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:36:44 by lothieve          #+#    #+#             */
/*   Updated: 2021/03/05 16:03:41 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void
	swap(t_stack **stack)
{
	(void)stack;
}

void	sa(t_stack **a, t_stack **b)
{
	(void)b;
	swap(a);
}

void	sb(t_stack **a, t_stack **b)
{
	(void)a;
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}
