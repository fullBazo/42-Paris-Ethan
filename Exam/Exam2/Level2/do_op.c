/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:13:33 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/12 14:27:03 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		switch(av[2][0])
		{
			case '+':
				printf("%d", atoi(av[1]) + atoi(av[3]));
				break;
			case '-':
				printf("%d", atoi(av[1]) - atoi(av[3]));
				break;
			case '*':
				printf("%d", atoi(av[1]) * atoi(av[3]));
				break;
			case '/':
				printf("%d", atoi(av[1]) + atoi(av[3]));
				break;
			case '%':
				printf("%d", atoi(av[1]) % atoi(av[3]));
				break;
		}
	}
	printf("\n");
}
