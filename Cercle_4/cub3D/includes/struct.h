/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupoix <rdupoix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:06:16 by ehuet             #+#    #+#             */
/*   Updated: 2026/06/29 16:16:21 by rdupoix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/* ================================ enum ================================ */

typedef enum e_orient
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}			t_orient;

typedef enum e_kind
{
	KIND_NO,
	KIND_SO,
	KIND_EA,
	KIND_WE,
	KIND_C,
	KIND_F,
	KIND_MAP,
	KIND_EMPTY,
	KIND_UNKNOWN
}			t_kind;

typedef enum e_elem
{
	EL_NO,
	EL_SO,
	EL_EA,
	EL_WE
}			t_elem;

typedef enum e_err
{
	OK = 0,
	ERR_ARGS,
	ERR_EXT,
	ERR_OPEN,
	ERR_DUP,
	ERR_MISSING,
	ERR_TEXTURE,
	ERR_COLOR,
	ERR_MAP_CHAR,
	ERR_MAP_OPEN,
	ERR_PLAYER,
	ERR_MALLOC,
	ERR_INVALID_LINE
}			t_err;

/* =============================== struct ================================ */

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
	bool		set;
}					t_color;

typedef struct s_player
{
	double		x;
	double		y;
	double		pos_angle;
	t_orient	dir;
}					t_player;

typedef struct s_config
{
	char		*tex[4];
	t_color		floor;
	t_color		ceiling;
	char		**map;
	int			**grid;
	int			map_h;
	int			map_w;
	t_player	player;
	bool		has_player;
}							t_config;

typedef enum e_keys
{
	KEY_ESC = 65307,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_W = 119,
	KEY_S = 115,
	KEY_A = 97,
	KEY_D = 100,
}	t_keys;

typedef struct s_tex
{
	void	*img;
	char	*addr;
	float	tex_x;
	float	tex_y;
	int		bpp;
	int		line_l;
	int		endian;
	int		width;
	int		height;
}	t_tex;

typedef struct s_data
{
	int	line_l;
	int	endian;
	int	bpp;
}	t_data;

typedef struct s_move
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
}				t_move;

typedef struct s_col
{
	int		x;
	int		start;
	int		end;
	float	height;
	t_tex	*tex;
}				t_col;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			hit_side;
	float		ray_x;
	float		ray_y;
	t_col		coll;
	t_tex		tex_no;
	t_tex		tex_so;
	t_tex		tex_ea;
	t_tex		tex_we;
	t_player	player;
	t_data		data;
	t_config	cfg;
	t_move		move;
}	t_game;
/* ================================= END ================================== */

#endif
