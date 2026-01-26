/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:42:14 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/26 14:56:33 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		fd_in;
	int		fd_out;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

char    **split_cmd(char *av);
char	**find_path(char **envp);
char	*tab_path(char *cmd, char **path);
void	ft_free(char **to_free);
void	child_one(t_pipex *px, char **av, char **envp);
void	child_two(t_pipex *px, char **av, char **envp);
void	exec_cmd(char *cmd, char **envp);
void	ft_fd_error(char **av, t_pipex *px);
void	open_file(t_pipex *pipex, char **av);
#endif
