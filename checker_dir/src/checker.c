/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:58:00 by lothieve          #+#    #+#             */
/*   Updated: 2021/03/05 15:36:25 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void
	err_exit()
{
	write(2, "Error\n", 6);
	exit(-1);
}

static int
	ft_atoi(const char *str)
{
	int				sign;
	unsigned long	out;

	sign = 1;
	out = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		out = out * 10 + (*str - '0');
		if (out > (unsigned int)-INT_MIN)
			err_exit();
		str++;
	}
	if (*str || out * sign > INT_MAX)
		err_exit();
	return (out * sign);
}

static t_stack
	*get_stack(int count, char **vals)
{
	t_stack *out;
	int		i;

	out = malloc(sizeof(t_stack) * count);
	i = count;
	while (--i >= 0)
	{
		out[i].val = ft_atoi(vals[i]);
		if (i < count - 1)
			out[i].next = out + i + 1;
		else
			out[i].next = NULL;
	}
	return (out);
}

int
	main(int ac, char **av)
{
	t_stack *a;

	if (ac <= 2)
	{
		write(1, "OK\n", 3);
		return (0);
	}
	a = get_stack(ac - 1, av + 1);
	run_and_check(a, 0);
	free(a);
}
