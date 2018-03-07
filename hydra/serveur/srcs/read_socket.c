/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_socket.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 16:36:08 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 11:14:31 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra.h"

t_readsock		*read_socket(SOCKET sfd)
{
	t_readsock		*out;
	ssize_t			ret;

	if ((out = ft_readsock_new(sfd)) == NULL)
		return (NULL);
	while ((out->msg_len = recvfrom(sfd, out->msg, BUF_MSG_SIZE, 0,
					(T_ADDR *)&(out->peer_addr), &(out->peer_addr_len))) == -1)
		continue ;
	if ((ret = getnameinfo((const T_ADDR *)&(out->peer_addr), out->peer_addr_len,
					out->host, NI_MAXHOST,
					out->serv, NI_MAXSERV, NI_NUMERICSERV)) != 0)
		fprintf(stderr, "getnameinfo: %s\n", gai_strerror(ret));
	return (out);
}
