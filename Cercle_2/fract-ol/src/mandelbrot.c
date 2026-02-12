/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:55:38 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/11 15:00:39 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(double cr, double ci, int max_iterations)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = 0;
	zi = 0;
	i = 0;
	while (zr * zr + zi * zi <= 4 && i < max_iterations)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		i++;
	}
	return (i);
}

void	render_mandel(t_data *data, int x, int y)
{
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
			cr = complex_x(x, data->width, data);
			ci = complex_y(y, data->height, data);
			iter = mandelbrot(cr, ci, 100);
			if (iter == 100)
				color = 0x00000000;
			else
				color = create_color(iter);
			put_color(data, x, y, color);
			x++;
		}
		y++;
	}
}
