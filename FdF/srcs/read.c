/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:09:57 by ehuet             #+#    #+#             */
/*   Updated: 2025/12/05 14:44:23 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

t_point	**alloc_map(char *filename, int *width, int *height)
{
	int 	fd;
	int		i;
	char	*line;
	int		z;
	char	**values;
	
	line = NULL;
	z = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while ((line = get_next_line(fd)))
	{
		
	}
}


// pour l'instant je teste juste si ma fonction lit bien tout les char des .fdf
// a voir comment malloc la place necessaire proprement
int	main(void)
{
	char	*test = "test_maps/basictest.fdf";

	ft_printf("%s\n", alloc_map(test));
	return (0);
}
