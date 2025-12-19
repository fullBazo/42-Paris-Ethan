/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:47:09 by ehuet             #+#    #+#             */
/*   Updated: 2025/12/18 16:03:50 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
//# include "mlx.h"
# include "./libft/libft.h"

typedef struct s_game
{
	char	**map;
	int		map_height;
	char	*filename;
	int		fd;
	int		exit;
	int		players;
	int		collectibles;
}				t_game;

typedef struct s_ff
{
	char	**grid;
	int		grid_width;
	int		grid_height;
	char	*line;
	int		player_x;
	int		player_y;
	char	valid;
	
}				t_ff;

void	check_extension(t_game *game);
void	openfile(t_game *game);
void	count_height(t_game *game);
void	read_map(t_game *game);
void	parsing(t_game *game);
void	init_struct(t_ff *flood, t_game *game, char **av);
void	check_elements(t_game *game);
void	check_valid_element(t_game *game);
void	check_border(t_game *game);
void	check_u_d_wall(t_game *game);
void	check_rectangle(t_game *game);
void	so_shlong_free_map(t_game *game);
void	copy_map(t_ff *ff, t_game *game);
void	so_shlong_free_flood(t_ff *flood);
void	player_pos(t_ff *ff);



#endif
