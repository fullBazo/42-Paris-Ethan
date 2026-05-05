/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:58:11 by rdupoix           #+#    #+#             */
/*   Updated: 2026/03/29 14:13:25 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	set_default_env(t_shell *shell)
{
	char	*cwd;
	char	*path;

	path = ft_strdup("/usr/sbin:/usr/bin:/sbin:/bin");
	cwd = getcwd(NULL, 0);
	shell->env = malloc(sizeof(char *) * 4);
	shell->env[0] = ft_strjoin("PWD=", cwd);
	shell->env[1] = ft_strdup("SHLVL=1");
	shell->env[2] = ft_strjoin("PATH=/usr/local/sbin:/usr/local/bin:", path);
	shell->env[3] = NULL;
}

static void	init_shell_defaults(t_shell *shell)
{
	shell->env_var = malloc(sizeof(char *) * 2);
	shell->env_var[0] = NULL;
	shell->env_var[1] = NULL;
	shell->exit_stat = 0;
	shell->stdin_fd = -1;
	shell->stdout_fd = -1;
	shell->tokens = NULL;
	shell->cmds = NULL;
}

t_shell	*init_shell(char **envp)
{
	int		i;
	t_shell	*shell;

	i = 0;
	shell = malloc(sizeof(t_shell));
	init_shell_defaults(shell);
	if (!envp[0])
	{
		set_default_env(shell);
		return (shell);
	}
	else
	{
		while (envp[i])
			i++;
		shell->env = malloc(sizeof(char *) * (i + 1));
		i = 0;
		while (envp[i])
		{
			shell->env[i] = ft_strdup(envp[i]);
			i++;
		}
		shell->env[i] = 0;
	}
	return (shell);
}

void	setup_pipe(t_cmd *cmd, int pipe_fd[], int prev_fd)
{
	if (prev_fd != -1)
	{
		dup2(prev_fd, STDIN_FILENO);
		close(prev_fd);
	}
	if (cmd->next)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
	}
	else if (pipe_fd[0] != -1)
		close(pipe_fd[0]);
}
