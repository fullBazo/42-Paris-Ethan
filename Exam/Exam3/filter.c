/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 filter.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ehuet <ehuet@student.42.fr>				+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/02/13 11:58:15 by ehuet			   #+#	  #+#			  */
/*	 Updated: 2026/02/16 10:30:12 by ehuet			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#define _GNU_SOURCE

#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (!av[1] || ac != 2)
		return 1;

	char *tmp = malloc(strlen(av[1]));
	if (!tmp)
	{
		perror("Error : failed malloc allocation");
		return 1;
	}
	char *buf = malloc(4096);
	if (!buf)
	{
		perror("Error : failed malloc allocation");
		return 1;
	}
	int tmp_len = 0, bytes_read = 1, total, pat_len = strlen(av[1]);

	while (bytes_read > 0)
	{
		bytes_read = read(0, buf, 4096);
		if (bytes_read < 0)
		{
			perror ("Error : failed read on stdin");
			return 1;
		}
		if (tmp_len > 0)
		{
			memmove(buf + tmp_len, buf, bytes_read);
			memmove(buf, tmp, tmp_len);
		}
		total = tmp_len + bytes_read;
		char *match;
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
