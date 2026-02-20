/* ************************************************************************** */
/*																				*/
/*															:::	   ::::::::   */
/*		filter.c											:+:		 :+:	:+:   */
/*														+:+ +:+		  +:+	  */
/*		By: ehuet <ehuet@student.42.fr>				+#+  +:+	   +#+		  */
/*													+#+#+#+#+#+	+#+			  */
/*		Created: 2026/02/13 11:58:15 by ehuet			   #+#	  #+#			  */
/*		Updated: 2026/02/16 10:30:12 by ehuet			  ###	########.fr		  */
/*																				*/
/* ************************************************************************** */

#define _GNU_SOURCE

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	char	*tmp;
	char	*buf;
	int		tmp_len = 0, bytes_read = 1, total, pat_len;
		char *match;

	if (!av[1] || ac != 2)
		return (1);
	tmp = malloc(strlen(av[1]));
	if (!tmp)
	{
		perror("Error : failed malloc allocation");
		return (1);
	}
	buf = malloc(4096);
	if (!buf)
	{
		perror("Error");
		return (1);
	}
	tmp_len = 0, bytes_read = 1, total, pat_len = strlen(av[1]);
	while (bytes_read > 0)
	{
		bytes_read = read(0, buf, 4096);
		if (bytes_read < 0)
		{
			perror("Error");
			return (1);
		}
		if (tmp_len > 0)
		{
			memmove(buf + tmp_len, buf, bytes_read);
			memmove(buf, tmp, tmp_len);
		}
		total = tmp_len + bytes_read;
		while ((match = memmem(buf, total, av[1], pat_len)) != NULL)
		{
			for (int i = 0; i < pat_len; i++)
				match[i] = '*';
		}
		write(1, buf, total - (pat_len - 1));
		memmove(tmp, buf + total - (pat_len - 1), pat_len - 1);
		tmp_len = pat_len - 1;
	}
	write(1, tmp, tmp_len);
}

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 16
#endif

int	main(int ac, char *av)
{
	size_t	len;
	char	buffer[BUFFER_SIZE];
	char	*s;
	ssize_t	n;
	size_t	size;
	char	*p;
	char	*pos;

	if (ac != 2)
		return (1);
	len = strlen(av[1]);
	s = 0;
	size = 0;
	while ((n = read(0, buffer, BUFFER_SIZE)))
	{
		if (n == -1 || !(s = realloc(s, n)))
		{
			if (s)
				free(s);
			perror("Error");
			return (1);
		}
		memmove(s + size, buffer, n);
		size += n;
	}
	s[size] = 0;
	pos = s;
	while ((p = memmem(pos, strlen(pos), av[1], len)))
	{
		write(1, pos, p - pos);
		for (int i = 0; i < len; i++)
			write(1, "*", 1);
		pos = p + len;
	}
	write(1, pos, strlen(pos));
	free(s);
}

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int	total = 0, cpt = 0, len;

	if (ac != 2 || !av[1])
		return (1);
	total = 0, cpt = 0, len = strlen(av[1]);
	char *match, *buff = NULL, tmp[1024];
	while ((cpt = read(0, tmp, 1024)) > 0)
	{
		if (!(buff = realloc(buff, total + cpt)))
			return (fprintf(stdout, "Error : l"), 1);
		memmove(buff + total, tmp, cpt);
		total += cpt;
	}
	if (cpt < 0)
		return (fprintf(stdout, "Error : l"), free(buff), 1);
	match = buff;
	while ((match = memmem(match, total - (match - buff), av[1], len)) != NULL)
	{
		for (int i = 0; i < len; i++)
			match[i] = '*';
		match += len;
	}
	if (buff)
		write(1, buff, total);
	free(buff);
	return (0);
}
