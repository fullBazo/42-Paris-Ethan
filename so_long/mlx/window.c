/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:15:25 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/08 18:57:22 by ehuet            ###   ########.fr       */
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
			if (game->map[y][x] == '0')
				put_tile(mlx, mlx->floor, x, y);
			else if (game->map[y][x] == '1')
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
int key_hook(int keycode, t_game *game)
{
	// if (keycode == 65307)
	// 	exit(mlx_destroy_window(mlx->mlx_connection, mlx->mlx_window));
	if (keycode == 'w' || keycode == 65362)
		move_player(game , 0, -1);
	if (keycode == 's' || keycode == 65364)
		move_player(game, 0, 1);
	if (keycode == 'a' || keycode == 65361)
		move_player(game, -1, 0);
	if (keycode == 'd' || keycode == 65363)
		move_player(game, 1, 0);
	return (0);
} 
void	move_player(t_game *game, int px, int py)
{
	int new_x;
	int new_y;

	new_x = game->player_x + px;
	new_y = game->player_y + py;
	// if (new_x >= 0 || new_y >= 0 || new_x < )
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'E')
		return ;
	if (game->map[new_y][new_x] == 'C')
		game->map[new_y][new_x] = '0';
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	
	game->player_x = new_x;
	game->player_y = new_y;

	render_map(game, game->mlx);
}