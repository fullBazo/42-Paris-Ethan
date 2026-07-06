/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupoix <rdupoix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:45:45 by ehuet             #+#    #+#             */
/*   Updated: 2026/06/26 17:11:55 by rdupoix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_direction(t_game *game, char map)
{
	if (map == 'N')
		game->player.pos_angle = M_PI / 2;
	if (map == 'E')
		game->player.pos_angle = M_PI;
	if (map == 'S')
		game->player.pos_angle = -M_PI / 2;
	if (map == 'W')
		game->player.pos_angle = 0;
}

void	spawn_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->cfg.map[y])
	{
		x = 0;
		while (game->cfg.map[y][x])
		{
			if (is_player(game->cfg.map[y][x]))
			{
				game->player.x = (float)(x * 64) + 32;
				game->player.y = (float)(y * 64) + 32;
				player_direction(game, game->cfg.map[y][x]);
				return ;
			}
			x++;
		}
		y++;
	}
}
