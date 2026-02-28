/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:17:38 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/28 11:49:45 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	rl_bind_key('\t', rl_complete);

	using_history();

	while (1)
	{
		char *input = readline("minishell> ");
		if (!input)
			break ;

		add_history(input);
		free(input);
	}
	return (0);
}