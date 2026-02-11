/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:10:53 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/27 15:29:40 by ehuet            ###   ########.fr       */
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
}	t_pipex;

char	**split_cmd(char *av);
char	**find_path(char **envp);
char	*tab_path(char *cmd, char **path);
void	ft_free(char **to_free);
void	child_one(t_pipex *px, char **av, char **envp);
void	child_two(t_pipex *px, char **av, char **envp);
void	exec_cmd(char *cmd, char **envp);
void	ft_fd_error(char **av, t_pipex *px);
void	open_file(t_pipex *pipex, char **av);
void	command_notx(char **args, char *cmd);
void	command_notfound(char **args);

#endif
