/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flagdel.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 13:33:32 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 14:00:30 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra.h"

void			ft_flagdel(t_flag **as)
{
	t_flag		*tmp;

	tmp = *as;
	if (tmp != NULL)
	{
		if (tmp->port != NULL)
			ft_strdel(&(tmp->port));
		free(tmp);
		*as = NULL;
	}
}
