/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:53:26 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/09 17:05:02 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    putnbr(int i)
{
    if (i > 9)
        putnbr(i / 10);
    write(1, &"0123456789"[i % 10], 1);
} 

int main(void)
{
    int i;

    i = 1;
    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if (i % 3 == 0)
            write(1, "fizz", 4);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else
            putnbr(i);
        write(1, "\n", 1);
        i++;
    }
}