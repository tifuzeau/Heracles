/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hydra.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 12:35:45 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 14:59:41 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HYDRA_H
# define HYDRA_H

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
# include <fcntl.h>
# include <sys/stat.h>

# include <netdb.h>

# include <sys/types.h>
# include <sys/socket.h>

/*
********************************************************************************
**								DEFINE                                        **
********************************************************************************
*/

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

# define ARG_D				1


/*
**	deflaut valu for flag
*/

# define DEFLAUT_PORT		"1111"

/*
**	for daemon
*/

# define RUNNING_DIR		"/Users/timfuzea/"
/*
** S_I  R | W | X , USR | GRP | OTH
** S_IRWXU	00700	lecture/écriture/exécution du propriétaire
** S_IRWXG	00070	lecture/écriture/exécution du groupe
** S_IRWXO	00007	lecture/écriture/exécution des autres
*/

# define DEFAULT_RIGHT		S_IRWXU | S_IRGRP | S_IROTH

/*
********************************************************************************
**								STRUCTURE                                     **
********************************************************************************
*/

typedef struct		s_flag
{
	unsigned int	flag;
	char			*port;
}					t_flag;

/*
typedef struct		s_check_flag
{
	char			*str;
	unsigned int	valu;
}					t_check_flag;
*/

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
t_flag				*ft_flagnew(void);

/*
**	in ft_flagdel.c
*/
void				ft_flagdel(t_flag **as);


/*
**	in ft_readsock_new.c
*/
t_readsock			*ft_readsock_new(SOCKET sfd);

/*
**	in ft_readsock_del.c
*/
void				ft_readsock_del(t_readsock **as);

/*
**	in open_socket.c
*/
SOCKET					open_socket(T_ADDRINFO *lstaddrinfo);

/*
**	in read_socket.c
*/
t_readsock			*read_socket(int sfd);

/*
**	in write_socket.c
*/
int					write_socket(t_readsock *msg, const char *str);

/*
**	in reseau.c
*/
SOCKET				reseau(t_flag *flag);

/*
**						PROGRAMME
*/

/*
**	in ft_usage.c
*/
void				ft_usage(const char *str);

/*
**	in parseur.c
*/
t_flag				*parseur(int argc, const char **argv);

/*
**	in deflaut_flag.c
*/
void				deflaut_flag(t_flag *flag);

/*
**	in print_info.c
*/
void				print_info(t_flag *flag);

/*
**	in init_addrinfo.c
*/
void				init_addrinfo(T_ADDRINFO *hints);

/*
**	in daemonize.c
*/
void				daemonize(void);
#endif
