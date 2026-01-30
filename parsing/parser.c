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

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atol(char *str)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

int	has_duplicate(t_stack *stack, int num)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		if (current->value == num)
			return (1);
		current = current->next;
	}
	return (0);
}

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
