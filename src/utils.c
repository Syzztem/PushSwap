/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:12:36 by lothieve          #+#    #+#             */
/*   Updated: 2021/12/02 16:33:12 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*++str)
		;
	return (str - s);
}

size_t ft_puts(const char *str)
{
	return (write(1, str, ft_strlen(str)) + write(1, "\n", 1));
}
