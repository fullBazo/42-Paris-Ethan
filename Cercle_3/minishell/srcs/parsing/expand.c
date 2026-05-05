/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:12:55 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/29 14:16:07 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*on recupere le nom de la variable*/
char	*var_name(char *str, int *i)
{
	int	start;

	start = *i;
	while (ft_isalnum(str[*i]) || str[*i] == '_')
		(*i)++;
	return (ft_substr(str, start, *i - start));
}

/*on parcours envp, et on return un pointeur
si on trouve une occurence avec le nom de la variable*/
char	*var_value(t_shell *shell, char *name)
{
	int (len) = strlen(name);
	int (i) = 0;
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], name, len) == 0
			&& shell->env[i][len] == '=')
			return (shell->env[i] + len + 1);
		i++;
	}
	return (NULL);
}

/*j'ai du faire une structure juste pour les expands mdrr
la norminette a detruit ma vie*/
t_expand	init_expand(t_shell *shell, int *i, int *j)
{
	t_expand	exp;

	exp.shell = shell;
	exp.i = i;
	exp.j = j;
	exp.buf = malloc(131072);
	return (exp);
}

/*encore une fonction qui bypass la norminette.. elle nous fait chier celle la*/
void	copy_to_buf(char *buf, int *j, char *value)
{
	int (k) = 0;
	while (value[k])
	{
		buf[*j] = value[k];
		(*j)++;
		k++;
	}
}

/*la fonction fait mal au crane mais c'est tranquille
juste pour gerer les variables*/
void	expand_in_buf(char *line, t_expand *exp)
{
	char	*value;
	char	*name;

	if (line[*exp->i + 1] == '?')
	{
		value = ft_itoa(exp->shell->exit_stat);
		copy_to_buf(exp->buf, exp->j, value);
		free(value);
		*exp->i += 2;
	}
	else if (ft_isalpha(line[*exp->i + 1]) || line[*exp->i + 1] == '_')
	{
		(*exp->i)++;
		name = var_name(line, exp->i);
		value = var_value(exp->shell, name);
		free(name);
		if (value)
			copy_to_buf(exp->buf, exp->j, value);
	}
	else
	{
		exp->buf[*exp->j] = '$';
		(*exp->j)++;
		(*exp->i)++;
	}
}
