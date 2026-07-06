/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupoix <rdupoix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 18:48:05 by rdupoix           #+#    #+#             */
/*   Updated: 2026/07/01 14:13:31 by rdupoix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "includes/cub3d.h"

/* ============================= parse_scene.c ============================== */

int		parse_scene(int ac, char *arg, t_game *game);

/* ============================= read_scene.c =============================== */

int		count(char **tab);
t_err	read_scene(int fd, t_config *cfg);

/* ============================= parse_utils.c ============================== */

void	free_tab(char **tab);
int		is_map(char c);
int		is_map_line(char *line);
int		which_id(char *line, char *id);
int		is_space(char c);
int		is_player(char c);

/* ============================ parse_element.c ============================= */

t_err	parse_color(char *line, t_color *col);
t_err	parse_texture(t_config *cfg, char *line, t_elem elem);

/* ============================= collect_map.c ============================== */

t_err	collect_map(char *first_line, int fd, t_config *cfg);

/* ============================= validate_map.c ============================= */

t_err	validate_map(t_config *cfg);

/* ============================== flood_fill.c ============================== */

t_err	check_corners(t_config *cfg);
t_err	check_closed(t_config *cfg);

/* ================================== end =================================== */

#endif