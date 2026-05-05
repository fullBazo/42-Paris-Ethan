/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:00:00 by ehuet             #+#    #+#             */
/*   Updated: 2026/03/29 13:59:33 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void	exec_pwd(void)
{
	char	buf[PATH_MAX];

	if (!getcwd(buf, PATH_MAX))
	{
		ft_putstr_fd("chdir: error retrieving current directory:", 2);
		ft_putstr_fd("getcwd: cannot access parent directories:", 2);
		ft_putstr_fd(" No such file or directory\n", 2);
	}
	else
		printf("%s\n", buf);
}
