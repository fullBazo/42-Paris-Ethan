/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_common.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:00:00 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/31 09:47:10 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void	exec_process(t_cmd *cmd, t_shell *shell)
{
	char	*path;

	if (cmd->args == NULL)
	{
		free_shell(shell);
		exit(0);
	}
	if (!cmd->args[0][0])
		error_cmd(cmd, shell);
	if (ft_strchr(cmd->args[0], '/'))
		check_direct_path(cmd, shell);
	path = find_path(shell, cmd);
	if (!path)
		error_cmd(cmd, shell);
	execve(path, cmd->args, shell->env);
	free(path);
	if (errno == EACCES || errno == EISDIR)
		error_cmd_pdenied(cmd, shell);
	if (errno == ENOEXEC)
		error_cmd_noexec(cmd, shell);
	error_cmd(cmd, shell);
}

void	exec_builtins(t_cmd *cmd, t_shell *shell)
{
	if (cmd->builtin == IS_ECHO)
		exec_echo(cmd);
	else if (cmd->builtin == IS_CD)
		exec_cd(shell, cmd);
	else if (cmd->builtin == IS_PWD)
		exec_pwd();
	else if (cmd->builtin == IS_EXPORT)
		exec_export_arg(shell, cmd);
	else if (cmd->builtin == IS_ENV)
		exec_env(shell);
	else if (cmd->builtin == IS_UNSET)
		exec_unset(cmd, shell);
	else if (cmd->builtin == IS_EXIT)
		exec_exit(shell, cmd);
}
