/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:09:57 by ehuet             #+#    #+#             */
/*   Updated: 2025/12/05 13:53:57 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

int	alloc_map(char *filename)
{
	int 	fd;
	char	*line;
	int		count;
	
	line = NULL;
	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((line = get_next_line(fd)))
	{
		count += ft_strlen(line);
		free(line);
	}
	return (count);
}


// pour l'instant je teste juste si ma fonction lit bien tout les char des .fdf
// a voir comment malloc la place necessaire proprement
int	main(void)
{
	char	*test = "test_maps/mars.fdf";

	ft_printf("%d\n", alloc_map(test));
	return (0);
}
