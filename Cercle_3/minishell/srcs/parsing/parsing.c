/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:44:52 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/29 14:01:35 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*init de la redir*/
t_redir	*new_redir(char *file, t_type type)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->file = ft_strdup(file);
	redir->heredoc_file = NULL;
	redir->quoted = 0;
	redir->type = type;
	redir->next = NULL;
	return (redir);
}

/*init de la commande*/
t_cmd	*new_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->redirs = NULL;
	cmd->next = NULL;
	return (cmd);
}

/*ajouter le node redir*/
t_redir	*add_redir(t_redir **list, t_redir *redir)
{
	t_redir	*last;

	if (!*list)
	{
		*list = redir;
		return (*list);
	}
	last = *list;
	while (last->next)
		last = last->next;
	last->next = redir;
	return (*list);
}

/*Dans le cas ou le token sur lequel on pointe est de type WORD,
 on l'ajoute aux args*/
char	**add_arg(char **args, char *arg)
{
	int	n;

	n = 0;
	while (args && args[n])
		n++;
	args = ft_realloc(args, sizeof(char *) * n, sizeof(char *) * (n + 2));
	args[n] = ft_strdup(arg);
	args[n + 1] = NULL;
	return (args);
}

/*on prend tout ce qui est au dessus et ca parse,
 comme ca romain il recup et pam*/
t_cmd	*parser(t_token *tokens)
{
	t_cmd	*list;
	t_cmd	*cmd;

	cmd = new_cmd();
	list = cmd;
	while (tokens)
	{
		cmd = handle_token(cmd, &tokens);
		tokens = tokens->next;
	}
	return (list);
}
