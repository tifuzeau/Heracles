/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:19:01 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:19:01 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *haystack, const char *needle)
{
	const char	*tmp;
	const char	*init_needle;

	init_needle = needle;
	if (!(*needle))
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			tmp = haystack;
			while (*haystack == *needle && *haystack)
			{
				haystack++;
				needle++;
			}
			if (*needle == '\0')
				return ((char *)tmp);
			haystack = tmp + 1;
			needle = init_needle;
		}
		haystack++;
	}
	return (NULL);
}
