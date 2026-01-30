/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:14:48 by yyuskiv           #+#    #+#             */
/*   Updated: 2026/01/30 12:26:42 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_all_costs(t_stack *a, t_stack *b)
{
	t_stack	*current;
	int		size_a;
	int		size_b;
	int		cost_a;
	int		cost_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	current = b;
	while (current)
	{
		if (current->index <= size_b / 2)
			cost_b = current->index;
		else
			cost_b = size_b - current->index;
		if (current->target->index <= size_a / 2)
			cost_a = current->target->index;
		else
			cost_a = size_a - current->target->index;
		current->cost_a = cost_a;
		current->cost_b = cost_b;
		current = current->next;
	}
}

t_stack	*find_cheapest(t_stack *b)
{
	t_stack	*current;
	t_stack	*cheapest;
	int		min_cost;
	int		total;

	current = b;
	cheapest = current;
	min_cost = current->cost_a + current->cost_b;
	while (current)
	{
		total = current->cost_a + current->cost_b;
		if (total < min_cost)
		{
			min_cost = total;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}
