/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:19:02 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:19:02 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	trimlen(char const *s)
{
	size_t		len;

	len = 0;
	while (ft_isalspace(*s))
		s++;
	while (*s++)
		len++;
	s -= 2;
	while (len && ft_isalspace(*s))
	{
		s--;
		len--;
	}
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char		*out;
	char		*pt_out;
	size_t		len;

	if (s == NULL)
		return (NULL);
	len = trimlen(s);
	if ((out = ft_strnew(len)) == NULL)
		return (NULL);
	pt_out = out;
	while (ft_isalspace(*s))
		s++;
	while (len)
	{
		*pt_out = *s;
		pt_out++;
		s++;
		len--;
	}
	*pt_out = '\0';
	return (out);
}
