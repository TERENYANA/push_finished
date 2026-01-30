/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyuskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:55:48 by yyuskiv           #+#    #+#             */
/*   Updated: 2026/01/30 14:59:11 by yyuskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = parse_args(ac, av);
	if (!a)
		return (0);
	b = NULL;
	if (is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	push_swap(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
