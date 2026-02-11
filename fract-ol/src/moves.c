/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:03:12 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/11 15:15:54 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	is_julia_or_mandel(t_data *data)
{
	if (data->mandel)
		render_mandel(data, 0, 0);
	else
		render_julia(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	zoom_in(t_data *data, int mouse_x, int mouse_y)
{
	double	mouse_cr;
	double	mouse_ci;
	double	zoom_factor;
	double	range_x;
	double	range_y;

	zoom_factor = 0.9;
	mouse_ci = complex_y(mouse_y, data->height, data);
	mouse_cr = complex_x(mouse_x, data->width, data);
	range_x = (data->max_x - data->min_x) * zoom_factor;
	range_y = (data->max_y - data->min_y) * zoom_factor;
	data->min_x = mouse_cr - range_x / 2;
	data->max_x = mouse_cr + range_x / 2;
	data->min_y = mouse_ci - range_y / 2;
	data->max_y = mouse_ci + range_y / 2;
	is_julia_or_mandel(data);
}

void	zoom_out(t_data *data, int mouse_x, int mouse_y)
{
	double	mouse_cr;
	double	mouse_ci;
	double	zoom_factor;
	double	range_x;
	double	range_y;

	zoom_factor = 0.9;
	mouse_ci = complex_y(mouse_y, data->height, data);
	mouse_cr = complex_x(mouse_x, data->width, data);
	range_x = (data->max_x - data->min_x) / zoom_factor;
	range_y = (data->max_y - data->min_y) / zoom_factor;
	data->min_x = mouse_cr - range_x / 2;
	data->max_x = mouse_cr + range_x / 2;
	data->min_y = mouse_ci - range_y / 2;
	data->max_y = mouse_ci + range_y / 2;
	is_julia_or_mandel(data);
}

void	move(t_data *data, int key)
{
	data->decal_x = (data->max_x - data->min_x) * 0.05;
	data->decal_y = (data->max_y - data->min_y) * 0.05;
	if (key == 1)
	{
		data->min_y -= data->decal_y;
		data->max_y -= data->decal_y;
	}
	else if (key == 2)
	{
		data->min_y += data->decal_y;
		data->max_y += data->decal_y;
	}
	else if (key == 3)
	{
		data->min_x -= data->decal_x;
		data->max_x -= data->decal_x;
	}
	else if (key == 4)
	{
		data->min_x += data->decal_x;
		data->max_x += data->decal_x;
	}
	is_julia_or_mandel(data);
}
