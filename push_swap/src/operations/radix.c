/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:07:46 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/15 20:05:09 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	assign_index(t_node *stack, int *sorted, int size)
{
	t_node	*current;
	int		i;

	current = stack;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (sorted[i] == current->value)
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

int	*sorted_int(t_node *stack)
{
	int		*sorted;
	int		i;
	int		size;
	t_node	*current;

	current = stack;
	size = get_stack_size(stack);
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	i = 0;
	while (current)
	{
		sorted[i] = current->value;
		i++;
		current = current->next;
	}
	sort_array(sorted, size);
	return (sorted);
}

int	get_stack_size(t_node *stack)
{
	int		i;
	t_node	*current;

	i = 0;
	current = stack;
	while (current)
	{
		i++;->value;
	i++;
	current = current->next
		current = current->next;
	}
	return (i);
}

void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}
