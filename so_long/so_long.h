/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:47:09 by ehuet             #+#    #+#             */
/*   Updated: 2025/12/12 12:57:24 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
	// void	*img_wall;
	// void	*img_floor;
	// void	*img_player;
	// void	*img_exit;
	// void	*img_collectible;
}				t_game;

void	error_and_exit(const char *message);
char	**read_map(const char *filename, t_game *game);
void	validate_map(t_game *game);
void	init_game(t_game *game);
int		handle_keypress(int keycode, t_game *game);
void	render_game(t_game *game);
void	free_map(char **map);
#endif
