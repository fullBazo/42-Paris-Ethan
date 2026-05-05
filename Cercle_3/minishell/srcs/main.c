/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:17:38 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/31 10:45:55 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int	handle_line(char *line, t_token *tokens, t_shell *shell)
{
	if (!tokens)
	{
		free(line);
		free_tokens(tokens);
		shell->exit_stat = 0;
		return (1);
	}
	else if (check_syntax(tokens))
	{
		free(line);
		free_tokens(tokens);
		shell->exit_stat = 2;
		return (1);
	}
	return (0);
}

static int	line_null(t_shell *shell)
{
	int	code;

	code = 0;
	printf("exit\n");
	code = shell->exit_stat;
	free_shell(shell);
	return (code);
}

static void	main_exec(t_shell *shell, t_token *tokens, char *line)
{
	t_cmd	*cmds;

	cmds = parser(tokens);
	shell->tokens = tokens;
	shell->cmds = cmds;
	execute(cmds, shell);
	free_tokens(shell->tokens);
	cleanup_heredocs(cmds);
	free_cmds(shell->cmds);
	shell->tokens = NULL;
	shell->cmds = NULL;
	free(line);
}

static void	check_signal(t_shell *shell)
{
	if (g_signal == SIGINT)
	{
		shell->exit_stat = 130;
		g_signal = 0;
	}
}

int	main(int ac, char **av, char **envp)
{
	char	*line;
	t_shell	*shell;
	t_token	*tokens;

	(void)ac;
	(void)av;
	if (!(isatty(STDIN_FILENO) && isatty(STDOUT_FILENO)))
		return (0);
	shell = init_shell(envp);
	setup_signals();
	while (1)
	{
		line = readline("minishell$ ");
		check_signal(shell);
		if (!line)
			return (line_null(shell));
		if (*line)
			add_history(line);
		tokens = tokenisation(line, shell);
		tokens = remove_empty_tokens(tokens);
		if (handle_line(line, tokens, shell))
			continue ;
		main_exec(shell, tokens, line);
	}
	return (0);
}
