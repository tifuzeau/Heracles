/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:54 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:18:54 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, char c)
{
	char *out;

	out = (char *)str;
	while (*out)
	{
		if (*out == c)
			return (out);
		out++;
	}
	if (c == 0)
		return (out);
	return (NULL);
}
