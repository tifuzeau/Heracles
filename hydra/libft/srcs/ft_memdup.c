/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:48 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:18:48 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *data, size_t size)
{
	void			*out;

	if ((out = malloc(size)) == NULL)
		return (NULL);
	ft_memcpy(out, data, size);
	return (out);
}
