/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:15:31 by yyuskiv           #+#    #+#             */
/*   Updated: 2026/01/30 12:32:52 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both_stacks(t_stack **a, t_stack **b, t_stack *cheapest,
				int *sizes)
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0
		&& cheapest->index <= sizes[1] / 2
		&& cheapest->target->index <= sizes[0] / 2)
	{
		rr(a, b);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0
		&& cheapest->index > sizes[1] / 2
		&& cheapest->target->index > sizes[0] / 2)
	{
		rrr(a, b);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
}

void	move_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	int		sizes[2];

	cheapest = find_cheapest(*b);
	sizes[0] = stack_size(*a);
	sizes[1] = stack_size(*b);
	rotate_both_stacks(a, b, cheapest, sizes);
	while (cheapest->cost_a-- > 0)
		do_rotation(a, 1, cheapest->target->index > sizes[0] / 2);
	while (cheapest->cost_b-- > 0)
		do_rotation(b, 0, cheapest->index > sizes[1] / 2);
	pa(a, b);
}

void	final_rotation(t_stack **a)
{
	t_stack	*min;
	int		size;

	min = find_min(*a);
	size = stack_size(*a);
	while (*a != min)
		do_rotation(a, 1, min->index > size / 2);
}
