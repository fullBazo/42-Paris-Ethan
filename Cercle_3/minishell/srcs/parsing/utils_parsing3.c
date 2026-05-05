/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:29:50 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/29 14:01:57 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*utilitaire pour return le type de redir*/
int	is_redir(t_type type)
{
	return (type == REDIR_IN || type == REDIR_APP || type == REDIR_OUT
		|| type == HEREDOC);
}

/*permet au parser de pas faire 400 lignes avec cette norme de merde*/
t_cmd	*handle_token(t_cmd *cmd, t_token **tokens)
{
	t_redir	*redir;

	if ((*tokens)->type == WORD)
		cmd->args = add_arg(cmd->args, (*tokens)->value);
	else if ((*tokens)->type == PIPE)
	{
		cmd->next = new_cmd();
		cmd = cmd->next;
	}
	else if (is_redir((*tokens)->type) && (*tokens)->next)
	{
		redir = new_redir((*tokens)->next->value, (*tokens)->type);
		if ((*tokens)->type == HEREDOC)
			redir->quoted = (*tokens)->next->quoted;
		add_redir(&cmd->redirs, redir);
		*tokens = (*tokens)->next;
	}
	return (cmd);
}
