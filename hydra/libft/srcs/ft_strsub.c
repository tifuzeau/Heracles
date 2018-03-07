/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:19:02 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:19:02 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char *out;
	char *tmp;

	if (str == NULL)
		return (NULL);
	if ((out = ft_strnew(len)) == NULL)
		return (NULL);
	tmp = out;
	str = &str[start];
	while (len--)
	{
		*tmp = *str;
		tmp++;
		str++;
	}
	*tmp = '\0';
	return (out);
}
