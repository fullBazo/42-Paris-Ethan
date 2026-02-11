/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:01:47 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/17 18:29:48 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
}

void	ra(t_node **a)
{
	t_node	*first;
	t_node	*cur;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	*a = first->next;
	first->next = NULL;
	cur = *a;
	while (cur->next)
		cur = cur->next;
	cur->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	t_node	*first;
	t_node	*cur;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	*b = first->next;
	first->next = NULL;
	cur = *b;
	while (cur->next)
		cur = cur->next;
	cur->next = first;
	write(1, "rb\n", 3);
}
