/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 mandatory.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ehuet <ehuet@student.42.fr>				+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/01/30 16:09:39 by ehuet			   #+#	  #+#			  */
/*	 Updated: 2026/02/06 12:02:59 by ehuet			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../fractol.h"

double complex_x(int x, int width)
{
	return ((double)x / width) * 3.5 - 2.5 ;
}

double complex_y(int y, int height)
{
	return ((double)y / height) * 2.0 - 1.0 ;
}

int	mandelbrot(t_fractol *f, double cr, double ci)
{
	double	zr;
	double	 zi;
	double	tmp;
	int		i;

	zr = 0;
	zi = 0;
	i = 0;
	while (zr * zr + zi * zi <= 4 && i < f->max_iterations)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		i++;
	}
	return (i);
}

void	put_color(t_data *data, int x, int y, int color)
{
	char    *dst;

    dst = data->address + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	render_mandel(t_data *data, t_fractol *f)
{
	int		x;
	int		y;
	double	cr;
	double	ci;
	int		iter;
	int		color;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			cr = complex_x(x, data->width);
			ci = complex_y(y, data->height);
			iter = mandelbrot(f, cr, ci);
			if (iter == 100)
				color = 0x00000000;				
			else
				color = 0x00FFFFFF;
			put_color(data, x, y, color);
			x++;
		}
		y++;
	}
}
