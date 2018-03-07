/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_readsock_del.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 14:41:43 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 14:42:36 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra.h"

void			ft_readsock_del(t_readsock **as)
{
	t_readsock		*tmp;

	tmp = *as;
	if (*as != NULL)
	{
		free(tmp);
		*as = NULL;
	}
}
