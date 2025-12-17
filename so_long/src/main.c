/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:22:32 by ehuet             #+#    #+#             */
/*   Updated: 2025/12/17 14:45:38 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_struct(t_game *game, char **av)
{
	game->map = NULL;
	game->map_height = 0;
	game->filename = av[1];
	game->fd = 0;
}

int	main(int ac, char **av)
{
	t_game game;
	
	if (ac != 2)
	{
		ft_printf("Error\nInvalid ARGS.\n");
		exit(1);
	}
	init_struct(&game, av);
	parsing(&game);
	
	for (int i = 0; i < game.map_height; i++)
        printf("line %d: %s\n", i, game.map[i]);

    // Nettoyage
    for (int i = 0; i < game.map_height; i++)
        free(game.map[i]);
    free(game.map);

	ft_printf("%d\n", game.map_height);
    return 0;

}