/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupoix <rdupoix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:30:07 by rdupoix           #+#    #+#             */
/*   Updated: 2026/06/26 17:49:24 by rdupoix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*err_str(t_err err)
{
	if (err == ERR_ARGS)
		return ("Wrong number of arguments\n");
	if (err == ERR_COLOR)
		return ("Wrong color code\n");
	if (err == ERR_DUP)
		return ("An element is duplicated\n");
	if (err == ERR_EXT)
		return ("Wrong file extension\n");
	if (err == ERR_MALLOC)
		return ("The allocation failed\n");
	if (err == ERR_MAP_CHAR)
		return ("Wrong character in the map\n");
	if (err == ERR_MAP_OPEN)
		return ("Map not surrounded\n");
	if (err == ERR_MISSING)
		return ("An element is missing in the file\n");
	if (err == ERR_OPEN)
		return ("Cannot open file\n");
	if (err == ERR_PLAYER)
		return ("The number of player is not equal to 1\n");
	if (err == ERR_TEXTURE)
		return ("Wrong texture path\n");
	if (err == ERR_INVALID_LINE)
		return ("Invalid line in the .cub file\n");
	return ("Unknown error\n");
}

static void	free_tex(t_game *game)
{
	int	i;

	i = 0;
	if (game->cfg.tex[i])
	{
		while (i < 4)
		{
			if (game->cfg.tex[i])
			{
				free(game->cfg.tex[i]);
				game->cfg.tex[i] = NULL;
			}
			i++;
		}
	}
}

void	free_config(t_game *game)
{
	int	i;

	i = 0;
	free_tex(game);
	if (game->cfg.map)
	{
		while (game->cfg.map[i])
		{
			free(game->cfg.map[i]);
			game->cfg.map[i] = NULL;
			i++;
		}
		free(game->cfg.map);
		game->cfg.map = NULL;
	}
	return ;
}

int	fail(t_game *game, t_err err)
{
	free_config(game);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err_str(err), 2);
	return (EXIT_FAILURE);
}
