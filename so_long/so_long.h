/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:47:09 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/08 18:57:14 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <fcntl.h>
# include "minilibx-linux/mlx.h"


typedef struct s_mlx
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collect;
	void	*mlx_connection;
	void	*mlx_window;
}				t_mlx;

typedef struct s_game
{
	char	**map;
	int		map_height;
	int		map_width;
	char	*filename;
	int		fd;
	int		exit;
	int		players;
	int		collectibles;
	int		player_x;
	int		player_y;
	int		moves;
	void	*win;
	t_mlx	*mlx;
}				t_game;

typedef struct s_ff
{
	char	**grid;
	char	*line;
	int		player_x;
	int		player_y;
	char	valid;
	int		collectibles;
	int		exit;
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
void	free_game(t_game *game);
void	copy_map(t_ff *ff, t_game *game);
void	free_flood(t_ff *flood);
void	player_pos(t_ff *ff, t_game *game);
int 	count_line(t_ff *flood);
int		count_length(t_ff *flood);
int 	check_limits(t_ff *flood, int x, int y);
void	valid_track(t_ff *flood);
int		flood_fill(t_ff *flood, int x, int y);
void  	init_windows(t_mlx *mlx, t_game *game);
void    load_img(t_mlx *mlx);
void	put_tile(t_mlx *mlx, void *img, int x, int y);
void	render_map(t_game *game, t_mlx *mlx);
void	move_player(t_game *game, int px, int py);
int		key_hook(int keycode, t_game *game);


#endif
