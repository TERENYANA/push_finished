/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:16:25 by yyuskiv           #+#    #+#             */
/*   Updated: 2026/01/30 13:36:20 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else
		turk_algorithm(a, b);
}

void	turk_algorithm(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
		pb(a, b);
	sort_three(a);
	while (*b)
	{
		assign_index(*a);
		assign_index(*b);
		find_all_targets(*a, *b);
		calculate_all_costs(*a, *b);
		move_cheapest(a, b);
	}
	final_rotation(a);
}
