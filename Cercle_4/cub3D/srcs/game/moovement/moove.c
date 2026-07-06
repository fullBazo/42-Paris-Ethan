/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:51:13 by ehuet             #+#    #+#             */
/*   Updated: 2026/07/01 11:22:34 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	normalize_angle(t_game *game)
{
	if (game->player.pos_angle > 2 * M_PI)
		game->player.pos_angle -= 2 * M_PI;
	else if (game->player.pos_angle < -2 * M_PI)
		game->player.pos_angle += 2 * M_PI;
}

void	player_moove(int code, t_game *game, float *map_x, float *map_y)
{
	if (code == KEY_W)
	{
		*map_x += cos(game->player.pos_angle) * 3;
		*map_y += sin(game->player.pos_angle) * 3;
	}
	else if (code == KEY_S)
	{
		*map_x -= cos(game->player.pos_angle) * 3;
		*map_y -= sin(game->player.pos_angle) * 3;
	}
	else if (code == KEY_D)
	{
		*map_x -= cos(game->player.pos_angle - (M_PI / 2)) * 3;
		*map_y -= sin(game->player.pos_angle - (M_PI / 2)) * 3;
	}
	else if (code == KEY_A)
	{
		*map_x += cos(game->player.pos_angle - (M_PI / 2)) * 3;
		*map_y += sin(game->player.pos_angle - (M_PI / 2)) * 3;
	}
}

void	player_strafe(int code, t_game *game)
{
	float	map_x;
	float	map_y;

	map_x = game->player.x;
	map_y = game->player.y;
	player_moove(code, game, &map_x, &map_y);
	if (!collision(game, map_x, game->player.y))
		game->player.x = map_x;
	if (!collision(game, game->player.x, map_y))
		game->player.y = map_y;
}

int	game_loop(t_game *game)
{
	if (game->move.w)
		player_strafe(KEY_W, game);
	if (game->move.s)
		player_strafe(KEY_S, game);
	if (game->move.a)
		player_strafe(KEY_A, game);
	if (game->move.d)
		player_strafe(KEY_D, game);
	if (game->move.right)
	{
		game->player.pos_angle += 0.05;
		normalize_angle(game);
	}
	if (game->move.left)
	{
		game->player.pos_angle -= 0.05;
		normalize_angle(game);
	}
	draw_rays(game, &game->coll);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, 0, 0);
	return (0);
}
