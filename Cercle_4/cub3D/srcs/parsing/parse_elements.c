/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupoix <rdupoix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:38:57 by rdupoix           #+#    #+#             */
/*   Updated: 2026/06/26 18:12:40 by rdupoix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_err	store_rgb(char **tab, t_color *col)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (tab[i])
	{
		value = ft_atoi(tab[i]);
		if (value < 0 || value > 255)
			return (ERR_COLOR);
		if (i == 0)
			col->r = value;
		if (i == 1)
			col->g = value;
		if (i == 2)
			col->b = value;
		i++;
	}
	return (OK);
}

static t_err	is_numeric(char	**tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		if (ft_strlen(tab[i]) > 3 || ft_strlen(tab[i]) == 0)
			return (ERR_COLOR);
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]))
				return (ERR_COLOR);
			j++;
		}
		i++;
	}
	return (OK);
}

static t_err	begin_start_color(int *i, t_color *col, char *line)
{
	if (col->set == true)
		return (ERR_DUP);
	while (is_space(line[*i]) == true)
		(*i)++;
	(*i) += 1;
	while (is_space(line[*i]) == true)
		(*i)++;
	return (OK);
}

t_err	parse_color(char *line, t_color *col)
{
	int		i;
	char	*trim;
	char	**tab;

	i = 0;
	if (begin_start_color(&i, col, line) != OK)
		return (begin_start_color(&i, col, line));
	if (!ft_isdigit(line[i]))
		return (ERR_COLOR);
	trim = ft_strtrim(line + i, " \t\n");
	if (!trim)
		return (ERR_MALLOC);
	tab = ft_split(trim, ',');
	free(trim);
	if (!tab)
		return (ERR_MALLOC);
	if (count(tab) != 3)
		return (free_tab(tab), ERR_COLOR);
	if (is_numeric(tab) != OK)
		return (free_tab(tab), ERR_COLOR);
	if (store_rgb(tab, col) != OK)
		return (free_tab(tab), ERR_COLOR);
	col->set = true;
	free_tab(tab);
	return (OK);
}

t_err	parse_texture(t_config *cfg, char *line, t_elem elem)
{
	int		i;
	int		fd;
	char	*path;

	i = 0;
	fd = -1;
	if (cfg->tex[elem])
		return (ERR_DUP);
	while (is_space(line[i]) == true)
		i++;
	i += 2;
	while (is_space(line[i]) == true)
		i++;
	path = ft_strtrim(line + i, " \t\n");
	if (!path)
		return (ERR_MALLOC);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (free(path), ERR_TEXTURE);
	close(fd);
	cfg->tex[elem] = ft_strdup(path);
	free(path);
	if (!cfg->tex[elem])
		return (ERR_MALLOC);
	return (OK);
}
