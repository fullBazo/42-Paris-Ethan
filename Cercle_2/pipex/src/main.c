/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:52:04 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/27 15:10:04 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	px;

	if (ac != 5)
	{
		ft_printf("Error, usage: ./pipex infile cmd1 cmd2 outfile\n");
		return (1);
	}
	px.fd_in = open(av[1], O_RDONLY);
	px.fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_fd_error(av, &px);
	pipe(px.pipefd);
	child_one(&px, av, envp);
	child_two(&px, av, envp);
	close(px.pipefd[0]);
	close(px.pipefd[1]);
	if (px.fd_in >= 0)
		close(px.fd_in);
	close(px.fd_out);
	wait(NULL);
	wait(NULL);
	return (0);
}
