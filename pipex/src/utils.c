/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 utils.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ehuet <ehuet@student.42.fr>				+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/01/26 10:26:22 by ehuet			   #+#	  #+#			  */
/*	 Updated: 2026/01/26 13:46:42 by ehuet			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free(char **to_free)
{
	int	i;

	i = 0;
	if (!to_free)
		return ;
	while(to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}

void	ft_fd_error(char **av, t_pipex *px)
{
	if (px->fd_in < 0)
	{
		perror(av[1]);
		exit(1);
	}
	if (px->fd_out < 0)
	{
		perror(av[4]);
		exit(1);
	}

}
