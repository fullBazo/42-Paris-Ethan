/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:09:43 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/06 17:38:32 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	copy_map(t_ff *flood, t_game *game)
{
	int	i;

	i = 0;
	flood->grid = malloc(sizeof (char *) * (game->map_height + 1));
	if (!flood->grid)
	{
		free_flood(flood);
		exit(ft_printf("Error\nMalloc failed.\n"));
	}
	while (game->map[i])
	{
		flood->grid[i] = ft_strdup(game->map[i]);
		i++;
	}
	flood->grid[i] = NULL;
}

void	player_pos(t_ff *flood, t_game *game)
{
	int i;
	int	y;

	i = 0;
	while (flood->grid[i])
	{
		y = 0;
		while (flood->grid[i][y])
		{
			if (flood->grid[i][y] == 'P')
			{
				flood->player_x = y;
				flood->player_y = i;
				game->player_x = y;
				game->player_y = i;
			}
			y++;
		}
		i++;
	}
}

int	count_line(t_ff *flood)
{
	int len;

	len = 0;
	while (flood->grid[len])
		len++;
	return (len);
}
int	count_length(t_ff *flood)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (flood->grid[i][y])
		y++;
	return (y);
}