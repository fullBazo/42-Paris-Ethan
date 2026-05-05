/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:05:12 by rdupoix           #+#    #+#             */
/*   Updated: 2026/03/29 14:15:07 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../exec.h"

static void	print_export_var(char *env_entry)
{
	char	*tmp;
	int		j;

	tmp = ft_strchr(env_entry, '=');
	if (!tmp)
	{
		printf("export %s\n", env_entry);
		return ;
	}
	j = 0;
	write(1, "export ", 7);
	while (env_entry[j] != '=')
		write(1, &env_entry[j++], 1);
	write(1, "=\"", 2);
	write(1, tmp + 1, ft_strlen(tmp + 1));
	write(1, "\"\n", 2);
}

void	exec_export(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->env[i])
	{
		print_export_var(shell->env[i]);
		i++;
	}
	i = 0;
	while (shell->env_var && shell->env_var[i])
		printf("export %s\n", shell->env_var[i++]);
}

int	export_valid_identifier(char *str)
{
	int	i;

	if (!str || (!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	update_existing_var(t_shell *shell, t_cmd *cmd, int i, int len)
{
	char	*name;
	int		j;

	j = 0;
	name = var_name(cmd->args[i], &len);
	while (shell->env[j])
	{
		if (export_var(shell, cmd->args[i], len, j) == 0)
		{
			free(name);
			return (1);
		}
		j++;
	}
	shell->env = ft_realloc(shell->env, sizeof(char *) * (j + 1), sizeof(char *)
			* (j + 2));
	shell->env[j] = ft_strdup(cmd->args[i]);
	shell->env[j + 1] = NULL;
	free(name);
	return (0);
}

void	exec_export_arg(t_shell *shell, t_cmd *cmd)
{
	int	len;
	int	i;

	len = 0;
	i = 1;
	if (!cmd->args[1])
		return (exec_export(shell));
	while (cmd->args[i])
	{
		if (!export_valid_identifier(cmd->args[i]))
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(cmd->args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			shell->exit_stat = 1;
			i++;
			continue ;
		}
		if (!ft_strchr(cmd->args[i], '='))
			add_exported(shell, cmd->args[i]);
		else
			update_existing_var(shell, cmd, i, len);
		i++;
	}
}
