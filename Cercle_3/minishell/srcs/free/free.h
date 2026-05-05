/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:56:59 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/31 10:46:46 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "includes/minishell.h"

void		free_tokens(t_token *tokens);
void		free_redir(t_redir *redir);
void		free_cmds(t_cmd *cmd);
void		free_shell(t_shell *shell);

#endif