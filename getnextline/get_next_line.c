/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:29:16 by ehuet             #+#    #+#             */
/*   Updated: 2025/11/20 14:13:29 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char	*gnl_stash(char )
{
//read ici on envoie le buffer dans stash
	char	*stash; 
	char	*buf;
	
	
	
}
char	*get_next_line(int fd)
{
	char	*str;
	int		fd;
	char	*buf;
	size_t	rbytes;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = NULL;
	buf = NULL;
	rbytes = 1;

	return (str);
}

int	main(void)
{

}