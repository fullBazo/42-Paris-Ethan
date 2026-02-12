/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:31:30 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/11 14:33:23 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	ft_atob(const char *str)
{
	double (sign) = 1;
	double (result) = 0;
	double (divisor) = 0.1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - 48);
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			result = result + (*str++ - 48) * divisor;
			divisor *= 0.1;
		}
	}
	return (result * sign);
}

int	parse_arg(char **av)
{
	int (i) = 2;
	int (j);
	while (i < 4)
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		if (!(av[i][j] >= '0' && av[i][j] <= '9'))
			return (0);
		while (av[i][j] >= '0' && av[i][j] <= '9')
			j++;
		if (av[i][j] == '.')
		{
			j++;
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (0);
			while (av[i][j] >= '0' && av[i][j] <= '9')
				j++;
		}
		if (av[i][j] != '\0')
			return (0);
		i++;
	}
	return (1);
}

void	mlx_event_hook(t_data *data)
{
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, 0, close_free, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_loop(data->mlx);
}

int	close_free(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(1);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_free(data);
	else if (keycode == 65362)
		move(data, 1);
	else if (keycode == 65364)
		move(data, 2);
	else if (keycode == 65361)
		move(data, 3);
	else if (keycode == 65363)
		move(data, 4);
	return (1);
}
