/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:29:16 by ehuet             #+#    #+#             */
/*   Updated: 2025/11/20 17:13:24 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char	*gnl_stash(char *tmp, char *buf, ssize_t rbytes)
{
	char	*keep_tmp;
	ssize_t	len;

	len = 0;
	keep_tmp = NULL;
	if (tmp)
	{
		keep_tmp = ft_strdup(tmp);
		free(tmp);
		len = ft_strlen(keep_tmp) + ft_strlen(buf);
		tmp = malloc(len + 1);
		if (!tmp)
			return (NULL);
		ft_memcpy(tmp, keep_tmp, ft_strlen(keep_tmp) + 1);
		tmp[ft_strlen(keep_tmp)] = '\0';
		ft_memcpy(ft_strchr(tmp, '\0'), buf, ft_strlen(buf));
		tmp[ft_strlen(len)] = '\0';
		free(keep_tmp);
	}	
	else if (!tmp)
		tmp = ft_strdup(buf);
	return (tmp);
	
	
}

char	*get_next_line(int fd)
{
	static char *tmp;
	char		*str;
	char		*buf;
	ssize_t		rbytes;

	str = NULL;
	buf = NULL;
	rbytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (rbytes != 0)
	{
		if (ft_strchr(tmp,'\n') != NULL)
			//return ();
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		rbytes = read(fd, buf, BUFFER_SIZE);
		if (rbytes <= 0)
			return (NULL);
		tmp = gnl_stash(tmp, buf, rbytes);
		free(buf);
		buf = NULL;
	}
	return ();
}

int	main(void)
{

}