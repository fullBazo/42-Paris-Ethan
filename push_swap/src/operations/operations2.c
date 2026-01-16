/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:58:41 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/15 20:07:04 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sb(t_node **b)
{
	t_node	*first;
	t_node	*second;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	second = (*b)->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	write(1, "sb\n", 3);
}

void	sa(t_node **a)
{
	t_node	*first;
	t_node	*second;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	write(1, "sa\n", 3);
}

void    rra(t_node **a)
{
    t_node *cur;
    t_node *last;

    if (!a || !*a || !(*a)->next)
        return ;
    cur = *a;
    while (cur->next->next)
        cur = cur->next;
    last = cur->next;
    cur->next = NULL;
    last->next = *a;
    *a = last;
	write(1, "rra\n", 4);
}

void    sort_3(t_node **a)
{
    int max;

    if (!a || !*a || !(*a)->next)
        return;
    max = get_max_index(*a);
    if ((*a)->index == max)
        ra(a);
    else if ((*a)->next->index == max)
        rra(a);
    if ((*a)->index > (*a)->next->index)
        sa(a);
}


void sort_5(t_node **a, t_node **b)
{
    int size;
    int min_index;
    int rotations;

    if (!a || !*a)
        return;
    size = get_stack_size(*a);
    while (size > 3)
    {
        min_index = get_min_index(*a);
        if (min_index <= size / 2)
        {
            rotations = min_index;
            while (rotations-- > 0)
                ra(a);
        }
        else
        {
            rotations = size - min_index;
            while (rotations-- > 0)
                rra(a);
        }
        pb(a, b);          
		size--;
	}
    sort_3(a);
    while (*b)
        pa(a, b);
}




