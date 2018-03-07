/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   open_socket.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 16:36:47 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 11:14:17 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra.h"

SOCKET			open_socket(T_ADDRINFO *lst_addrinfo)
{
	SOCKET			sfd;
	T_ADDRINFO		*tmp;

	tmp = lst_addrinfo;
	while (tmp != NULL)
	{
		if ((sfd = socket(tmp->ai_family, tmp->ai_socktype, tmp->ai_protocol)) == -1)
			continue;
		if (bind(sfd, tmp->ai_addr, tmp->ai_addrlen) == 0)
			break ;
		close(sfd);
		tmp = tmp->ai_next;
	}
	freeaddrinfo(lst_addrinfo);
	if (tmp == NULL)
		return (-1);
	return (sfd);
}
