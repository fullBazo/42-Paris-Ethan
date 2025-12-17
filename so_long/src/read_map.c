/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:06:22 by ehuet             #+#    #+#             */
/*   Updated: 2025/12/17 16:55:46 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_rectangle(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(game->map[i++]);
	while (game->map[i])
	{
		if (len != ft_strlen(game->map[i]))
			exit(ft_printf("Error\nNot a rectangle\n"));
		i++;
	}
}

void	check_u_d_wall(t_game *game)
{
	int	i;
	int	y;
	int	len;

	i = 0;
	y = 0;
	while (game->map[0][y])
	{
		if (game->map[0][y] != '1')
			exit(ft_printf("Error\nInvalid Walls.\n"));
		y++;
	}
	i = 0;
	y = 0;
	while (game->map[i - 1][y])
	{
		if (game->map[i - 1][y] != '1')
			exit(ft_printf("Error\nInvalid Walls.\n"));
		y++;
	}
}

void	check_border(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	while (game->map[i])
	{
		len = ft_strlen(game->map[i]);
		if (game->map[i][0] != '1' || game->map[i][len - 1] != '1')
			exit(ft_printf("Error\nInvalid Walls.\n"));
		i++;
	}
}

void	check_valid_element(t_game *game)
{
	int		x;
	int		y;
	char	c;
	
	x = 0;
	y = 0;
	while (game->map[x])
	{
		
	}
}