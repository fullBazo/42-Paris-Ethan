/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 15:26:19 by username          #+#    #+#             */
/*   Updated: 2026/06/29 15:51:53 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

void	init_config(t_config *cfg)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		cfg->tex[i] = NULL;
		i++;
	}
	cfg->floor.set = false;
	cfg->ceiling.set = false;
	cfg->map = NULL;
	cfg->grid = NULL;
	cfg->map_h = 0;
	cfg->map_w = 0;
	cfg->player.x = 0;
	cfg->player.y = 0;
	cfg->has_player = false;
	return ;
}

int	main(int ac, char **av)
{
	t_game		game;

	ft_memset(&game, 0, sizeof(game));
	init_config(&game.cfg);
	if (parse_scene(ac, av[1], &game) == EXIT_FAILURE)
		return (free_config(&game), EXIT_FAILURE);
	init_all(&game);
	mlx_hook(game.mlx_win, 2, 1L << 0, (void *)key_press, &game);
	mlx_hook(game.mlx_win, 3, 1L << 1, (void *)key_release, &game);
	mlx_hook(game.mlx_win, 17, 0, (void *)cleanup_and_exit, &game);
	mlx_loop_hook(game.mlx, (void *)game_loop, &game);
	mlx_loop(game.mlx);
	free_config(&game);
	return (EXIT_SUCCESS);
}
