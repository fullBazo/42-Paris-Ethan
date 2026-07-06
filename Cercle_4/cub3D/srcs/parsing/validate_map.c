/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupoix <rdupoix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 18:58:55 by rdupoix           #+#    #+#             */
/*   Updated: 2026/07/02 11:48:25 by rdupoix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	store_player(t_config *cfg, char c, int x, int y)
{
	cfg->player.x = x;
	cfg->player.y = y;
	if (c == 'N')
		cfg->player.dir = NORTH;
	if (c == 'S')
		cfg->player.dir = SOUTH;
	if (c == 'W')
		cfg->player.dir = WEST;
	if (c == 'E')
		cfg->player.dir = EAST;
	return ;
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W'
		|| c == 'E')
		return (true);
	return (false);
}

static t_err	find_player(t_config *cfg)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (cfg->map[y])
	{
		x = 0;
		while (cfg->map[y][x])
		{
			if (is_player(cfg->map[y][x]) == true)
			{
				count++;
				store_player(cfg, cfg->map[y][x], x, y);
			}
			x++;
		}
		y++;
	}
	if (count != 1)
		return (ERR_PLAYER);
	return (OK);
}

static t_err	check_charset(t_config *cfg)
{
	int	y;
	int	x;

	y = 0;
	if (!cfg->map)
		return (ERR_MISSING);
	while (cfg->map[y])
	{
		x = 0;
		while (cfg->map[y][x])
		{
			if (is_map(cfg->map[y][x]) == false)
				return (ERR_MAP_CHAR);
			x++;
		}
		y++;
	}
	return (OK);
}

t_err	validate_map(t_config *cfg)
{
	t_err	err;

	err = check_charset(cfg);
	if (err != OK)
		return (err);
	err = find_player(cfg);
	if (err != OK)
		return (err);
	err = check_closed(cfg);
	if (err != OK)
		return (err);
	err = check_corners(cfg);
	if (err != OK)
		return (err);
	return (OK);
}
