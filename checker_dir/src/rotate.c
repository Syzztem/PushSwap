/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:44:20 by lothieve          #+#    #+#             */
/*   Updated: 2021/03/05 15:48:05 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void
	rotate(t_stack **stack)
{
	(void)stack;
}

void	ra(t_stack **a, t_stack **b)
{
	(void)b;
	rotate(a);
}

void	rb(t_stack **a, t_stack **b)
{
	(void)a;
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
