/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:47:09 by ehuet             #+#    #+#             */
/*   Updated: 2025/12/17 14:18:32 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
//# include "mlx.h"
# include "./libft/libft.h"

typedef struct s_game
{
	char	**map;
	int		map_height;
	char	*filename;
	int		fd;
}				t_game;

void	check_extension(t_game *game);
void	openfile(t_game *game);
void	count_height(t_game *game);
void	read_map(t_game *game);
void	parsing(t_game *game);
void	init_struct(t_game *game, char **av);

#endif
