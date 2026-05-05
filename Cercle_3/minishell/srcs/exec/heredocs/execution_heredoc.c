/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:53:06 by rdupoix           #+#    #+#             */
/*   Updated: 2026/03/29 14:00:20 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

char	*make_heredoc_name(int count)
{
	char	*to_add;
	char	*file;

	to_add = ft_itoa(count);
	file = ft_strjoin("/tmp/._heredoc_", to_add);
	free(to_add);
	return (file);
}

static void	create_heredoc_file(int *fd, int count)
{
	char	*file;

	file = make_heredoc_name(count);
	*fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd < 0)
		perror("open");
	free(file);
}

static void	read_heredoc(t_redir *redir, t_shell *shell, int count)
{
	int	fd;

	fd = -1;
	create_heredoc_file(&fd, count);
	if (fd < 0)
		return ;
	heredoc_loop(fd, redir->file, redir->quoted, shell);
	close(fd);
}

static int	fork_heredoc(t_redir *redir, t_shell *shell, int count)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, sigint_heredoc_handler);
		read_heredoc(redir, shell, count);
		free_shell(shell);
		if (g_signal == SIGINT)
			exit(130);
		exit(0);
	}
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	setup_signals();
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
	{
		shell->exit_stat = 130;
		write(1, "\n", 1);
		return (1);
	}
	redir->heredoc_file = make_heredoc_name(count);
	return (0);
}

int	collect_heredoc(t_cmd *cmd, t_shell *shell)
{
	t_redir	*redir;
	int		count;

	count = 0;
	while (cmd)
	{
		redir = cmd->redirs;
		while (redir)
		{
			if (redir->type == HEREDOC)
			{
				if (fork_heredoc(redir, shell, count) != 0)
					return (1);
				count++;
			}
			redir = redir->next;
		}
		cmd = cmd->next;
	}
	return (0);
}
