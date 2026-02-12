/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:09:08 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/27 16:02:48 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free(char **to_free)
{
	int	i;

	i = 0;
	if (!to_free)
		return ;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}

void	ft_fd_error(char **av, t_pipex *px)
{
	if (px->fd_in < 0)
		perror(av[1]);
	if (px->fd_out < 0)
	{
		perror(av[4]);
		if (px->fd_in >= 0)
			close(px->fd_in);
		exit(1);
	}
}

void	command_notx(char **args, char *cmd)
{
	if (access(cmd, X_OK) < 0)
	{
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": ", 2);
		perror("");
		ft_free(args);
		free(cmd);
		exit(126);
	}
	return ;
}

void	command_notfound(char **args)
{
	ft_putstr_fd(": command not found\n", 2);
	ft_free(args);
	exit(127);
}
