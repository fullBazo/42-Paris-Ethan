/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:54:39 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/13 16:43:28 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}


void	fill_stack(t_node **stack, char **av)
{
	int		i;
	t_node	*new;
	t_node	*tmp;

	i = 1;
	if (!validate_args(av))
	{
		ft_printf("Error\n");
		exit(1);
	}
	while (av[i])
	{
		new = new_node(ft_atoi(av[i]));

		if (*stack == NULL)
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
	t_node *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

int	validate_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '+' || av[i][j] == '-')
		{
			j++;
			if (av[i][j] == '\0')
				return (0);
		}
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


