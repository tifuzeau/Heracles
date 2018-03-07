/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:57 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:18:57 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*pt_dst;
	char			*pt_src;
	size_t			n;
	size_t			dlen;

	n = size;
	pt_dst = dst;
	pt_src = (char *)src;
	while (n-- && *pt_dst)
		pt_dst++;
	dlen = pt_dst - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(src));
	while (*pt_src)
	{
		if (n != 1)
		{
			*pt_dst++ = *pt_src;
			n--;
		}
		pt_src++;
	}
	*pt_dst = '\0';
	return (dlen + (pt_src - src));
}
