/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_and_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:56:31 by lothieve          #+#    #+#             */
/*   Updated: 2021/03/06 15:06:50 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int
	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (!*s1 && !*s2)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int
	adaptive_read(int fd, char *buf)
{
	char	nul;

	if (read(fd, buf, 3) < 3 || *buf == '\04')
		return (0);
	if (buf[2] == '\n')
		buf[2] = 0;
	else
		read(fd, &nul, 1);
	return (1);
}

static t_instruct
	run_instruct(char *instruct)
{
	int i;

	i = 0;
	while (i < INS_COUNT)
	{
		if (!ft_strcmp(instruct, ins_names()[i]))
			return (instructions().instructs[i]);
		++i;
	}
	err_exit();
	return (NULL);
}

void
	run_and_check(t_stack *a, int fd)
{
	t_stack *b;
	char	instruct[4];

	b = NULL;
	(void)a;
	instruct[3] = 0;
	while (adaptive_read(fd, instruct))
	{
		run_instruct(instruct)(&a, &b);
		print_state(instruct, a, b);
	}
	if (!b && is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

