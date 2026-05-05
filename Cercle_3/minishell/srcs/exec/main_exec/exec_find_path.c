/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_find_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:45:14 by rdupoix           #+#    #+#             */
/*   Updated: 2026/03/29 14:00:35 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

static char	**get_complete_path(t_shell *shell)
{
	char	**path;
	int		i;

	i = 0;
	path = NULL;
	if (shell->env[i])
	{
		while (shell->env[i])
		{
			if (!ft_strncmp(shell->env[i], "PATH=", 5))
			{
				path = ft_split(shell->env[i] + 5, ':');
				return (path);
			}
			i++;
		}
	}
	return (path);
}

char	*find_path(t_shell *shell, t_cmd *cmd)
{
	char	**path;
	char	*to_exec;
	char	*tmp;
	int		i;

	i = 0;
	path = get_complete_path(shell);
	if (!path)
		return (NULL);
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		to_exec = ft_strjoin(tmp, cmd->args[0]);
		if (!access(to_exec, X_OK))
			return (free(tmp), free_tab(path), to_exec);
		free(tmp);
		free(to_exec);
		i++;
	}
	return (free_tab(path), NULL);
}

void	check_direct_path(t_cmd *cmd, t_shell *shell)
{
	struct stat	sb;

	if (stat(cmd->args[0], &sb) == 0 && S_ISDIR(sb.st_mode))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->args[0], 2);
		ft_putstr_fd(": Is a directory\n", 2);
		free_shell(shell);
		exit(126);
	}
	execve(cmd->args[0], cmd->args, shell->env);
	if (errno == EACCES || errno == EISDIR)
		error_cmd_pdenied(cmd, shell);
	if (errno == ENOEXEC)
		error_cmd_noexec(cmd, shell);
	error_cmd(cmd, shell);
}
