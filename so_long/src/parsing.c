/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:33:04 by ehuet             #+#    #+#             */
/*   Updated: 2025/12/18 12:14:50 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_extension(t_game *game)
{
	int	len;

	if (!game->filename)
		exit(ft_printf("Error\nThe name of file is empty.\n"));
	len = ft_strlen(game->filename);
	if (len < 4)
		exit(ft_printf("Error\nInvalid file name.\n"));
	if (ft_strncmp(game->filename + len - 4, ".ber", 4) != 0)
		exit(ft_printf("Error\nExtension not found.\n"));
}

void	openfile(t_game *game)
{
	game->fd = open(game->filename, O_RDONLY);
	if (game->fd < 0)
		exit(ft_printf("Error\nFile cannot be opened.\n"));
}

void	count_height(t_game *game)
{
	char	*line;

	line = get_next_line(game->fd);
	while (line)
	{
		free(line);
		game->map_height++;
		line = get_next_line(game->fd);
	}
	free(line);
	close(game->fd);
}

void	read_map(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	openfile(game);
	line = get_next_line(game->fd);
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
	{
		so_shlong_free_map(game);
		exit(ft_printf("Error\nMalloc failed.\n"));
	}
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		game->map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(game->fd);
	}
	free(line);
	game->map[i] = NULL;
}

void	parsing(t_game *game)
{
	check_extension(game);
	openfile(game);
	count_height(game);
	read_map(game);
	check_rectangle(game);
	check_u_d_wall(game);
	check_border(game);
	check_valid_element(game);
	check_elements(game);
}
