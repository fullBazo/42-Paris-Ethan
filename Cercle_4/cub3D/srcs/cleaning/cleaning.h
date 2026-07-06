/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupoix <rdupoix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:57:45 by rdupoix           #+#    #+#             */
/*   Updated: 2026/06/26 17:09:36 by rdupoix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANING_H
# define CLEANING_H

# include "includes/cub3d.h"
# include "includes/struct.h"

/* =============================== errors.c ================================ */

char	*err_str(t_err err);
void	free_config(t_game *game);
int		fail(t_game *game, t_err err);
void	cleanup_and_exit(t_game *game);
void	free_mlx(t_game *game);

/* ================================== end ================================== */

#endif