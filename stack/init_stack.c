/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:34:03 by yyuskiv           #+#    #+#             */
/*   Updated: 2026/01/30 14:51:17 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->cost_b = 0;
	node->cost_a = 0;
	node->target = NULL;
	node->next = NULL;
	return (node);
}

void	stack_add_bottom(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*last;

	new = new_node(value);
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
}
