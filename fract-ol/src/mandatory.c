/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:37:46 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/11 14:54:35 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	complex_x(int x, int width, t_data *data)
{
	return (data->min_x + ((double)x / width) * (data->max_x - data->min_x));
}

double	complex_y(int y, int height, t_data *data)
{
	return (data->min_y + ((double)y / height) * (data->max_y - data->min_y));
}

void	put_color(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address;
	dst += (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	create_color(int iter)
{
	int	r;
	int	g;
	int	b;
	int	color;

	r = 150 + (iter * 3) % 106;
	g = (iter * 5) % 150;
	b = 0;
	color = (r << 16) | (g << 8) | b;
	return (color);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	if (keycode == 4)
	{
		zoom_in(data, x, y);
		return (0);
	}
	else if (keycode == 5)
	{
		zoom_out(data, x, y);
		return (0);
	}
	return (1);
}
