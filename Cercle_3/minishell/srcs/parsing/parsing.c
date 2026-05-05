/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:44:52 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/06 13:19:40 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*new_token(char *value, t_type type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = value;
	token->type = type;
	token->next = NULL;
	return (token);
}

t_token	*add_token(t_token **list, t_token *token)
{
	t_token	*last;

	if (!*list)
	{
		*list = token;
		return (*list);
	}
	last = *list;
	while (last->next)
		last = last->next;
	last->next = token;
	return (*list);
}

t_token	*tokenisation(char *line)
{
	int		start;
	t_type	type;
	t_token	*token;

	int (i) = 0;
	t_token *(list) = NULL;
	while (line[i])
	{
		skip_space(line, &i);
		if (is_operator(line[i]))
		{
			start = i;
			type = get_operator_type(line, &i);
			token = new_token(ft_substr(line, start, i - start), type);
			add_token(&list, token);
		}
		else
		{
			start = i;
			skip_word(line, &i);
			if (i > start)
			{
				token = new_token(ft_substr(line, start, i - start), WORD);
				add_token(&list, token);
			}
		}
	}
	return (list);
}
