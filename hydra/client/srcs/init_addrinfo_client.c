/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_addrinfo_client.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 15:00:55 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 15:00:55 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra_client.h"

void			init_addrinfo_client(T_ADDRINFO *hints)
{
	hints->ai_family = AF_UNSPEC;
	hints->ai_socktype = SOCK_RAW;
	hints->ai_flags = AI_PASSIVE;
	hints->ai_protocol = 0;
	hints->ai_canonname = NULL;
	hints->ai_addr = NULL;
	hints->ai_next = NULL;
}
