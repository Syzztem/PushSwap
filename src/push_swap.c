/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:43:44 by lothieve          #+#    #+#             */
/*   Updated: 2022/01/13 16:16:32 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_exit(void)
{
	printf("Error\n");
	exit(0);
}

static int	ft_atoi(const char *str)
{
	long	out;
	int		sign;

	out = 0;
	sign = 1;
	if (*str == '-')
	{
		++str;
		sign = -1;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9' || out > INT_MAX)
			error_exit();
		out = out * 10 + *str - '0';
		++str;
	}
	out *= sign;
	if (out > INT_MAX || out < INT_MIN)
		error_exit();
	return ((int)out);
}

static void	check_doublons(int size, t_sstack *stack)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
			if (stack[i].val == stack[j].val)
				error_exit();
	}
}

static t_sstack	*get_stack(int size, char **list)
{
	t_sstack	*stack;
	int			i;

	stack = malloc(sizeof(t_stack) * size);
	i = 0;
	while (i < size)
	{
		stack[i].val = ft_atoi(list[i]);
		if (i != size - 1)
			stack[i].next = stack + i + 1;
		else
			stack[i].next = NULL;
		++i;
	}
	check_doublons(size, stack);
	return (stack);
}

int	main(int ac, char **av)
{
	t_sstack	*a;
	t_stack		*acpy;

	if (ac < 2)
		return (0);
	a = get_stack(ac - 1, av + 1);
	convert_stack(a);
	acpy = (t_stack *)a;
	solve(&acpy);
	free(a);
}
