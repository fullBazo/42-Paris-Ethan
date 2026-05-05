/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils_heredoc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:01:32 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/31 11:03:14 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void	cleanup_heredocs(t_cmd *cmd)
{
	t_redir	*redir;

	while (cmd)
	{
		redir = cmd->redirs;
		while (redir)
		{
			if (redir->type == HEREDOC && redir->heredoc_file)
				unlink(redir->heredoc_file);
			redir = redir->next;
		}
		cmd = cmd->next;
	}
}

static void	heredoc_eof_warning(char *delim)
{
	ft_putstr_fd("minishell: warning: here-document"
		" delimited by end-of-file (wanted `",
		2);
	ft_putstr_fd(delim, 2);
	ft_putstr_fd("')\n", 2);
}

static char	*process_heredoc_line(char *line, int quoted, t_shell *shell)
{
	char	*expanded;

	if (!quoted)
	{
		expanded = expand_heredoc_line(line, shell);
		free(line);
		return (expanded);
	}
	return (line);
}

void	heredoc_loop(int fd, char *delim, int quoted, t_shell *shell)
{
	char	*line;
	int		len;

	len = ft_strlen(delim);
	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strncmp(line, delim, len + 1))
		{
			if (!line && g_signal != SIGINT)
				heredoc_eof_warning(delim);
			free(line);
			break ;
		}
		line = process_heredoc_line(line, quoted, shell);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
}

char	*expand_heredoc_line(char *line, t_shell *shell)
{
	t_expand	exp;
	char		*result;
	int			i;
	int			j;

	i = 0;
	j = 0;
	exp = init_expand(shell, &i, &j);
	if (!exp.buf)
		return (NULL);
	while (line[i])
	{
		if (line[i] == '$')
			expand_in_buf(line, &exp);
		else
			exp.buf[j++] = line[i++];
	}
	exp.buf[j] = '\0';
	result = ft_strdup(exp.buf);
	free(exp.buf);
	return (result);
}
