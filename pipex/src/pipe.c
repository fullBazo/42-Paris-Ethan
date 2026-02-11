/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:07:23 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/30 11:43:47 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child_one(t_pipex *px, char **av, char **envp)
{
	if (fork() == 0)
	{
		close(px->pipefd[0]);
		if (px->fd_in >= 0)
		{
			dup2(px->fd_in, STDIN_FILENO);
			close(px->fd_in);
		}
		if (px->fd_in < 0)
		{
			close(px->pipefd[1]);
			close(px->fd_out);
			exit(1);
		}
		dup2(px->pipefd[1], STDOUT_FILENO);
		close(px->pipefd[1]);
		if (px->fd_out >= 0)
			close(px->fd_out);
		exec_cmd(av[2], envp);
	}
}

void	child_two(t_pipex *px, char **av, char **envp)
{
	if (fork() == 0)
	{
		close(px->pipefd[1]);
		dup2(px->pipefd[0], STDIN_FILENO);
		close(px->pipefd[0]);
		dup2(px->fd_out, STDOUT_FILENO);
		close(px->fd_out);
		if (px->fd_in >= 0)
			close(px->fd_in);
		exec_cmd(av[3], envp);
	}
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	**path;
	char	*cmd_path;

	args = split_cmd(cmd);
	if (!args || !args[0])
		command_notfound(args);
	path = find_path(envp);
	cmd_path = tab_path(cmd, path);
	ft_free(path);
	if (!cmd_path)
	{
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_free(args);
		free(cmd_path);
		exit(127);
	}
	command_notx(args, cmd_path);
	execve(cmd_path, args, envp);
	ft_free(args);
	free(cmd_path);
	exit(1);
}
