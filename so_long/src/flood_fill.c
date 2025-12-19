/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:54:25 by ehuet             #+#    #+#             */
/*   Updated: 2025/12/18 16:17:47 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(char **grid, int x, int y, t_ff *ff)
{
	if (x < 0 || x >= ff->grid_height || y < 0 || y >= ff->grid_width)
		return ;
	if (grid[x][y] == '1')
		return ;
	flood_fill(ff->grid[x]);
	flood_fill();
	flood_fill();
	flood_fill();


}


