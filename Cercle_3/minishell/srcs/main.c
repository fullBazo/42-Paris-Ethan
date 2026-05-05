/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:17:38 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/06 13:34:22 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// need un split pour parser les commandes

int	main(int ac, char **av)
{
	t_token *list;
	t_token *current;
	(void)ac;

	list = tokenisation(av[1]);
	current = list;
	while (current)
	{
		printf("value: [%s] | type: [%d]\n", current->value, current->type);
		current = current->next;
	}
}