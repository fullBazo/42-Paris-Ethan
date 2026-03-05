/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:44:52 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/05 14:42:45 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*new_token(char *value, t_type type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = ft_strdup(value);
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

// todo

// t_token	*tokenisation(char *line)
// {
// 	int i;
// 	int start;
// 	t_type type;
// 	t_token *token;

// 	i = -1;
// 	while (line[++i])
// 	{
// 		if (line[i] == '|' || line[i] == '<' || line[i] == '>')
// 		{
// 			new_token();
// 			\\ TODO
// 		}
// 		else
// 		{
// 			start = i;
// 			while ()
// 		}
// 	}
// }