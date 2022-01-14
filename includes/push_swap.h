/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <lothieve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:53:18 by lothieve          #+#    #+#             */
/*   Updated: 2022/01/05 14:21:47 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INS_COUNT 11
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

typedef struct s_stack
{
	struct s_stack	*next;
	uint32_t		val;
}				t_stack;

typedef struct s_sstack
{
	struct s_sstack	*next;
	int				val;
}				t_sstack;

typedef void	(*t_instruct)(t_stack **a, t_stack **b);

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

t_stack			*last(t_stack *stack);
t_stack			*before_last(t_stack *stack);
int				is_sorted(const t_stack *stack);
uint32_t		stack_size(const t_stack *stack);
uint32_t		stack_max(t_stack *s);
uint32_t		stack_min(t_stack *s);
uint32_t		biggest_under(t_stack *stack, uint32_t val);
uint32_t		smallest_over(t_stack *stack, uint32_t val);
uint32_t		index_of(t_stack *stack, uint32_t val);
void			print_both_stacks(t_stack *a, t_stack *b);
void			reorder(t_stack **stack);
void			insert(t_stack **a, t_stack **b);
void			insert_b(t_stack **a, t_stack **b);
void			chunk_to_b(t_stack **a, t_stack **b, uint32_t s, uint32_t c);
void			send_to_bottom(t_stack **s, uint32_t v, t_instruct r,
					t_instruct rr);

size_t			ft_puts(const char *str);
size_t			ft_strlen(const char *str);

void			convert_stack(t_sstack *stack);
void			solve_small(t_stack **a, t_stack **b);
void			solve(t_stack **a);

#endif
