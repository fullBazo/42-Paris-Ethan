/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:58:14 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/05 13:07:36 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = 0;
	return (s1);
}

bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

bool	is_operator(char c)
{
	return (c == 124 || c == 62 || c == 60);
}

void	quote_state(char c, t_state *state)
{
	if (state == IN_SINGLE && c == 39)
		state = NO_QUOTE;
	else if (state == IN_DOUBLE && c == 34)
		state = NO_QUOTE;
	else if (state == NO_QUOTE && c == 39)
		state = IN_SINGLE;
	else if (state == NO_QUOTE && c == 34)
		state = IN_DOUBLE;
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