/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:54:25 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/05 17:39:35 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_limits(t_ff *flood, int x, int y)
{
    if (y < 0 || y >= count_line(flood))
        return (0);
    if (x < 0 || x >= count_length(flood))
        return (0);
    return (1);
}
int flood_fill(t_ff *flood, int x, int y)
{
    if (!check_limits(flood, x, y))
        return (0);

    if (flood->grid[y][x] == '1' || flood->grid[y][x] == 'X')
        return (1);

    flood->grid[y][x] = 'X';

    flood_fill(flood, x + 1, y);
    flood_fill(flood, x - 1, y);
    flood_fill(flood, x, y + 1);
    flood_fill(flood, x, y - 1);

    return (1);
}

void	valid_track(t_ff *flood)
{
	int	y;
	int	x;

	flood_fill(flood, flood->player_x, flood->player_y);
	y = 0;
	while (y < count_line(flood))
	{
		x = 0;
		while (x < count_length(flood))
		{
			if (flood->grid[y][x] == 'C'
				|| flood->grid[y][x] == 'E')
			{
				free_flood(flood);
				exit(ft_printf("Error\nMap is not solvable"));
			}
			x++;
		}
		y++;
	}
}
