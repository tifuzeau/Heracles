/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:59 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:18:59 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*pt_dst;

	pt_dst = dst;
	while (*src && n)
	{
		*pt_dst = *src;
		pt_dst++;
		src++;
		n--;
	}
	while (n != 0)
	{
		*pt_dst = '\0';
		pt_dst++;
		n--;
	}
	return (dst);
}
