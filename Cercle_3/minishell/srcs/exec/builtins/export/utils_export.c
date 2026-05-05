/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:15:58 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/29 14:00:01 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../exec.h"

int	remove_exported(t_shell *shell, char *name)
{
	int	i;

	i = 0;
	while (shell->env_var[i])
	{
		if (ft_strncmp(shell->env_var[i], name, ft_strlen(name)) == 0)
		{
			free(shell->env_var[i]);
			while (shell->env_var[i + 1])
			{
				shell->env_var[i] = shell->env_var[i + 1];
				i++;
			}
			shell->env_var[i] = NULL;
			return (1);
		}
		i++;
	}
	return (0);
}

void	add_exported(t_shell *shell, char *name)
{
	int	i;

	i = 0;
	while (shell->env_var[i])
	{
		if (ft_strncmp(shell->env_var[i], name, ft_strlen(name)) == 0)
			return ;
		i++;
	}
	shell->env_var = ft_realloc(shell->env_var, sizeof(char *) * (i + 2),
			sizeof(char *) * (i + 3));
	shell->env_var[i] = ft_strdup(name);
	shell->env_var[i + 1] = NULL;
}

int	export_var(t_shell *shell, char *arg, int len, int i)
{
	if (ft_strncmp(shell->env[i], arg, len) == 0
		&& (shell->env[i][len] == '=' || shell->env[i][len] == '\0'))
	{
		free(shell->env[i]);
		shell->env[i] = ft_strdup(arg);
		return (0);
	}
	return (1);
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_quotes(char *line, int start, int end)
{
	int	i;

	i = start;
	while (i < end)
	{
		if (line[i] == '\'' || line[i] == '"')
			return (1);
		i++;
	}
	return (0);
}
