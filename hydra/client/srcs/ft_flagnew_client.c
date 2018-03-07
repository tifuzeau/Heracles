/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flagnew_client.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 15:00:55 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 15:00:55 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra_client.h"

t_flag			*ft_flagnew_client(void)
{
	t_flag			*out;

	if ((out = malloc(sizeof(t_flag))) == NULL)
		return (NULL);
	out->flag = 0;
	out->port = NULL;
	out->host = NULL;
	return (out);
}

