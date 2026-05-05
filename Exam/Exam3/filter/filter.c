/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 10:41:14 by ehuet             #+#    #+#             */
/*   Updated: 2026/04/10 11:26:20 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, int len)
{
	int	i;

	i = 0;
	while (i != len - 1 && s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0, j, read_count = 0, len = strlen(av[1]);
		char c;
		char str[70000];

		read_count = read(0, &c, 1);
		if (read_count <= 0)
		{
			perror("Error :");
			return (1);
		}
		while (read_count)
		{
			str[i] = c;
			i++;
			read_count = read(0, &c, 1);
		}
		str[i] = 0;
		i = 0;
		while (str[i])
		{
			if (ft_strncmp(av[1], &str[i], len) == 0)
			{
				j = 0;
				while (j != len)
				{
					write(1, "*", 1);
					i++;
					j++;
				}
			}
			else
				write(1, &str[i++], 1);
		}
	}
	else
		return (1);
}