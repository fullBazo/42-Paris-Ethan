/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:15:25 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/06 18:01:25 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    load_img(t_mlx *mlx)
{
    int width;
    int height;

    mlx->wall = mlx_xpm_file_to_image(mlx->mlx_connection, "textures/walls.xpm", &width , &height);
    mlx->floor = mlx_xpm_file_to_image(mlx->mlx_connection, "textures/floor.xpm", &width , &height);
    mlx->player = mlx_xpm_file_to_image(mlx->mlx_connection, "textures/player.xpm",&width , &height);
    mlx->exit = mlx_xpm_file_to_image(mlx->mlx_connection, "textures/exit.xpm",&width , &height);
    mlx->collect = mlx_xpm_file_to_image(mlx->mlx_connection, "textures/collectible.xpm",&width , &height);
    if (!mlx->wall || !mlx->floor || !mlx->collect || !mlx->exit || !mlx->player)
    {
        free(mlx->mlx_connection);
        exit(ft_printf("Error\nXPM load failed\n"));
    }
}
void	put_tile(t_mlx *mlx, void *img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_connection, mlx->mlx_window, img,
		x * 84, y * 84);
}

void	render_map(t_game *game, t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			put_tile(mlx, mlx->floor, x, y);
			if (game->map[y][x] == '1')
				put_tile(mlx, mlx->wall, x, y);
			else if (game->map[y][x] == 'P')
				put_tile(mlx, mlx->player, x, y);
			else if (game->map[y][x] == 'C')
				put_tile(mlx, mlx->collect, x, y);
			else if (game->map[y][x] == 'E')
				put_tile(mlx, mlx->exit, x, y);
			x++;
		}
		y++;
	}
}
void    player_move(t_mlx *mlx, t_game *game, int x, int y)
{
    if ()
}