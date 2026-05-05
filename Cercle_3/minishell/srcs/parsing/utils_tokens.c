/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:44:43 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/30 12:52:14 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_token	*remove_head(t_token *list)
{
	t_token	*tmp;

	while (list && list->type == WORD && !list->value[0] && !list->quoted)
	{
		tmp = list->next;
		free(list->value);
		free(list);
		list = tmp;
	}
	return (list);
}

t_token	*remove_empty_tokens(t_token *list)
{
	t_token	*prev;
	t_token	*current;

	list = remove_head(list);
	if (!list)
		return (NULL);
	prev = list;
	current = list->next;
	while (current)
	{
		if (current->type == WORD && !current->value[0] && !current->quoted)
		{
			prev->next = current->next;
			free(current->value);
			free(current);
			current = prev->next;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
	return (list);
}
