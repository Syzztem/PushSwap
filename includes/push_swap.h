/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:53:18 by lothieve          #+#    #+#             */
/*   Updated: 2021/12/02 17:06:22 by lothieve         ###   ########.fr       */
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
t_stack			*last(t_stack *stack);
t_stack			*before_last(t_stack *stack);
void			print_both_stacks(t_stack *a, t_stack *b);

size_t			ft_puts(const char *str);
size_t			ft_strlen(const char *str);

void			solve_small(t_stack **a, t_stack **b);
void			solve(t_stack **a);

#endif
