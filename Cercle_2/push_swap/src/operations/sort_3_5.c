/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:20:47 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/17 17:22:12 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_3(t_node **a)
{
	int	max;

	if (!a || !*a || !(*a)->next)
		return ;
	max = get_max_index(*a);
	if ((*a)->index == max)
		ra(a);
	else if ((*a)->next->index == max)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

static void	push_min_to_b(t_node **a, t_node **b, int size)
{
	int	min;
	int	rot;

	min = get_min_index(*a);
	if (min <= size / 2)
	{
		rot = min;
		while (rot-- > 0)
			ra(a);
	}
	else
	{
		rot = size - min;
		while (rot-- > 0)
			rra(a);
	}
	pb(a, b);
}

void	sort_5(t_node **a, t_node **b)
{
	int	size;

	if (!a || !*a)
		return ;
	size = get_stack_size(*a);
	while (size-- > 3)
		push_min_to_b(a, b, size + 1);
	sort_3(a);
	while (*b)
		pa(a, b);
}
