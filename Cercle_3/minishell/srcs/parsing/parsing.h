/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:57:23 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/31 10:46:41 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "includes/minishell.h"

/* token.c */
t_token		*new_token(char *value, t_type type);
t_token		*add_token(t_token **list, t_token *token);
t_token		*tokenisation(char *line, t_shell *shell);

/* parsing.c */
t_redir		*new_redir(char *file, t_type type);
t_redir		*add_redir(t_redir **list, t_redir *redir);
t_cmd		*new_cmd(void);
char		**add_arg(char **args, char *arg);
t_cmd		*parser(t_token *tokens);

/* utils_parsing.c */
bool		is_space(char c);
bool		is_operator(char c);
int			quote_state(char c, t_state *state);
void		skip_word(char *word, int *i);
void		skip_space(char *word, int *i);

/* utils_parsing2.c */
t_type		get_operator_type(char *line, int *i);
char		*extract_word(char *line, int start, int end, t_shell *shell);
int			check_quote(char *line);
int			check_syntax(t_token *tokens);

/* utils_parsing3.c */
int			is_redir(t_type type);
t_cmd		*handle_token(t_cmd *cmd, t_token **tokens);

/* expand.c */
char		*var_name(char *str, int *i);
char		*var_value(t_shell *shell, char *name);
t_expand	init_expand(t_shell *shell, int *i, int *j);
void		copy_to_buf(char *buf, int *j, char *value);
void		expand_in_buf(char *line, t_expand *exp);

/* utils_token.c */
t_token		*remove_empty_tokens(t_token *list);

#endif