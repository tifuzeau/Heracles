/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:19:00 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:19:00 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		match(const char *haystack, const char *needle, size_t n)
{
	while (n && (*needle && *haystack) && (*haystack == *needle))
	{
		haystack++;
		needle++;
		n--;
	}
	if (*needle == '\0')
		return (1);
	else if (n == 0)
		return (-1);
	else
		return (0);
}

char			*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int				i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && n)
	{
		if (*haystack == *needle)
		{
			i = match(haystack, needle, n);
			if (i == 1)
				return ((char *)haystack);
			if (i == -1)
				return (NULL);
		}
		haystack++;
		n--;
	}
	return (NULL);
}
