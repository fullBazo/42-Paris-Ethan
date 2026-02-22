/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:52:05 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/22 14:52:12 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

//MESSAGES
# define MSG_OK 0

//ERRORS
# define ERR_BASE 1
# define ERR_MALLOC 2
# define ERR_MUTEX 3
# define ERR_GET_TIME 4
# define ERR_ARGS_NB 11
# define ERR_ARGS_FORMAT 12

//MESSAGES
int	msg(int msg_code);

#endif
