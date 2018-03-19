/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:47 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:18:47 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*out;
	unsigned char	*tmp;

	if ((out = malloc(size)) == NULL)
		return (NULL);
	tmp = (unsigned char *)out;
	while (size != 0)
	{
		*tmp = 0;
		tmp++;
		size--;
	}
	return (out);
}
