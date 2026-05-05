/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:41:37 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/29 14:13:39 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

static int	is_n_flag(char *arg)
{
	int	j;

	j = 0;
	if (arg[j] != '-')
		return (0);
	j++;
	if (!arg[j])
		return (0);
	while (arg[j])
	{
		if (arg[j] != 'n')
			return (0);
		j++;
	}
	return (arg[j] == 0);
}

int	echo_op_count(t_cmd *cmd)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (cmd->args[i])
	{
		if (is_n_flag(cmd->args[i]))
			count++;
		else
			return (count);
		i++;
	}
	return (count);
}

static void	print_args(t_cmd *cmd, int start)
{
	int	i;

	i = start;
	while (cmd->args[i])
	{
		if (cmd->args[i + 1])
			printf("%s ", cmd->args[i]);
		else
			printf("%s", cmd->args[i]);
		i++;
	}
}

void	exec_echo(t_cmd *cmd)
{
	int	i;

	i = 1;
	if (cmd->args[1] && echo_op_count(cmd) > 0)
	{
		i += echo_op_count(cmd);
		print_args(cmd, i);
	}
	else
	{
		print_args(cmd, i);
		printf("\n");
	}
}
