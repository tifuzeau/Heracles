/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_info.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 14:55:51 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 15:18:13 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra_client.h"

void		print_info(t_flag *flag)
{
	printf("\tClien Start\n");
	printf("Host: %s\n", flag->host);
	printf("Port: %s\n", flag->port);
}
