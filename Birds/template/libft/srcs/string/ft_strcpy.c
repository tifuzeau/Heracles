/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:54 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:18:54 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *dst, const char *src)
{
	char	*pt_dst;

	pt_dst = dst;
	while (*src)
	{
		*pt_dst = *src;
		pt_dst++;
		src++;
	}
	*pt_dst = '\0';
	return (dst);
}
