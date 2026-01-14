/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:07:06 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/14 16:00:32 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_node *stack)
{
	t_node *tmp = stack;
	printf("Pile du top au bottom :\n");
	while (tmp)
	{
		printf("%d -> ", tmp->value);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

int	main(int ac, char **av)
{
	t_node *stack = NULL;

	if (ac < 2)
	{
		printf("Usage: %s numbers...\n", av[0]);
		return (0);
	}

	// Remplir la pile depuis les arguments
	fill_stack(&stack, av);

	// Afficher la pile pour vérifier
	print_stack(stack);

	return (0);
}
