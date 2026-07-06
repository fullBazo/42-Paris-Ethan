/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupoix <rdupoix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:29:32 by rdupoix           #+#    #+#             */
/*   Updated: 2026/06/26 17:01:22 by rdupoix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}

int	is_map(char c)
{
	if (c == '1' || c == '0' || c == ' '
		|| c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (is_map(line[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

int	which_id(char *line, char *id)
{
	int	len;

	len = ft_strlen(id);
	if (!ft_strncmp(line, id, len) && is_space(line[len]) == true)
		return (true);
	return (false);
}

int	is_space(char c)
{
	if ((c == '\t') || (c == 32))
		return (true);
	return (false);
}
