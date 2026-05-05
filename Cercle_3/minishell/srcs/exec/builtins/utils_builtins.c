/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:46:46 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/29 14:14:44 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

t_builtin	is_builtin(t_cmd *cmd)
{
	if (cmd->args == NULL)
		return (cmd->builtin = NO_BUILTIN);
	if (cmd->args[0])
	{
		if (!ft_strncmp(cmd->args[0], "echo", 5))
			return (cmd->builtin = IS_ECHO);
		else if (!ft_strncmp(cmd->args[0], "cd", 3))
			return (cmd->builtin = IS_CD);
		else if (!ft_strncmp(cmd->args[0], "pwd", 4))
			return (cmd->builtin = IS_PWD);
		else if (!ft_strncmp(cmd->args[0], "export", 7))
			return (cmd->builtin = IS_EXPORT);
		else if (!ft_strncmp(cmd->args[0], "unset", 6))
			return (cmd->builtin = IS_UNSET);
		else if (!ft_strncmp(cmd->args[0], "env", 4))
			return (cmd->builtin = IS_ENV);
		else if (!ft_strncmp(cmd->args[0], "exit", 5))
			return (cmd->builtin = IS_EXIT);
	}
	return (cmd->builtin = NO_BUILTIN);
}
