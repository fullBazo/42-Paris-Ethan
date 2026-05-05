/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:57:43 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/31 10:46:35 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "includes/minishell.h"

/* sig.c */
void		setup_signals(void);
void		sigint_handler(int signal);
void		sigint_exec_handler(int signal);
void		sigint_heredoc_handler(int signal);

/* utils_sig.c */
void		update_exit_stat(t_shell *shell, int status);

#endif