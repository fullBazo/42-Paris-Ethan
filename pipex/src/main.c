/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:25:43 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/23 16:12:46 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	open_file(t_pipex *pipex, char **av)
{	
	pipex->fd_in = open(av[1], O_RDONLY);
	if (pipex->fd_in < 0)
		perror("Error\n");
	pipex->fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (pipex->fd_out < 0)
		perror("Error\n");
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*px;
	(void)ac;
	
	px = malloc(sizeof(t_pipex));
	if (!px)
		return(1);
	open_file(px, av);
	pipe(px->pipefd);
	if (fork() == 0)
	{
		dup2(px->fd_in, STDIN_FILENO);
		dup2(px->pipefd[1], STDOUT_FILENO);
		close(px->fd_in);        // ajoute
		close(px->fd_out);       // ajoute
		close(px->pipefd[0]);
		close(px->pipefd[1]);
		execve(tab_path(av[2], find_path(envp)), split_cmd(av[2]), envp);
		exit(1);                 // si execve échoue
	}
	if (fork() == 0)
	{
		dup2(px->pipefd[0], STDIN_FILENO);
		dup2(px->fd_out, STDOUT_FILENO);
		close(px->fd_in);        // ajoute
		close(px->fd_out);       // ajoute
		close(px->pipefd[0]);
		close(px->pipefd[1]);
		execve(tab_path(av[3], find_path(envp)), split_cmd(av[3]), envp);
		exit(1);                 // si execve échoue
	}
	// Parent : ferme TOUT
	close(px->fd_in);            // ajoute
	close(px->fd_out);           // ajoute
	close(px->pipefd[0]);
	close(px->pipefd[1]);
	wait(NULL);
	wait(NULL);
	free(px);                    // ajoute
	return (0);
}
