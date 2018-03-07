/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_addrinfo.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 11:32:34 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 11:32:36 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra.h"

void			init_addrinfo(T_ADDRINFO *hints)
{
	hints->ai_family = AF_UNSPEC;
	hints->ai_socktype = SOCK_RAW;
	hints->ai_flags = AI_PASSIVE;
	hints->ai_protocol = 0;
	hints->ai_canonname = NULL;
	hints->ai_addr = NULL;
	hints->ai_next = NULL;
}
