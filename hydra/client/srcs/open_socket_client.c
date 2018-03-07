/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   open_socket_client.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 15:00:56 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 15:00:56 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra_client.h"

SOCKET			open_socket_client(T_ADDRINFO *lst_addrinfo)
{
	SOCKET			sfd;
	T_ADDRINFO		*tmp;

	tmp = lst_addrinfo;
	while (tmp != NULL)
	{
		if ((sfd = socket(tmp->ai_family, tmp->ai_socktype, tmp->ai_protocol)) == -1)
			continue;
		if (connect(sfd, tmp->ai_addr, tmp->ai_addrlen) == 0)
			break ;
		close(sfd);
		tmp = tmp->ai_next;
	}
	freeaddrinfo(lst_addrinfo);
	if (tmp == NULL)
		return (-1);
	return (sfd);
}
