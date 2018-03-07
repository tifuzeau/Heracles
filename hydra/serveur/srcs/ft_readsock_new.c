/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_readsock_new.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 15:04:27 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 11:12:19 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra.h"

t_readsock		*ft_readsock_new(SOCKET sfd)
{
	t_readsock		*out;

	if ((out = malloc(sizeof(t_readsock))) == NULL)
		return (NULL);
	out->sfd = sfd;
	ft_bzero(out->host, NI_MAXHOST);
	ft_bzero(out->serv, NI_MAXSERV);
	ft_bzero((void *)&(out->peer_addr), sizeof(T_SOCKADDR));
	out->peer_addr_len = sizeof(T_SOCKADDR);
	return (out);
}
