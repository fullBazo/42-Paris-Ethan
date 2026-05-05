/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:27:49 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/29 14:02:15 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	update_exit_stat(t_shell *shell, int status)
{
	if (WIFSIGNALED(status))
	{
		shell->exit_stat = 128 + WTERMSIG(status);
		if (WTERMSIG(status) == SIGQUIT)
			write(2, "Quit (core dumped)\n", 19);
		else if (WTERMSIG(status) == SIGINT)
			write(1, "\n", 1);
	}
	else if (WIFEXITED(status))
		shell->exit_stat = WEXITSTATUS(status);
}
