/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdel_2d.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:55 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:18:55 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_strdel_2d(char ***as)
{
	char	**str;

	str = *as;
	while (*str != NULL)
	{
		free(*str);
		*str = NULL;
		str++;
	}
	free(*as);
	*as = NULL;
}
