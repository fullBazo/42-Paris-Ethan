/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 fractol.h											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ehuet <ehuet@student.42.fr>				+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/01/30 13:24:07 by ehuet			   #+#	  #+#			  */
/*	 Updated: 2026/01/30 13:28:00 by ehuet			  ###	########.fr		  */
/*																			  */
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

typedef struct s_fractol
{
	int		x;
	int		y;
	int		max_iterations;
	char	*name;
	double	zoom;
}	t_fractol;

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *address;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     width;
    int     height;
}   t_data;


void	render_mandel(t_data *data, t_fractol *f);
double complex_y(int y, int height);
double complex_x(int x, int width);

#endif
