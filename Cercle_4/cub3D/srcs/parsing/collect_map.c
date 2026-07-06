/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupoix <rdupoix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:56:10 by rdupoix           #+#    #+#             */
/*   Updated: 2026/06/26 16:59:26 by rdupoix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_err	list_to_map(t_list *lst, t_config *cfg)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		cfg->map[i] = ft_strdup(tmp->content);
		if (!cfg->map[i])
			return (ERR_MALLOC);
		if ((int)ft_strlen(cfg->map[i]) > cfg->map_w)
			cfg->map_w = (int)ft_strlen(cfg->map[i]);
		tmp = tmp->next;
		i++;
	}
	cfg->map[cfg->map_h] = NULL;
	return (OK);
}

static t_err	build_list(char *first_line, int fd, t_list **lst)
{
	t_list	*node;
	char	*copy;
	char	*line;

	copy = ft_strtrim(first_line, "\n");
	if (!copy)
		return (ERR_MALLOC);
	node = ft_lstnew(copy);
	if (!node)
		return (free(copy), ERR_MALLOC);
	ft_lstadd_back(lst, node);
	line = get_next_line(fd);
	while (line)
	{
		copy = ft_strtrim(line, "\n");
		if (!copy)
			return (ft_lstclear(lst, free), free(line), ERR_MALLOC);
		node = ft_lstnew(copy);
		if (!node)
			return (ft_lstclear(lst, free), free(line), free(copy), ERR_MALLOC);
		ft_lstadd_back(lst, node);
		free(line);
		line = get_next_line(fd);
	}
	return (OK);
}

t_err	collect_map(char *first_line, int fd, t_config *cfg)
{
	t_list	*lst;
	t_err	err;

	lst = NULL;
	err = build_list(first_line, fd, &lst);
	if (err != OK)
		return (err);
	cfg->map_h = ft_lstsize(lst);
	cfg->map_w = 0;
	cfg->map = ft_calloc((cfg->map_h + 1), sizeof(char *));
	if (!cfg->map)
		return (ft_lstclear(&lst, free), ERR_MALLOC);
	err = list_to_map(lst, cfg);
	ft_lstclear(&lst, free);
	if (err != OK)
		return (err);
	return (OK);
}
