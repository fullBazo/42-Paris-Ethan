/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:58:14 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/29 14:01:51 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*recuperation du type d'operateur*/
t_type	get_operator_type(char *line, int *i)
{
	if (line[*i] == '|')
		return (*i += 1, PIPE);
	else if (line[*i] == '>' && line[*i + 1] == '>')
		return (*i += 2, REDIR_APP);
	else if (line[*i] == '>')
		return (*i += 1, REDIR_OUT);
	else if (line[*i] == '<' && line[*i + 1] == '<')
		return (*i += 2, HEREDOC);
	else if (line[*i] == '<')
		return (*i += 1, REDIR_IN);
	return (ERROR);
}

/*extraction du mot si quotes ou expand*/
char	*extract_word(char *line, int start, int end, t_shell *shell)
{
	char		*result;
	t_expand	exp;

	t_state(state) = NO_QUOTE;
	int (i) = start;
	int (j) = 0;
	exp = init_expand(shell, &i, &j);
	if (!exp.buf)
		return (NULL);
	while (i < end)
	{
		if (quote_state(line[i], &state) == 1)
			i++;
		else if ((state == NO_QUOTE || state == IN_DOUBLE) && line[i] == '$')
			expand_in_buf(line, &exp);
		else
			exp.buf[j++] = line[i++];
	}
	exp.buf[j] = '\0';
	result = ft_strdup(exp.buf);
	free(exp.buf);
	return (result);
}

/*check des unclosed quotes*/
int	check_quote(char *line)
{
	t_state	state;

	int (i) = 0;
	state = NO_QUOTE;
	while (line[i])
		quote_state(line[i++], &state);
	if (state != NO_QUOTE)
	{
		ft_putstr_fd("minishell : unclosed quote\n", 2);
		return (1);
	}
	return (0);
}

/*check de la syntaxe, return une erreur ou rien*/
int	check_syntax(t_token *tokens)
{
	t_token	*prev;

	prev = NULL;
	while (tokens)
	{
		if (tokens->type == PIPE && prev == NULL)
			return (ft_putstr_fd("minishell : parse error near `|'\n", 2), 1);
		else if (tokens->type == PIPE && prev->type == PIPE)
			return (ft_putstr_fd("minishell : parse error near `|'\n", 2), 1);
		else if (tokens->type == PIPE && tokens->next == NULL)
			return (ft_putstr_fd("minishell : parse error near `|'\n", 2), 1);
		else if (is_redir(tokens->type) && tokens->next == NULL)
			return (ft_putstr_fd("minishell : parse error near `\\n'\n", 2), 1);
		else if (is_redir(tokens->type) && tokens->next->type == PIPE)
			return (ft_putstr_fd("minishell : parse error near `|'\n", 2), 1);
		else if (is_redir(tokens->type) && tokens->next->type != WORD)
			return (ft_putstr_fd("minishell : parse error near redir\n", 2), 1);
		prev = tokens;
		tokens = tokens->next;
	}
	return (0);
}
