/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:38:14 by ehuet             #+#    #+#             */
/*   Updated: 2025/12/12 13:53:58 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(const char *filename, t_game *game)
{
	char	**map;
	int		fd;
	char	*line;
	int		x;
	int		temp;
		
	x = 0;
	map = NULL;
	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		return (NULL);
	while ((line = get_next_line(fd)))
	{
		if (x < 1)
			game->map_width = ft_strlen(line);
			map[0] = ft_lstnew
			x++;
		game->map_height += 1;
		temp = ft_strlen(line);
		if (temp != game->map_width)
			return (-1);
	}
	return (map);
}