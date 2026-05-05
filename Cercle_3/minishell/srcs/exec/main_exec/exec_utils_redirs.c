/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_redirs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:00:00 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/29 14:00:48 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

static int	redir_input(t_redir *redir)
{
	int	fd;

	fd = open(redir->file, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

static int	redir_output(t_redir *redir, int flags)
{
	int	fd;

	fd = open(redir->file, flags, OUTFILE_PERMS);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

static void	redir_heredoc(t_redir *redir)
{
	int	fd;

	fd = open(redir->heredoc_file, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return ;
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}

int	setup_redirs(t_cmd *cmd)
{
	t_redir	*redir;

	redir = cmd->redirs;
	while (redir)
	{
		if (redir->type == REDIR_IN)
		{
			if (redir_input(redir) != 0)
				return (1);
		}
		else if (redir->type == REDIR_OUT)
		{
			if (redir_output(redir, O_WRONLY | O_CREAT | O_TRUNC) != 0)
				return (1);
		}
		else if (redir->type == REDIR_APP)
		{
			if (redir_output(redir, O_WRONLY | O_CREAT | O_APPEND) != 0)
				return (1);
		}
		else if (redir->type == HEREDOC)
			redir_heredoc(redir);
		redir = redir->next;
	}
	return (0);
}
