/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_isin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:53 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:18:53 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_str_isin(const char *str, char c)
{
	if (str == NULL)
		return (-1);
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}
