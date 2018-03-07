/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_usage.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 13:16:20 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 13:41:28 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra.h"

void			ft_usage(const char *str)
{
	fprintf(stderr, "Usage: %s\n-d for deamon run\n--port %%d port\n"
			, str);
	exit(EXIT_FAILURE);
}
