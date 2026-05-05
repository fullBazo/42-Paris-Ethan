/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:42:48 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/29 14:14:28 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

static void	remove_env_var(t_shell *shell, char *name, int len)
{
	int	i;

	i = 0;
	while (shell->env[i])
	{
		if (!ft_strncmp(shell->env[i], name, len) && (shell->env[i][len] == '='
			|| shell->env[i][len] == '\0'))
		{
			free(shell->env[i]);
			while (shell->env[i + 1])
			{
				shell->env[i] = shell->env[i + 1];
				i++;
			}
			shell->env[i] = NULL;
			return ;
		}
		else if (remove_exported(shell, name) == 1)
			return ;
		i++;
	}
}

void	exec_unset(t_cmd *cmd, t_shell *shell)
{
	char	*name;
	int		len;
	int		j;

	j = 1;
	if (!cmd->args[1])
		return ;
	while (cmd->args[j])
	{
		len = 0;
		name = var_name(cmd->args[j], &len);
		remove_env_var(shell, name, len);
		free(name);
		j++;
	}
}
