/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 12:46:11 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 14:53:11 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra.h"

void			loop(SOCKET sfd)
{
	t_readsock		*msg;

	msg = NULL;
	while (1)
	{
		if ((msg = read_socket(sfd)) == NULL)
			fprintf(stderr, "read_socket: %s\n", "maby malloc");
		dprintf(1, "Receve %s\n", msg->msg);
		if (ft_strequ(msg->msg, "ping") == 1)
		{
			if (write_socket(msg, "pong") == -1)
				fprintf(stderr, "write_socket: %s\n", strerror(errno));
		}
		else if (ft_strequ(msg->msg, "exit") == 1)
		{
			write_socket(msg, "thx bey bey");
			exit(EXIT_SUCCESS);
		}
		else
		{
			if (write_socket(msg, "bang") == -1)
				fprintf(stderr, "write_socket: %s\n", strerror(errno));
		}
		ft_readsock_del(&msg);
	}
	close(sfd);
}

int				main(int argc, const char *argv[])
{
	t_flag			*flag;
	SOCKET			sfd;

	if ((flag = parseur(argc - 1, &argv[1])) == NULL)
		exit(EXIT_FAILURE);
	deflaut_flag(flag);
	if (flag->flag & ARG_D)
		daemonize();
	sfd = reseau(flag);
	print_info(flag);
	loop(sfd);
	return (0);
}

