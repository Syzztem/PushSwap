/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   furbiddun_cunstunt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:23:57 by lothieve          #+#    #+#             */
/*   Updated: 2021/03/05 16:02:27 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

const char **ins_names()
{
	static const char *n[INS_COUNT] = {
		"sa",
		"sb",
		"ss",
		"pa",
		"pb",
		"ra",
		"rb",
		"rr",
		"rra",
		"rrb",
		"rrr"
	};
	return (n);
}

t_inss instructions()
{
	static const t_inss i = {.instructs = {
		sa,
		sb,
		ss,
		pa,
		pb,
		ra,
		rb,
		rr,
		rra,
		rrb,
		rrr
	}};
	return (i);
}
