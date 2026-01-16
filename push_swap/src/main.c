/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:07:06 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/15 20:35:41 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	has_duplicates(t_node *stack)
{
	t_node	*i;
	t_node	*j;

	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

void	push_swap(t_node **stack_a, t_node **stack_b, int ac)
{
	int	size;
	int	*sorted;

	size = get_stack_size(*stack_a);
	sorted = sorted_int(*stack_a);
	if (!sorted)
		return ;
	assign_index(*stack_a, sorted, size);
	if (is_sorted(*stack_a))
		free_stack(*stack_a);
	free(sorted);
	if (ac <= 4)
	{
		sort_3(stack_a);
		return ;
	}
	if (ac <= 6)
	{
		sort_5(stack_a, stack_b);
		return ;
	} 
	radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	fill_stack(&stack_a, argv);
	if (has_duplicates(stack_a))
	{
		write(2, "Error\n", 6);
		free_stack(stack_a);
		exit(1);
	}
	push_swap(&stack_a, &stack_b, argc);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
