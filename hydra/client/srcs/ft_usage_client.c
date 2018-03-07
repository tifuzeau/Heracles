/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_usage_client.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 15:00:55 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 15:06:37 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra_client.h"

void			ft_usage_client(const char *str)
{
	fprintf(stderr, "Usage: %s\n--host for hostname run\n--port %%d port\n", str);
	exit(EXIT_FAILURE);
}
