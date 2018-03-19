/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:19:00 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:19:00 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*out;
	char			*pt_out;

	if ((out = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	pt_out = out;
	while (size)
	{
		*pt_out = '\0';
		pt_out++;
		size--;
	}
	*pt_out = '\0';
	return (out);
}
