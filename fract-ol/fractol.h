/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:11:23 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/11 15:14:40 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*address;
	int		bpp;
	int		line_l;
	int		endian;
	int		width;
	int		height;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	julia_cr;
	double	julia_ci;
	int		mandel;
	int		julia;
	double	decal_x;
	double	decal_y;
}	t_data;

int		parse_arg(char **av);
void	render_julia(t_data *data);
double	ft_atob(const char *str);
void	put_color(t_data *data, int x, int y, int color);
int		create_color(int iter);
int		close_free(t_data *data);
int		mouse_hook(int keycode, int x, int y, t_data *data);
void	render_mandel(t_data *data, int x, int y);
double	complex_y(int y, int height, t_data *data);
double	complex_x(int x, int width, t_data *data);
void	zoom_in(t_data *data, int mouse_x, int mouse_y);
int		key_hook(int keycode, t_data *data);
void	mlx_event_hook(t_data *data);
void	move(t_data *data, int key);
void	zoom_out(t_data *data, int mouse_x, int mouse_y);

#endif
