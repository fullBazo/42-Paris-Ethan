/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:00:00 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/29 14:00:45 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

static void	child_single(t_cmd *cmd, t_shell *shell)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (cmd->redirs && setup_redirs(cmd) != 0)
	{
		free_shell(shell);
		exit(1);
	}
	exec_process(cmd, shell);
}

static void	exec_single_ext(t_cmd *cmd, t_shell *shell)
{
	int	status;

	status = 0;
	signal(SIGINT, sigint_exec_handler);
	cmd->pid = fork();
	if (cmd->pid == -1)
	{
		perror("Error");
		return ;
	}
	if (cmd->pid == 0)
		child_single(cmd, shell);
	waitpid(cmd->pid, &status, 0);
	update_exit_stat(shell, status);
	setup_signals();
}

static void	exec_single_builtin(t_cmd *cmd, t_shell *shell)
{
	if (!cmd->redirs)
	{
		exec_builtins(cmd, shell);
		return ;
	}
	shell->stdin_fd = dup(STDIN_FILENO);
	shell->stdout_fd = dup(STDOUT_FILENO);
	if (setup_redirs(cmd) != 0)
	{
		shell->exit_stat = 1;
		dup2(shell->stdin_fd, STDIN_FILENO);
		dup2(shell->stdout_fd, STDOUT_FILENO);
		close(shell->stdin_fd);
		close(shell->stdout_fd);
		return ;
	}
	exec_builtins(cmd, shell);
	dup2(shell->stdin_fd, STDIN_FILENO);
	dup2(shell->stdout_fd, STDOUT_FILENO);
	close(shell->stdin_fd);
	close(shell->stdout_fd);
}

void	execute(t_cmd *cmd, t_shell *shell)
{
	t_cmd	*start;

	start = cmd;
	shell->exit_stat = 0;
	if (collect_heredoc(cmd, shell) != 0)
		return ;
	if (!cmd->next)
	{
		cmd->builtin = is_builtin(cmd);
		if (cmd->builtin == NO_BUILTIN)
			exec_single_ext(cmd, shell);
		else
			exec_single_builtin(cmd, shell);
	}
	else
		exec_pipeline(cmd, start, shell);
	cleanup_heredocs(start);
}
