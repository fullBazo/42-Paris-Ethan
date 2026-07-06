/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupoix <rdupoix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:01:23 by rdupoix           #+#    #+#             */
/*   Updated: 2026/06/26 17:52:28 by rdupoix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static t_err	dispatch_line(char *line, t_kind kind, t_config *cfg, int fd)
{
	if (kind == KIND_NO || kind == KIND_SO
		|| kind == KIND_WE || kind == KIND_EA)
		return (parse_texture(cfg, line, (t_elem)kind));
	else if (kind == KIND_F)
		return (parse_color(line, &cfg->floor));
	else if (kind == KIND_C)
		return (parse_color(line, &cfg->ceiling));
	else if (kind == KIND_UNKNOWN)
		return (ERR_INVALID_LINE);
	else if (kind == KIND_MAP)
		return (collect_map(line, fd, cfg));
	return (OK);
}

static t_kind	identify_line(char *line)
{
	int		i;

	i = 0;
	while (is_space(line[i]) == true)
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (KIND_EMPTY);
	if (which_id(line + i, "NO") == true)
		return (KIND_NO);
	if (which_id(line + i, "SO") == true)
		return (KIND_SO);
	if (which_id(line + i, "WE") == true)
		return (KIND_WE);
	if (which_id(line + i, "EA") == true)
		return (KIND_EA);
	if (which_id(line + i, "F") == true)
		return (KIND_F);
	if (which_id(line + i, "C") == true)
		return (KIND_C);
	if (is_map_line(line) == true)
		return (KIND_MAP);
	return (KIND_UNKNOWN);
}

t_err	read_scene(int fd, t_config *cfg)
{
	char	*line;
	t_kind	kind;
	t_err	err;

	line = get_next_line(fd);
	while (line)
	{
		kind = identify_line(line);
		err = dispatch_line(line, kind, cfg, fd);
		if (err != OK)
			return (free(line), err);
		if (kind == KIND_MAP)
			return (free(line), OK);
		free(line);
		line = get_next_line(fd);
	}
	return (OK);
}
