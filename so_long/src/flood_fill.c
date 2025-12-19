/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:54:25 by ehuet             #+#    #+#             */
/*   Updated: 2025/12/18 16:17:47 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(t_ff *ff, int x, int y)
{
	if (x < 0 || x >= ff->grid_height || y < 0 || y >= ff->grid_width)
		return ;
	if (ff->grid[x][y] == '1')
		return ;
	ff->grid[y][x] = 'X';
	flood_fill(ff->grid, x + 1, y, ff);
	flood_fill(ff->grid, x - 1, y, ff);
	flood_fill(ff->grid, x, y + 1, ff);
	flood_fill(ff->grid, x, y - 1, ff);
}

int	count_collectible(t_ff *ff, t_game *game)
{
    int x;
    int	y;
    int count;

    y = 0;
    while (ff->grid[y])
    {
	x = 0;
	while (ff->grid[y][x])
	{
	    if (game->map[y][x] == 'C' && ff->grid[y][x] == 'X')
		count++;
	    x++;
	}
	y++;
    }
    return (0);
}

int	access_exit(t_game *game, t_ff *ff)
{  
	int	x;
	int	y;
	int	count;

	y = 0;
	while (ff->grid[y])
	{
		x = 0;
		while (ff->grid[y][x])
		{
			if (game->map[y][x] == 'E' && ff->grid[y][x] == 'X')
			return (1);
			x++;
		}
	y++;
	}
	return (0);
}

int	flood_result(t_ff *ff, t_game *game)
{
	int access;

	access = count_collectible(ff, game);
	if (access != game->collectible)
    {
		ft_printf("Error\nNot all collectibles are accessibles.\n");
		return (0);
    }
    if (!access_exit(ff, game))
    {
		ft_printf("Error\nExit is not accessible.\n");
		return (0);
	}
	return (1);
}

int	valid track(t_ff *ff, t_game *game)
{
	flood_fill(ff->grid, ff->player_x, ff->player_y);
}
















