/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:19:58 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/15 20:05:50 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_max_bits(int max_index)
{
	int	bits;

	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_node **a, t_node **b)
{
	int	size;
	int	max_bits;
	int	bit;
	int	count;

	size = get_stack_size(*a);
	max_bits = get_max_bits(size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		count = size;
		while (count > 0)
		{
			if (((*a)->index >> bit) & 1)
				ra(a);
			else
				pb(a, b);
			count--;
		}
		while (*b)
			pa(b, a);
		bit++;
	}
}

int	is_sorted(t_node *stack)
{
	t_node *current;

	current = stack;
	while (current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

int get_max_index(t_node *stack)
{
    int max;
    t_node *tmp;

    if (!stack)
        return (-1);
    tmp = stack;
    max = tmp->index;
	while (tmp)
    {
        if (tmp->index > max)
            max = tmp->index;
        tmp = tmp->next;
    }
    return max;
}

int get_min_index(t_node *a)
{
    int min;
    int min_index;
    int i;

    if (!a)
        return (-1);
    min = a->index;
    min_index = 0;
    i = 0;
    while (a)
    {
        if (a->index < min)
        {
            min = a->index;
            min_index = i;
        }
        a = a->next;
        i++;
    }
    return (min_index);
}
