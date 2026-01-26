
/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 path.c												:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ehuet <ehuet@student.42.fr>				+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/01/20 14:49:20 by ehuet			   #+#	  #+#			  */
/*	 Updated: 2026/01/26 10:41:33 by ehuet			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../pipex.h"

char	**split_cmd(char *av)
{
	char	**res;

	res = ft_split(av, ' ');
	return (res);
}

char	**find_path(char **envp)
{
	char	*path_line;
	char	**path;

	path = NULL;
	while(*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			path_line = ft_substr(*envp, 5, ft_strlen(*envp + 5));
			path = ft_split(path_line, ':');
			free(path_line);
			return (path);
		}
		envp++;
	}
	return (NULL);
}

char	*tab_path(char *cmd, char **path)
{
	int		i;
	char	*cmd_path;
	char	*temp;
	char	**first_arg;

	i = 0;
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	first_arg = split_cmd(cmd);
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(temp, first_arg[0]);
		free(temp);
		if (access(cmd_path, X_OK) == 0)
		{
			ft_free(first_arg);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	ft_free(first_arg);
	return (cmd);
}
