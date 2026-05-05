/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:13:17 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/30 13:35:29 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* =============================== INCLUDES ================================ */

# include "libft/libft.h"
# include "struct.h"
# include "srcs/exec/exec.h"
# include "srcs/free/free.h"
# include "srcs/parsing/parsing.h"
# include "srcs/signals/signals.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>

/* ================================ MACROS ================================= */

# define OUTFILE_PERMS 0644

/* ============================== GLOBAL VAR =============================== */

extern int	g_signal;

#endif