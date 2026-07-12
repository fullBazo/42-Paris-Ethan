/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:22:40 by ehuet             #+#    #+#             */
/*   Updated: 2026/07/11 10:15:06 by ethan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	get_wall_height(t_game *game, float ray_angle)
{
	float	fisheye;

	fisheye = sqrt((game->ray_x - game->player.x)
			* (game->ray_x - game->player.x)
			+ (game->ray_y - game->player.y)
			* (game->ray_y - game->player.y));
	fisheye *= cos(ray_angle - game->player.pos_angle);
	if (fisheye < 1.0)
		fisheye = 1.0;
	return ((64 / fisheye) * 1108.5);
}

t_tex	*get_cur_tex(t_game *game, float ray_angle)
{
	if (game->hit_side == 0 && cos(ray_angle) > 0)
		return (&game->tex_we);
	else if (game->hit_side == 0)
		return (&game->tex_ea);
	else if (sin(ray_angle) > 0)
		return (&game->tex_no);
	return (&game->tex_so);
}

void	draw_column(t_game *game, t_col *coll, int col, float ray_angle)
{
	float	height;

	height = get_wall_height(game, ray_angle);
	coll->tex = get_cur_tex(game, ray_angle);
	if (game->hit_side == 0)
		coll->tex->tex_x = (int)((game->ray_y / 64.0 - (int)(game->ray_y / 64.0)) * coll->tex->width);
	else
    	coll->tex->tex_x = (int)((game->ray_x / 64.0 - (int)(game->ray_x / 64.0)) * coll->tex->width);
	coll->tex->tex_x = ft_clamp(coll->tex->tex_x, 0, coll->tex->width - 1);
	coll->start = ft_clamp(360 - height / 2, 0, 720);
	coll->end = ft_clamp(360 + height / 2, 0, 720);
	if (game->hit_side == 0 && cos(ray_angle) < 0)
		coll->tex->tex_x = coll->tex->width - 1 - coll->tex->tex_x;
	if (game->hit_side == 1 && sin(ray_angle) > 0)
		coll->tex->tex_x = coll->tex->width - 1 - coll->tex->tex_x;
	draw_ceiling_floor(game, col, coll->start, coll->end);
	draw_wall(game, col, coll, height);
}

void	cast_rays(t_game *game, float ray_angle)
{
	int		map_x;
	int		map_y;
	int		prev_x;

	game->ray_x = game->player.x;
	game->ray_y = game->player.y;
	map_x = (int)(game->ray_x / 64);
	prev_x = map_x;
	map_y = (int)(game->ray_y / 64);
	while (map_x >= 0 && map_x && map_y >= 0 && map_y
		&& game->cfg.map[map_y][map_x] != '1'
		&& game->cfg.map[map_y][map_x] != ' ')
	{
		prev_x = map_x;
		game->ray_x += cos(ray_angle);
		game->ray_y += sin(ray_angle);
		map_x = (int)(game->ray_x / 64);
		map_y = (int)(game->ray_y / 64);
		if (game->ray_x == 10e36 || game->ray_y == 10e36)
			return ;
	}
	if (prev_x != map_x)
		game->hit_side = 0;
	else
		game->hit_side = 1;
}

void	draw_rays(t_game *game, t_col *coll)
{
	float	ray_angle;
	float	fov;
	int		col;

	col = 0;
	fov = M_PI / 3;
	while (col < 1280)
	{
		ray_angle = game->player.pos_angle - (fov / 2) + (fov / 1280) * col;
		cast_rays(game, ray_angle);
		draw_column(game, coll, col, ray_angle);
		col++;
	}
}
