/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:21:24 by ehuet             #+#    #+#             */
/*   Updated: 2025/12/18 14:39:36 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	so_shlong_free_map(t_game *game)
{
	int i;
	
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	so_shlong_free_flood(t_ff *flood)
{
	int i;
	
	i = 0;
	while (flood->grid[i])
	{
		free(flood->grid[i]);
		i++;
	}
	free(flood->grid);
}

