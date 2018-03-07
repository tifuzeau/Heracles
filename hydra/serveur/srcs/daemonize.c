/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   run_deamon.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 17:37:14 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 16:31:16 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra.h"

static void			trap_sig(void)
{
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
}

static void			deflaut_IO(void)
{
	int			fd;

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	fd = open("/dev/null", O_RDWR);
	dup(fd);
	dup(fd);
}


void			daemonize(void)
{
	pid_t		pid;

	if (getppid() == 1)
		return ;
	if ((pid = fork()) == -1)
	{
		fprintf(stderr, "Fork: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	if (pid > 0)
	{
		printf("Deamon success created\n pid: %d\n", pid);
		exit(EXIT_SUCCESS);
	}
	if (pid == 0)
	{
		setsid();
		trap_sig();
		deflaut_IO();
		umask(DEFAULT_RIGHT);
		chdir(RUNNING_DIR);
	}
}
