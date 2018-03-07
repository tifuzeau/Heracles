/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:57 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:18:57 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	char	*tmp;
	size_t	len_out;

	if (s1 == NULL | s2 == NULL)
		return (NULL);
	len_out = ft_strlen(s1) + ft_strlen(s2);
	if ((out = ft_strnew(len_out)) == NULL)
		return (NULL);
	tmp = out;
	while (*s1)
	{
		*tmp = *s1;
		tmp++;
		s1++;
	}
	while (*s2)
	{
		*tmp = *s2;
		tmp++;
		s2++;
	}
	return (out);
}
