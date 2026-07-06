/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupoix <rdupoix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:05:58 by rdupoix           #+#    #+#             */
/*   Updated: 2026/07/01 13:55:03 by rdupoix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_err	check_all_present(t_config *cfg)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!cfg->tex[i])
			return (ERR_MISSING);
		i++;
	}
	if (cfg->ceiling.set == false)
		return (ERR_MISSING);
	if (cfg->floor.set == false)
		return (ERR_MISSING);
	if (!cfg->map)
		return (ERR_MISSING);
	return (OK);
}

static t_err	check_args(int ac, char *arg)
{
	if (ac != 2)
		return (ERR_ARGS);
	if (ft_strlen(arg) < 4 || ft_strncmp(arg + (ft_strlen(arg) - 4), ".cub", 4))
		return (ERR_EXT);
	return (OK);
}

int	parse_scene(int ac, char *arg, t_game *game)
{
	int		fd;
	t_err	err;

	fd = -1;
	err = check_args(ac, arg);
	if (err != OK)
		return (fail(game, err));
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (fail(game, ERR_OPEN));
	err = read_scene(fd, &game->cfg);
	if (err != OK)
	{
		get_next_line(GNL_CLEAR);
		close(fd);
		return (fail(game, err));
	}
	err = validate_map(&game->cfg);
	if (err != OK)
		return (close(fd), fail(game, err));
	err = check_all_present(&game->cfg);
	if (err != OK)
		return (close(fd), fail(game, err));
	return (close(fd), EXIT_SUCCESS);
}
