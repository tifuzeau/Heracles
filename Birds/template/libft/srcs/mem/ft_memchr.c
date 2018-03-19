/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:47 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:18:47 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*ptr_src;

	ptr_src = (unsigned char *)src;
	while (n--)
	{
		if (*ptr_src == (unsigned char)c)
			return (ptr_src);
		ptr_src++;
	}
	return (NULL);
}
