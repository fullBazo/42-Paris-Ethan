/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupoix <rdupoix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:13:53 by rdupoix           #+#    #+#             */
/*   Updated: 2026/07/02 12:04:59 by rdupoix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_err	check_corners(t_config *cfg)
{
	int	x1;
	int	x2;
	int	last;

	x1 = 0;
	x2 = 0;
	last = cfg->map_h - 1;
	while (is_space(cfg->map[0][x1]) == true || cfg->map[0][x1] == '0')
		x1++;
	while (is_space(cfg->map[last][x2]) == true || cfg->map[0][x2] == '0')
		x2++;
	if (x1 && x2 && cfg->map[0][x1 - 1] == '0'
		&& cfg->map[last] && cfg->map[last][x2 - 1] == '0')
		return (ERR_MAP_OPEN);
	while (cfg->map[0][x1] == '1')
		x1++;
	while (cfg->map[last][x2] == '1')
		x2++;
	if (cfg->map[0][x1] == '0' && cfg->map[last][x2] == '0')
		return (ERR_MAP_OPEN);
	return (OK);
}

static void	flood_fill(char **grid, int x, int y, int *flag)
{
	if (y < 0 || grid[y] == NULL || x < 0
		|| x >= (int)ft_strlen(grid[y]) || grid[y][x] == ' ')
	{
		*flag = 1;
		return ;
	}
	if (is_player(grid[y][x]))
		grid[y][x] = '0';
	if (grid[y][x] == '1' || grid[y][x] == 'F')
		return ;
	if (grid[y][x] == '0')
	{
		grid[y][x] = 'F';
		flood_fill(grid, x + 1, y, flag);
		flood_fill(grid, x - 1, y, flag);
		flood_fill(grid, x, y + 1, flag);
		flood_fill(grid, x, y - 1, flag);
	}
	return ;
}

static char	**copy_grid(t_config *cfg)
{
	char	**grid;
	int		i;

	i = 0;
	grid = ft_calloc((cfg->map_h + 1), sizeof(char *));
	if (!grid)
		return (NULL);
	while (i < cfg->map_h)
	{
		grid[i] = ft_strdup(cfg->map[i]);
		if (!grid[i])
			return (free_tab(grid), NULL);
		i++;
	}
	grid[cfg->map_h] = NULL;
	return (grid);
}

t_err	check_closed(t_config *cfg)
{
	char	**grid;
	int		flag;

	flag = 0;
	grid = copy_grid(cfg);
	if (!grid)
		return (ERR_MALLOC);
	flood_fill(grid, (int)cfg->player.x, (int)cfg->player.y, &flag);
	free_tab(grid);
	if (flag == 1)
		return (ERR_MAP_OPEN);
	return (OK);
}
