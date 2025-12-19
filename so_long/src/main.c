/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:22:32 by ehuet             #+#    #+#             */
/*   Updated: 2025/12/18 15:46:45 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_struct(t_ff *flood, t_game *game, char **av)
{
	game->map = NULL;
	game->map_height = 0;
	game->filename = av[1];
	game->fd = 0;
	game->collectibles = 0;
	game->exit = 0;
	game->players = 0;
	flood->grid = NULL;
	flood->player_x = 0;
	flood->player_y = 0;
}

int	main(int ac, char **av)
{
	t_game game;
	t_ff flood;
	
	if (ac != 2)
	{
		ft_printf("Error\nInvalid ARGS.\n");
		exit(1);
	}
	init_struct(&flood, &game, av);
	parsing(&game);
	copy_map(&flood, &game);
	player_pos(&flood);
	
	for (int i = 0; i < game.map_height; i++)
        printf("line %d: %s\n", i, game.map[i]);

    // Nettoyage
    for (int i = 0; i < game.map_height; i++)
        free(game.map[i]);
    free(game.map);

	ft_printf("%d\n", game.map_height);

	for (int i = 0; i < game.map_height; i++)
    	printf("line %d: %s\n", i, flood.grid[i]);

	printf("Player is in position : x : %d y : %d\n", flood.player_x, flood.player_y);
}