/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reseau.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 16:37:31 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 14:52:15 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra.h"

SOCKET		reseau(t_flag *flag)
{
	int				ret;
	SOCKET			sfd;
	T_ADDRINFO		hints;
	T_ADDRINFO		*out_addr_info;

	init_addrinfo(&hints);
	if ((ret = getaddrinfo(NULL, flag->port, &hints, &out_addr_info)) != 0)
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
		exit(EXIT_FAILURE);
	}
	if ((sfd = open_socket(out_addr_info)) == -1)
	{
		fprintf(stderr, "Could not bind\n");
		exit(EXIT_FAILURE);
	}
	return (sfd);
}
