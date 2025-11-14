/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:57:22 by ehuet             #+#    #+#             */
/*   Updated: 2025/11/14 15:34:06 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_current;
	t_list	*new_node;
	void	*new_content;
	
	if (!lst || !f)
		return (NULL);
	new_content = (*f)(lst->content);
	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = new_content;
	new_list->next = NULL;
	new_current = new_list;
	lst = lst->next;
	while (lst)
	{
		new_content = (*f)(lst->content);
		new_node = malloc(sizeof(t_list));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_node->content = new_content;
		new_node->next = NULL;
		new_current->next = new_node;
		new_current = new_node;
		lst = lst->next;
	}
	return (new_list);
}