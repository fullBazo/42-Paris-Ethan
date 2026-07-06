/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupoix <rdupoix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:52:31 by ehuet             #+#    #+#             */
/*   Updated: 2026/06/26 17:15:57 by rdupoix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	draw_ceiling_floor(t_game *game, int x, int start, int end)
{
	int	y;

	y = 0;
	while (y < start)
		pixel_put(game, x, y++, create_color(game->cfg.ceiling.r,
				game->cfg.ceiling.g, game->cfg.ceiling.b));
	while (end < 720)
		pixel_put(game, x, end++,
			create_color(game->cfg.floor.r,
				game->cfg.floor.g, game->cfg.floor.b));
}

void	draw_wall(t_game *game, int col, t_col *coll, float height)
{
	int	tex_y;

	while (coll->start < coll->end)
	{
		tex_y = (coll->start - (360 - height / 2))
			* coll->tex->height / height;
		tex_y = ft_clamp(tex_y, 0, coll->tex->height - 1);
		pixel_put(game, col, coll->start++,
			get_tex_pixel_from(coll->tex, coll->tex->tex_x, tex_y));
	}
}
