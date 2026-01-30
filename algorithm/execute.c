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

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0
		&& cheapest->index <= stack_size(*b) / 2
		&& cheapest->target->index <= stack_size(*a) / 2)
	{
		rr(a, b);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
}

static void	reverse_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0
		&& cheapest->index > stack_size(*b) / 2
		&& cheapest->target->index > stack_size(*a) / 2)
	{
		rrr(a, b);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
}

static void	rotate_a(t_stack **a, t_stack *cheapest)
{
	while (cheapest->cost_a > 0)
	{
		if (cheapest->target->index <= stack_size(*a) / 2)
			ra(a);
		else
			rra(a);
		cheapest->cost_a--;
	}
}

static void	rotate_b(t_stack **b, t_stack *cheapest)
{
	while (cheapest->cost_b > 0)
	{
		if (cheapest->index <= stack_size(*b) / 2)
			rb(b);
		else
			rrb(b);
		cheapest->cost_b--;
	}
}

void	move_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*b);
	rotate_both(a, b, cheapest);
	reverse_both(a, b, cheapest);
	rotate_a(a, cheapest);
	rotate_b(b, cheapest);
	pa(a, b);
}

void	final_rotation(t_stack **a)
{
	t_stack	*min;
	int		size;

	min = find_min(*a);
	size = stack_size(*a);
	while (*a != min)
	{
		if (min->index <= size / 2)
			ra(a);
		else
			rra(a);
	}
}
