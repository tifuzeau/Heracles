/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flagdel_client.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 15:00:54 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 15:09:30 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra_client.h"

void			ft_flagdel_client(t_flag **as)
{
	t_flag		*tmp;

	tmp = *as;
	if (tmp != NULL)
	{
		if (tmp->port != NULL)
			ft_strdel(&(tmp->port));
		if (tmp->host != NULL)
			ft_strdel(&(tmp->host));
		free(tmp);
		*as = NULL;
	}
}
