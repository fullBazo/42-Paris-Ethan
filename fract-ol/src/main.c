/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 main.c												:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ehuet <ehuet@student.42.fr>				+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/01/30 13:23:29 by ehuet			   #+#	  #+#			  */
/*	 Updated: 2026/02/06 15:05:58 by ehuet			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../fractol.h"

void	init_struct(t_data *data, t_fractol *f)
{
	data->height = 600;
	data->width = 800;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width, data->height, "fract-ol");
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	data->address = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	f->max_iterations = 100;
}

void    zoom_in(t_data *data, int mouse_x, int mouse_y)
{
	double 	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
    double  mouse_cr = complex_x(mouse_x, data->width);
    double  mouse_ci = complex_y(mouse_y, data->height);
    double  zoom_factor = 0.8;  // Zoome de 20%
    
    double  range_x = (3.5 - 2.5) * zoom_factor;
    double  range_y = (2.0 - 1.0) * zoom_factor;
    
    // Recentre autour du point de la souris
    min_x = mouse_cr - range_x / 2;
    max_x = mouse_cr + range_x / 2;
    min_y = mouse_ci - range_y / 2;
    max_y = mouse_ci + range_y / 2;
    
    // Ensuite re-render la fractale
}

int	main()
{
	t_data data;
	t_fractol f;

	init_struct(&data, &f);
	render_mandel(&data, &f);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);

}
