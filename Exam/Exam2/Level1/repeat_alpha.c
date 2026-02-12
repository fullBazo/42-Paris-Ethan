/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:00:29 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/12 11:40:54 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	main(int ac, char **av)
{
	int i = 0;
	int count;
	if (ac == 2)
	{
		while (av[1][i])
		{
			count = 0;
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				count = av[1][i] - 96;
				while (count > 0)
				{ 
					write(1, &av[1][i], 1);
					count--;
				}
			}
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				count = av[1][i] - 64;
				while (count > 0)
				{    
					write(1, &av[1][i], 1);
					count--;
				}
			}
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
