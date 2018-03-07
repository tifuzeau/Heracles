/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   deflaut_flag.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 14:46:58 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 14:50:11 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra.h"

void		deflaut_flag(t_flag *flag)
{
	if (flag->port == NULL)
		if ((flag->port = ft_strdup(DEFLAUT_PORT)) == NULL)
			exit(EXIT_FAILURE);
}
