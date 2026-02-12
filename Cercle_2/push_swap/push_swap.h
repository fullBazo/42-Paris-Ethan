/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:34:46 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/15 20:36:37 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

void	is_new_null(t_node *node);
void	fill_stack(t_node **stack, char **av);
t_node	*new_node(int value);
void	swap(t_node **stack);
void	reverse_rotate(t_node **stack);
void	assign_index(t_node *stack, int *sorted, int size);
int		*sorted_int(t_node *stack);
int		get_stack_size(t_node *stack);
void	sort_array(int *array, int size);
void	push_swap(t_node **stack_a, t_node **stack_b);
void	radix_sort(t_node **a, t_node **b);
int		get_max_bits(int max_index);
int		is_sorted(t_node *stack);
void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rra(t_node **a);
void	free_stack(t_node *stack);
void	sa(t_node **a);
void	sb(t_node **b);
int		ft_atol(const char *str, int *out);
void	is_max_min(t_node *stack, char *str, int *out);
int		get_max_index(t_node *a);
void	sort_3(t_node **a);
void	sort_5(t_node **a, t_node **b);
int		get_min_index(t_node *a);

#endif
