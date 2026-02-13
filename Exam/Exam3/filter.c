/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:58:15 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/13 13:22:20 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE

#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (!av[1] || ac != 2)
		return 1;

	char tmp[strlen(av[1])];
	char *buf = malloc(sizeof(char) * 4096 + strlen(av[1]));
	int	fd = 0, i = 0, tmp_len = 0, bytes_read = 1, total;

	memset(tmp, 0, strlen(av[1]));
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, 4096);
		if (tmp_len > 0)
		{
			memmove(buf + tmp_len, buf, bytes_read);
			memmove(buf, tmp, tmp_len);
		}
		total = tmp_len + bytes_read;
		while (memmem(buf, total, av[1], strlen(av[1])))
		{
			
		}
	}
}

