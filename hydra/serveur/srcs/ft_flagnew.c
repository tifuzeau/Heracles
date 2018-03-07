/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flagnew.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 13:30:00 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 15:02:15 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra.h"

t_flag			*ft_flagnew(void)
{
	t_flag			*out;

	if ((out = malloc(sizeof(t_flag))) == NULL)
		return (NULL);
	out->flag = 0;
	out->port = NULL;
	return (out);
}

