/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:22:32 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/08 18:57:15 by ehuet            ###   ########.fr       */
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
	game->player_x = 0;
	game->player_y = 0;
	flood->grid = NULL;
	flood->player_x = 0;
	flood->player_y = 0;
}
void   init_windows(t_mlx *mlx, t_game *game)
{
    mlx->mlx_connection = mlx_init();
    if (mlx->mlx_connection == NULL)
    {
        free(mlx->mlx_connection);
        return ;
    }
    mlx->mlx_window = mlx_new_window(mlx->mlx_connection, game->map_width * 84, game->map_height * 84, "so_long");
    if (mlx->mlx_window == NULL)
    {
        mlx_destroy_display(mlx->mlx_connection);
        free(mlx->mlx_connection);
        return ;
    }
}

int	main(int ac, char **av)
{
	t_game game;
	t_ff flood;
	t_mlx mlx;
	
	game.mlx = &mlx;
	
	if (ac != 2)
	{
		ft_printf("Error\nInvalid ARGS.\n");
		exit(1);
	}
	init_struct(&flood, &game, av);
	parsing(&game);
	copy_map(&flood, &game);
	player_pos(&flood, &game);
	valid_track(&flood);
	init_windows(&mlx, &game);
	load_img(&mlx);
	render_map(&game, &mlx);
	mlx_key_hook(mlx.mlx_window, key_hook, &game);
	mlx_loop(mlx.mlx_connection);


	// for (int i = 0; i < game.map_height; i++)
    //     printf("line %d: %s\n", i, game.map[i]);

    // // Nettoyage
    // for (int i = 0; i < game.map_height; i++)
    //     free(game.map[i]);
    // free(game.map);

	// ft_printf("%d\n", game.map_height);

	// for (int i = 0; i < game.map_height; i++)
    // 	printf("line %d: %s\n", i, flood.grid[i]);

	// printf("Player is in position : x : %d y : %d\n", flood.player_x, flood.player_y);
}
