/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 12:46:11 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 11:16:46 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra.h"

int			write_socket(t_readsock *msg, const char *str)
{
	ssize_t		ret;

	if ((ret = sendto(msg->sfd, str, ft_strlen(str), 0,
					(const T_ADDR *)&(msg)->peer_addr, msg->peer_addr_len))
			!= (ssize_t)ft_strlen(str))
		return (-1);
	return (1);
}
