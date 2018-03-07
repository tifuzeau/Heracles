/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   deflaut_flag_client.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 15:00:54 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 15:17:52 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra_client.h"

void		deflaut_flag_client(t_flag *flag)
{
	if (flag->port == NULL)
		if ((flag->port = ft_strdup(DEFLAUT_PORT)) == NULL)
			exit(EXIT_FAILURE);
	if (flag->host == NULL)
		if ((flag->host = ft_strdup(DEFLAUT_HOST)) == NULL)
			exit(EXIT_FAILURE);
}
