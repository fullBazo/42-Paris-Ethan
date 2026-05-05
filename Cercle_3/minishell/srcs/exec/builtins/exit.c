/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:32:24 by rdupoix           #+#    #+#             */
/*   Updated: 2026/03/30 14:34:48 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

int			is_valid_exit_arg(char *str);

long long	ft_atol(char *str)
{
	long long	result;
	long long	digit;

	int (i) = 0;
	digit = 0;
	result = 0;
	if (!str)
		return (0);
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			i++;
	}
	while (ft_isdigit(str[i]))
	{
		digit = str[i] - 48;
		if (result > (LONG_MAX - digit) / 10)
			return (0);
		result = result * 10 + (str[i++] - 48);
	}
	return (1);
}

int	is_valid_exit_arg(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (!ft_atol(str))
		return (0);
	return (1);
}

void	exec_exit(t_shell *shell, t_cmd *cmd)
{
	int	code;

	code = shell->exit_stat;
	printf("exit\n");
	if (cmd->args[1] && is_valid_exit_arg(cmd->args[1]) == 0)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd->args[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		free_shell(shell);
		exit(2);
	}
	if (cmd->args[1] && cmd->args[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		shell->exit_stat = 1;
		return ;
	}
	if (cmd->args[1])
		code = ft_atoi(cmd->args[1]);
	free_shell(shell);
	exit(code & 255);
}
