/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 08:22:43 by ehuet             #+#    #+#             */
/*   Updated: 2026/07/01 08:25:31 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int code, t_game *game)
{
	if (code == KEY_ESC)
		cleanup_and_exit(game);
	if (code == KEY_W)
		game->move.w = 1;
	if (code == KEY_S)
		game->move.s = 1;
	if (code == KEY_A)
		game->move.a = 1;
	if (code == KEY_D)
		game->move.d = 1;
	if (code == KEY_LEFT)
		game->move.left = 1;
	if (code == KEY_RIGHT)
		game->move.right = 1;
	return (0);
}

int	key_release(int code, t_game *game)
{
	if (code == KEY_W)
		game->move.w = 0;
	if (code == KEY_S)
		game->move.s = 0;
	if (code == KEY_A)
		game->move.a = 0;
	if (code == KEY_D)
		game->move.d = 0;
	if (code == KEY_LEFT)
		game->move.left = 0;
	if (code == KEY_RIGHT)
		game->move.right = 0;
	return (0);
}
