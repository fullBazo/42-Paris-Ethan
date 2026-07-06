/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupoix <rdupoix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 15:29:16 by rdupoix           #+#    #+#             */
/*   Updated: 2026/07/02 11:56:46 by rdupoix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* =============================== INCLUDES ================================ */

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <math.h>
# include <stdbool.h>
# include "struct.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "srcs/parsing/parsing.h"
# include "srcs/cleaning/cleaning.h"

/* ================================ MACROS ================================= */

# define TRUE 0
# define FALSE 1
# define SUCCESS 0
# define FAILURE 1
# define PI 3.1415926535

/* ================================= END ================================== */

void	init_all(t_game *game);
int		get_tex_pixel_from(t_tex *tex, int x, int y);
void	pixel_put(t_game *game, int x, int y, int color);
int		ft_clamp(int val, int min, int max);
void	draw_wall(t_game *game, int col, t_col *coll, float height);
void	draw_ceiling_floor(t_game *game, int x, int start, int end);
void	draw_rays(t_game *game, t_col *coll);
void	spawn_player(t_game *game);
int		key_press(int code, t_game *game);
int		key_release(int code, t_game *game);
int		game_loop(t_game *game);
int		collision(t_game *game, float x, float y);

#endif
