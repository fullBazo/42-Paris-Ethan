/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:16:28 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/31 11:03:38 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void	error_cmd(t_cmd *cmd, t_shell *shell)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd->args[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	free_shell(shell);
	exit(127);
}

void	error_cmd_pdenied(t_cmd *cmd, t_shell *shell)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd->args[0], 2);
	ft_putstr_fd(": Permission denied\n", 2);
	free_shell(shell);
	exit(126);
}

void	error_cmd_noexec(t_cmd *cmd, t_shell *shell)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd->args[0], 2);
	ft_putstr_fd(": cannot execute binary file\n", 2);
	free_shell(shell);
	exit(126);
}
