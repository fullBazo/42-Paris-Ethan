/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:26:09 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/29 14:01:45 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

bool	is_operator(char c)
{
	return (c == 124 || c == 62 || c == 60);
}

int	quote_state(char c, t_state *state)
{
	if (*state == IN_SINGLE && c == 39)
	{
		*state = NO_QUOTE;
		return (1);
	}
	else if (*state == IN_DOUBLE && c == 34)
	{
		*state = NO_QUOTE;
		return (1);
	}
	else if (*state == NO_QUOTE && c == 39)
	{
		*state = IN_SINGLE;
		return (1);
	}
	else if (*state == NO_QUOTE && c == 34)
	{
		*state = IN_DOUBLE;
		return (1);
	}
	return (0);
}

void	skip_word(char *word, int *i)
{
	t_state	state;

	state = NO_QUOTE;
	while (word[*i])
	{
		if (state == NO_QUOTE && (is_space(word[*i]) || is_operator(word[*i])))
			break ;
		quote_state(word[*i], &state);
		(*i)++;
	}
}

void	skip_space(char *word, int *i)
{
	while (is_space(word[*i]))
		(*i)++;
}
