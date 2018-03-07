/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_client.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 15:00:55 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 15:27:01 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra_client.h"

void			loop(SOCKET sfd)
{
	int			rret;
	int			ret;
	int			out;
	char		buf[BUF_SIZE + 1];
	char		*line;

	ret = 0;
	rret = 0;
	line = NULL;
	out = 1;
	while (out && (ret = get_next_line(0, &line)) > 0)
	{
		rret = write(sfd, line, ft_strlen(line));
		if (rret != (int)ft_strlen(line))
		{
			fprintf(stderr, "Fail to send\n");
			continue ;
		}
		if (ft_strequ(line, "exit") == 1)
			out = 0;
		ft_strdel(&line);
		rret = read(sfd, buf, BUF_SIZE);
		dprintf(1, "Serveur send: nbit=%d, str=%s\n", rret, buf);
		ft_strdel(&line);
	}
	if (ret == 0)
		exit(EXIT_SUCCESS);
}

int				main(int argc, const char *argv[])
{
	int				ret;
	t_flag			*flag;
	T_ADDRINFO		hints;
	T_ADDRINFO		*out_addr_info;

	ret = 0;
	init_addrinfo_client(&hints);
	if ((flag = parseur_client(argc - 1, &argv[1])) == NULL)
		exit(EXIT_FAILURE);
	deflaut_flag_client(flag);
	if ((ret = getaddrinfo(flag->host, flag->port, &hints, &out_addr_info)) != 0)
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
		exit(EXIT_FAILURE);
	}
	if ((ret = open_socket_client(out_addr_info)) == -1)
	{
		fprintf(stderr, "Could not bind\n");
		exit(EXIT_FAILURE);
	}
	print_info(flag);
	loop(ret);
	return (0);
}
