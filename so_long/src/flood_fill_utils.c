/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:09:43 by ehuet             #+#    #+#             */
/*   Updated: 2025/12/18 16:06:53 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	copy_map(t_ff *ff, t_game *game)
{
	int i;
	
	ff->grid = malloc(sizeof(char *) * (game->map_height + 1));
	game->map_height = ff->grid_height;
	if (!ff->grid)
	{
		so_shlong_free_flood(ff);
		exit(ft_printf("Error\nMalloc mon gars.\n"));
	}
	i = 0;
	while (game->map[i])
	{
		ff->grid[i] = ft_strdup(game->map[i]);
		i++;
	}
	ff->grid[game->map_height] = NULL;
}

void	player_pos(t_ff *ff)
{
	int x;
	int y;

	x = 0;
	while (ff->grid[x])
	{
		y = 0;
		while (ff->grid[x][y])
		{
			if (ft_strchr("P", ff->grid[x][y]))
				ff->player_y = y;
			y++;
		}
		ff->player_x = x;
		x++;
	}
	ff->grid_width = y;
}


