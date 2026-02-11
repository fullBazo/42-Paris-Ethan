/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:53:26 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/11 15:01:14 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_struct(t_data *d)
{
	d->height = 800;
	d->width = 800;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->width, d->height, "fract-ol");
	d->img = mlx_new_image(d->mlx, d->width, d->height);
	d->address = mlx_get_data_addr(d->img, &d->bpp, &d->line_l, &d->endian);
	d->min_x = -2.0;
	d->max_x = 2.0;
	d->min_y = -2.0;
	d->max_y = 2.0;
	d->julia = 0;
	d->mandel = 0;
}

void	exec_julia(t_data *data, char **av)
{
	init_struct(data);
	data->julia = 1;
	data->julia_cr = ft_atob(av[2]);
	data->julia_ci = ft_atob(av[3]);
	render_julia(data);
	mlx_event_hook(data);
}

void	exec_mandel(t_data *data)
{
	init_struct(data);
	data->mandel = 1;
	render_mandel(data, 0, 0);
	mlx_event_hook(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac >= 2)
	{
		if (ft_strncmp(av[1], "mandelbrot", 11) == 0)
		{
			exec_mandel(&data);
		}
		else if (ft_strncmp(av[1], "julia", 6) == 0 && ac == 4)
		{
			if (parse_arg(av))
			{
				exec_julia(&data, av);
			}
			else
				ft_printf("julia : args not valid.\nUse digits instead.\n");
		}
		else
			ft_printf("args not valid : julia [value] [value] or mandelbrot\n");
	}
	else
		ft_printf("args not valid : julia [value] [value] or mandelbrot\n");
}
