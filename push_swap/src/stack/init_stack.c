/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:54:39 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/15 20:30:27 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	fill_stack(t_node **stack, char **av)
{
	int		i;
	t_node	*new;
	t_node	*tmp;
	int		value;

	i = 1;
	while (av[i])
	{
		is_max_min(*stack, av[i], &value);
		new = new_node(value);
		is_new_null(new);
		if (!*stack)
			*stack = new;
		else
		{
			tmp = *stack;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		i++;
	}
}

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	exit(0);
}
