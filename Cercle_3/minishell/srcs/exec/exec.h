/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:56:30 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/31 10:46:52 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "includes/minishell.h"

/* exec_common.c */
void		exec_process(t_cmd *cmd, t_shell *shell);
void		exec_builtins(t_cmd *cmd, t_shell *shell);
void		check_direct_path(t_cmd *cmd, t_shell *shell);

/* exec_pipe.c */
void		exec_pipe_cmd(t_cmd *cmd, t_shell *shell, int *prev_fd);
void		exec_pipeline(t_cmd *cmd, t_cmd *start, t_shell *shell);

/* exec_single.c */
void		execute(t_cmd *cmd, t_shell *shell);

/* builtins */
int			echo_op_count(t_cmd *cmd);
void		exec_echo(t_cmd *cmd);
void		exec_env(t_shell *shell);
void		exec_unset(t_cmd *cmd, t_shell *shell);
void		exec_export(t_shell *shell);
void		exec_exit(t_shell *shell, t_cmd *cmd);
void		exec_cd(t_shell *shell, t_cmd *cmd);
void		exec_pwd(void);
int			update_existing_var(t_shell *shell, t_cmd *cmd, int i, int len);
void		exec_export_arg(t_shell *shell, t_cmd *cmd);

/* error.c */
void		error_cmd(t_cmd *cmd, t_shell *shell);
void		error_cmd_pdenied(t_cmd *cmd, t_shell *shell);
void		error_cmd_noexec(t_cmd *cmd, t_shell *shell);

/* find_path.c */
char		*find_path(t_shell *shell, t_cmd *cmd);

/* utils */
void		free_tab(char **tab);
t_builtin	is_builtin(t_cmd *cmd);
t_shell		*init_shell(char **envp);
void		setup_pipe(t_cmd *cmd, int pipe_fd[], int prev_fd);
int			remove_exported(t_shell *shell, char *name);
void		add_exported(t_shell *shell, char *name);
int			export_var(t_shell *shell, char *arg, int len, int i);
int			is_numeric(char *str);
int			has_quotes(char *line, int start, int end);

/* redirs */
int			setup_redirs(t_cmd *cmd);

/* heredoc */
char		*make_heredoc_name(int count);
int			collect_heredoc(t_cmd *cmd, t_shell *shell);
void		cleanup_heredocs(t_cmd *cmd);
void		heredoc_loop(int fd, char *delim, int quoted, t_shell *shell);
char		*expand_heredoc_line(char *line, t_shell *shell);

#endif