/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:23:38 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/31 11:02:50 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*init du token*/
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

/*on l'add dans notre liste chainee... yi haaa*/
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

/*encore une fonction a la con qui permet a la norminette de fermer sa gueule*/
static void	handle_word(char *line, int *i, t_shell *shell, t_token **list)
{
	int		start;
	t_token	*token;

	start = *i;
	skip_word(line, i);
	if (*i > start)
	{
		token = new_token(extract_word(line, start, *i, shell), WORD);
		token->quoted = has_quotes(line, start, *i);
		add_token(list, token);
	}
}

/*tokenisation de chacun des args de notre input via readline*/
t_token	*tokenisation(char *line, t_shell *shell)
{
	int		start;
	t_type	type;
	t_token	*token;

	t_token *(list) = NULL;
	int (i) = 0;
	if (check_quote(line))
		return (NULL);
	while (line[i])
	{
		skip_space(line, &i);
		if (is_operator(line[i]))
		{
			start = i;
			type = get_operator_type(line, &i);
			token = new_token(extract_word(line, start, i, shell), type);
			add_token(&list, token);
		}
		else
			handle_word(line, &i, shell, &list);
	}
	return (list);
}
