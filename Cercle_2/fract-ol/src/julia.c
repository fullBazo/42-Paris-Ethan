/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:45:12 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/11 14:43:16 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	julia(t_data *data, int x, int y, int max_iterations)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = complex_x(x, data->width, data);
	zi = complex_y(y, data->height, data);
	i = 0;
	while (zr * zr + zi * zi <= 4 && i < max_iterations)
	{
		tmp = zr * zr - zi * zi + data->julia_cr;
		zi = 2 * zr * zi + data->julia_ci;
		zr = tmp;
		i++;
	}
	return (i);
}

void	render_julia(t_data *data)
{
	int	x;
	int	y;
	int	iter;
	int	color;
	int	iterations;

	iterations = 100;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			iter = julia(data, x, y, iterations);
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
