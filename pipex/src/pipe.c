/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 pipe.c												:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ehuet <ehuet@student.42.fr>				+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/01/21 14:25:34 by ehuet			   #+#	  #+#			  */
/*	 Updated: 2026/01/21 14:45:21 by ehuet			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../pipex.h"

void	child_one(t_pipex *px, char **av, char **envp)
{
	if (fork() == 0)
	{
		open_file(px, av);
		if (px->fd_in >= 0)
			dup2(px->fd_in, STDIN_FILENO);
		dup2(px->pipefd[1], STDOUT_FILENO);
		close(px->pipefd[0]);
		close(px->pipefd[1]);
		if (px->fd_in >= 0)
			close(px->fd_in);
		close(px->fd_in);
		exec_cmd(av[2], envp);
		exit(1);
	}
}

void	child_two(t_pipex *px, char **av, char **envp)
{
	if (fork() == 0)
	{
		dup2(px->pipefd[0], STDIN_FILENO);
		dup2(px->fd_out, STDOUT_FILENO);
		close(px->pipefd[0]);
		close(px->pipefd[1]);
		if (px->fd_in >= 0)
			close(px->fd_in);
		close(px->fd_out);
		exec_cmd(av[3], envp);
		exit(1);
	}
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	**path;
	char	*cmd_path;

	args = split_cmd(cmd);
	path = find_path(envp);
	cmd_path = tab_path(cmd, path);
	if (access(cmd_path, X_OK) < 0)
	{
		write(2, " ", 1);
		ft_free(args);
		ft_free(path);
		exit(127);
	}
	ft_free(path);
	execve(cmd_path, args, envp);
	ft_free(args);
	free(cmd_path);
	exit(1);
}
