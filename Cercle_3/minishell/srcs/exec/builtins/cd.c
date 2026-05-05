/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:44:24 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/29 14:13:54 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void	exec_cd(t_shell *shell, t_cmd *cmd)
{
	char	*home;

	if (!cmd->args[1])
	{
		home = var_value(shell, "HOME");
		if (!home)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			shell->exit_stat = 1;
			return ;
		}
		chdir(home);
	}
	else if (cmd->args[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		shell->exit_stat = 1;
		return ;
	}
	else if (chdir(cmd->args[1]))
	{
		shell->exit_stat = 1;
		perror("cd");
	}
}
