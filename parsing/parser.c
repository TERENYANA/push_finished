/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:06:16 by yyuskiv           #+#    #+#             */
/*   Updated: 2026/01/30 14:31:00 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*stack;
	long	num;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			error_exit("Error\n", stack, NULL);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_exit("Error\n", stack, NULL);
		if (has_duplicate(stack, (int)num))
			error_exit("Error\n", stack, NULL);
		stack_add_bottom(&stack, (int)num);
		i++;
	}
	return (stack);
}