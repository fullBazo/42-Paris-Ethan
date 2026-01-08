/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:21:24 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/05 14:26:40 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_game(t_game *game)
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

void	free_flood(t_ff *flood)
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

