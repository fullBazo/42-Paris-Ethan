/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupoix <rdupoix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 16:58:30 by rdupoix           #+#    #+#             */
/*   Updated: 2026/07/01 14:59:50 by rdupoix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	collision(t_game *game, float x, float y)
{
	float	m;

	m = 10;
	if (game->cfg.map[(int)((y - m) / 64)][(int)((x - m) / 64)] == '1'
		|| game->cfg.map[(int)((y - m) / 64)][(int)((x + m) / 64)] == '1'
		|| game->cfg.map[(int)((y + m) / 64)][(int)((x - m) / 64)] == '1'
		|| game->cfg.map[(int)((y + m) / 64)][(int)((x + m) / 64)] == '1')
		return (1);
	return (0);
}
