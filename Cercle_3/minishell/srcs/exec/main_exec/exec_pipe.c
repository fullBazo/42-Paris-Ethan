/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:00:00 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/29 14:00:39 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

static void	child_pipe(t_cmd *cmd, t_shell *shell, int *pfd, int prev_fd)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	setup_pipe(cmd, pfd, prev_fd);
	if (cmd->redirs && setup_redirs(cmd) != 0)
	{
		free_shell(shell);
		exit(1);
	}
	if (cmd->builtin == NO_BUILTIN)
		exec_process(cmd, shell);
	else
	{
		exec_builtins(cmd, shell);
		free_shell(shell);
		exit(0);
	}
}

static void	parent_pipe(int *prev_fd, int *pfd)
{
	if (*prev_fd != -1)
		close(*prev_fd);
	if (pfd[1] != -1)
		close(pfd[1]);
	if (pfd[0] != -1)
		*prev_fd = pfd[0];
}

void	exec_pipe_cmd(t_cmd *cmd, t_shell *shell, int *prev_fd)
{
	int	pfd[2];

	pfd[0] = -1;
	pfd[1] = -1;
	if (cmd->next)
	{
		if (pipe(pfd) == -1)
			perror("pipe");
	}
	signal(SIGINT, sigint_exec_handler);
	cmd->pid = fork();
	if (cmd->pid == -1)
		perror("fork");
	if (cmd->pid == 0)
		child_pipe(cmd, shell, pfd, *prev_fd);
	else
		parent_pipe(prev_fd, pfd);
}

static void	wait_pipes(t_cmd *start, t_shell *shell)
{
	int	status;

	while (start)
	{
		waitpid(start->pid, &status, 0);
		if (!start->next)
			update_exit_stat(shell, status);
		start = start->next;
	}
	setup_signals();
}

void	exec_pipeline(t_cmd *cmd, t_cmd *start, t_shell *shell)
{
	int	prev_fd;

	prev_fd = -1;
	while (cmd)
	{
		cmd->builtin = is_builtin(cmd);
		exec_pipe_cmd(cmd, shell, &prev_fd);
		cmd = cmd->next;
	}
	wait_pipes(start, shell);
}
