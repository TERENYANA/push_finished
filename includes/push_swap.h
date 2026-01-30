/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <yyuskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:39:40 by yyuskiv           #+#    #+#             */
/*   Updated: 2026/01/30 13:40:31 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost_b;
	int				cost_a;
	struct s_stack	*target;
	struct s_stack	*next;
}					t_stack;

// Парсинг
int					is_valid_number(char *str);
int					ft_isspace(int c);
int					ft_isdigit(int c);
long				ft_atol(char *str);
int					has_duplicate(t_stack *stack, int num);
t_stack				*parse_args(int argc, char **argv);

// Стек - утилиты
t_stack				*new_node(int value);
void				stack_add_bottom(t_stack **stack, int value);
int					stack_size(t_stack *stack);
void				assign_index(t_stack *stack);
int					is_sorted(t_stack *stack);
t_stack				*find_min(t_stack *stack);
t_stack				*find_max(t_stack *stack);

// Операции
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

// Алгоритм
void				push_swap(t_stack **a, t_stack **b);
void				turk_algorithm(t_stack **a, t_stack **b);
void				sort_three(t_stack **a);
t_stack				*find_target(t_stack *a, int value_from_b);
void				find_all_targets(t_stack *a, t_stack *b);
void				calculate_all_costs(t_stack *a, t_stack *b);
t_stack				*find_cheapest(t_stack *b);
void				move_cheapest(t_stack **a, t_stack **b);
void				final_rotation(t_stack **a);

// Ошибки
void				error_exit(char *msg, t_stack *a, t_stack *b);
void				free_stack(t_stack *stack);

#endif
