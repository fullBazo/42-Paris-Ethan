/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:06:22 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/08 18:33:41 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_rectangle(t_game *game)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(game->map[i++]);
	while (game->map[i])
	{
		if (len != ft_strlen(game->map[i]))
		{
			free_game(game);
			exit(ft_printf("Error\nNot a rectangle\n"));
		}
		i++;
	}
}

void	check_u_d_wall(t_game *game)
{
	int	i;
	int	y;

	y = 0;
	while (game->map[0][y])
	{
		if (game->map[0][y] != '1')
		{
			free_game(game);
			exit(ft_printf("Error\nInvalid Walls.\n"));
		}
		y++;
	}
	i = 0;
	y = 0;
	while (game->map[i])
		i++;
	while (game->map[i - 1][y])
	{
		if (game->map[i - 1][y] != '1')
		{
			free_game(game);
			exit(ft_printf("Error\nInvalid Walls.\n"));
		}
		y++;
	}
}

void	check_border(t_game *game)
{
	int		i;
	size_t	len;

	i = 0;
	while (game->map[i])
	{
		len = ft_strlen(game->map[i]);
		if (game->map[i][0] != '1' || game->map[i][len - 1] != '1')
		{
			free_game(game);
			exit(ft_printf("Error\nInvalid Walls.\n"));
		}
		i++;
	}
}

void	check_valid_element(t_game *game)
{
	int		i;
	int		y;
	
	i = 0;
	while (game->map[i])
	{
		game->map_width = 0;
		y = 0;
		while (game->map[i][y])
		{
			if (!(ft_strchr("01PEC", game->map[i][y])))
			{
				free_game(game);
				exit(ft_printf("Error\nInvalid characters.\n"));
			}
			y++;
			game->map_width++;
		}
		i++;
	}
}

void	check_elements(t_game *game)
{
	int	i;
	int	y;

	i = 0;
	while (game->map[i])
	{
		y = 0;
		while (game->map[i][y])
		{
			if (game->map[i][y] == 'P')
				game->players++;
			else if (game->map[i][y] == 'C')
				game->collectibles++;
			else if (game->map[i][y] == 'E')
				game->exit++;
			y++;
		}
		i++;
	}
	if (game->players != 1 || game->collectibles < 1 || game->exit != 1)
	{
		free_game(game);
		exit(ft_printf("Error\nTo much elements or some missing.\n"));
	}
}

