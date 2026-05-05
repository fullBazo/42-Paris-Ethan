/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 13:27:29 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/30 14:27:51 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>
# include <sys/types.h>

typedef struct s_shell	t_shell;

typedef enum e_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APP,
	HEREDOC,
	ERROR
}						t_type;

typedef enum e_builtin
{
	NO_BUILTIN,
	IS_ECHO,
	IS_CD,
	IS_PWD,
	IS_EXPORT,
	IS_UNSET,
	IS_ENV,
	IS_EXIT
}						t_builtin;

typedef enum e_state
{
	NO_QUOTE,
	IN_SINGLE,
	IN_DOUBLE
}						t_state;

typedef struct s_expand
{
	char				*buf;
	int					*i;
	int					*j;
	t_shell				*shell;
}						t_expand;

typedef struct s_token
{
	char				*value;
	t_type				type;
	int					quoted;
	struct s_token		*next;
}						t_token;

typedef struct s_redir
{
	char				*file;
	char				*heredoc_file;
	t_type				type;
	int					quoted;
	struct s_redir		*next;
}						t_redir;

typedef struct s_cmd
{
	char				**args;
	t_redir				*redirs;
	pid_t				pid;
	t_builtin			builtin;
	struct s_cmd		*next;
}						t_cmd;

struct					s_shell
{
	char				**env;
	char				**env_var;
	int					exit_stat;
	int					stdin_fd;
	int					stdout_fd;
	t_token				*tokens;
	t_cmd				*cmds;
};

#endif