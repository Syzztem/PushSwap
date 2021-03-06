/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:53:18 by lothieve          #+#    #+#             */
/*   Updated: 2021/03/06 14:42:15 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define INS_COUNT 11
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# define SHIT_LOAD_OF_DASHES "-------------------------------------------------"

typedef struct	s_stack
{
	struct s_stack	*next;
	int				val;
}				t_stack;

typedef void (*t_instruct)(t_stack **a, t_stack **b);

typedef struct	s_inss
{
	t_instruct instructs[INS_COUNT];
}				t_inss;

void			err_exit();
void			run_and_check(t_stack *a, int fd);

const char		**ins_names();
t_inss			instructions();

void			sa(t_stack **a, t_stack **b);
void			sb(t_stack **a, t_stack **b);
void			ss(t_stack **a, t_stack **b);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **a, t_stack **b);
void			ra(t_stack **a, t_stack **b);
void			rb(t_stack **a, t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			rra(t_stack **a, t_stack **b);
void			rrb(t_stack **a, t_stack **b);
void			rrr(t_stack **a, t_stack **b);

int				is_sorted(const t_stack *stack);
unsigned int	stack_size(const t_stack *stack);
t_stack			*before_last(t_stack *stack);
void			print_state(char *instruct, t_stack *a, t_stack *b);

#endif
