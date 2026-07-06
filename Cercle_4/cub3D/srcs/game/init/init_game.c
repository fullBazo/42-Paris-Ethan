/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupoix <rdupoix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:18:10 by ehuet             #+#    #+#             */
/*   Updated: 2026/07/02 11:59:50 by rdupoix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	err_assets(t_game *game)
{
	ft_putstr_fd("Error\nXPM file non valid\n", 2);
	cleanup_and_exit(game);
}

void	init_xpm(t_game *game)
{
	game->tex_no.img = mlx_xpm_file_to_image(game->mlx, game->cfg.tex[0],
			&game->tex_no.width, &game->tex_no.height);
	if (!game->tex_no.img)
		err_assets(game);
	game->tex_no.addr = mlx_get_data_addr(game->tex_no.img, &game->tex_no.bpp,
			&game->tex_no.line_l, &game->tex_no.endian);
	game->tex_so.img = mlx_xpm_file_to_image(game->mlx, game->cfg.tex[1],
			&game->tex_so.width, &game->tex_so.height);
	if (!game->tex_so.img)
		err_assets(game);
	game->tex_so.addr = mlx_get_data_addr(game->tex_so.img, &game->tex_so.bpp,
			&game->tex_so.line_l, &game->tex_so.endian);
	game->tex_ea.img = mlx_xpm_file_to_image(game->mlx, game->cfg.tex[2],
			&game->tex_ea.width, &game->tex_ea.height);
	if (!game->tex_ea.img)
		err_assets(game);
	game->tex_ea.addr = mlx_get_data_addr(game->tex_ea.img, &game->tex_ea.bpp,
			&game->tex_ea.line_l, &game->tex_ea.endian);
	game->tex_we.img = mlx_xpm_file_to_image(game->mlx, game->cfg.tex[3],
			&game->tex_we.width, &game->tex_we.height);
	if (!game->tex_we.img)
		err_assets(game);
	game->tex_we.addr = mlx_get_data_addr(game->tex_we.img, &game->tex_we.bpp,
			&game->tex_we.line_l, &game->tex_we.endian);
}

void	init_mlx(t_game *gm)
{
	gm->mlx = mlx_init();
	gm->mlx_win = mlx_new_window(gm->mlx, 1280, 720, "cub3d");
	gm->img = mlx_new_image(gm->mlx, 1280, 720);
	gm->addr = mlx_get_data_addr(gm->img, &gm->data.bpp,
			&gm->data.line_l, &gm->data.endian);
	init_xpm(gm);
}

void	init_all(t_game *game)
{
	spawn_player(game);
	init_mlx(game);
}
