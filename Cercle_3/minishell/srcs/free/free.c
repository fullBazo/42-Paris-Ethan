/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 10:03:36 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/29 14:01:16 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

/*des fonctions de free quoi.. rien de fou*/
void	free_tokens(t_token *token)
{
	t_token	*next;

	while (token)
	{
		next = token->next;
		free(token->value);
		free(token);
		token = next;
	}
}

void	free_redir(t_redir *redir)
{
	t_redir	*next;

	while (redir)
	{
		next = redir->next;
		free(redir->file);
		if (redir->heredoc_file)
			free(redir->heredoc_file);
		free(redir);
		redir = next;
	}
}

void	free_cmds(t_cmd *cmd)
{
	t_cmd	*next;
	int		i;

	while (cmd)
	{
		next = cmd->next;
		if (cmd->args)
		{
			i = 0;
			while (cmd->args[i])
				free(cmd->args[i++]);
			free(cmd->args);
		}
		free_redir(cmd->redirs);
		free(cmd);
		cmd = next;
	}
}

void	free_shell(t_shell *shell)
{
	int	i;

	i = 0;
	if (shell->tokens)
		free_tokens(shell->tokens);
	if (shell->cmds)
		free_cmds(shell->cmds);
	while (shell->env[i])
		free(shell->env[i++]);
	free(shell->env);
	i = 0;
	while (shell->env_var[i])
		free(shell->env_var[i++]);
	free(shell->env_var);
	free(shell);
}
