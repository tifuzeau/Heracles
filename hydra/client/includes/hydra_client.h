/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hydra_client.h                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 15:05:24 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 15:21:59 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HYDRA_CLIENT_H
# define HYDRA_CLIENT_H

/*
********************************************************************************
**								INCLUDES                                      **
********************************************************************************
*/

#include "libft.h"

#include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# include <netdb.h>

# include <sys/types.h>
# include <sys/socket.h>

/*
********************************************************************************
**								DEFINE                                        **
********************************************************************************
*/

# define BUF_SIZE			1024

# define SUCCESS			1
# define FAIL				0

# define END				2

# define SOCKET				int

# define T_ADDR				struct sockaddr
# define T_ADDRINFO			struct addrinfo
# define T_SOCKADDR			struct sockaddr_storage

# define BUF_MSG_SIZE		1024


/*
** Define for flag in parseur.c
*/

/*
**	deflaut valu for flag
*/

# define DEFLAUT_PORT		"1111"
# define DEFLAUT_HOST		"localhost"

/*
********************************************************************************
**								STRUCTURE                                     **
********************************************************************************
*/

typedef struct		s_flag
{
	unsigned int	flag;
	char			*port;
	char			*host;
}					t_flag;

typedef struct		s_readsock
{
	SOCKET				sfd;
	char			host[NI_MAXHOST + 1];
	char			serv[NI_MAXSERV + 1];
	char			msg[BUF_MSG_SIZE + 1];
	ssize_t			msg_len;
	T_SOCKADDR		peer_addr;
	socklen_t		peer_addr_len;
}					t_readsock;


/*
********************************************************************************
**								FONCTION                                      **
********************************************************************************
*/

/*
**	in ft_flag_new.c
*/
t_flag				*ft_flagnew_client(void);

/*
**	in ft_flagdel.c
*/
void				ft_flagdel_client(t_flag **as);


/*
**	in ft_readsock_new.c
*/
t_readsock			*ft_readsock_new_client(SOCKET sfd);

/*
**	in ft_readsock_del.c
*/
void				ft_readsock_del_client(t_readsock **as);

/*
**	in open_socket.c
*/
SOCKET					open_socket_client(T_ADDRINFO *lstaddrinfo);

/*
**	in read_socket.c
*/
t_readsock			*read_socket_client(int sfd);

/*
**	in write_socket.c
*/
int					write_socket_client(t_readsock *msg, const char *str);

/*
**						PROGRAMME
*/

/*
**	in ft_usage.c
*/
void				ft_usage_client(const char *str);

/*
**	in deflaut_flag.c
*/
void				deflaut_flag_client(t_flag *flag);

/*
**	in print_info.c
*/
void				print_info(t_flag *flag);

/*
**	in init_addrinfo.c
*/
void				init_addrinfo_client(T_ADDRINFO *hints);

/*
**	in parseur.c
*/
t_flag				*parseur_client(int argc, const char **argv);

#endif
