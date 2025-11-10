/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:06:31 by ehuet             #+#    #+#             */
/*   Updated: 2025/11/07 14:46:56 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *memBlock, int schar, size_t size)
{
	size_t			i;
	unsigned char	*mb;
	unsigned char	sc;

	i = 0;
	mb = (unsigned char *)memBlock;
	sc = (unsigned char)schar;
	while (i < size)
	{
		if (mb[i] == sc)
			return (&mb[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    const unsigned int size = 10;

    // On recherche une valeur inhéxistante :
    void *found = memchr( data, 57, size );
    printf( "57 is %s\n", ( found != NULL ? "found" : "not found" ) );

    // On recherche une valeur existante :
    found = memchr( data, 50, size );
    printf( "50 is %s\n", ( found != NULL ? "found" : "not found" ) );
    if ( found != NULL ) {
        printf( "La valeur à la position calculée est %d\n", *((char *) found) );
    }

    printf( "57 is %s\n", ( found != NULL ? "found" : "not found" ) );

    // On recherche une valeur existante :
    found = ft_memchr( data, 50, size );
    printf( "50 is %s\n", ( found != NULL ? "found" : "not found" ) );
    if ( found != NULL ) {
        printf( "La valeur à la position calculée est %d\n", *((char *) found) );
    }
}
*/