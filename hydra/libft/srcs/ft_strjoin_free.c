/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin_free.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:57 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:18:57 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char **as, const char *s2)
{
	char	*out;
	size_t	len_out;

	len_out = ft_strlen(*as) + ft_strlen(s2) + 1;
	if ((out = ft_strnew(len_out)) == NULL)
		return (NULL);
	if (len_out == 1)
		out[0] = '\0';
	if (*as != NULL)
	{
		ft_strcpy(out, *as);
		free(*as);
		*as = NULL;
	}
	if (s2 != NULL)
		ft_strcat(out, s2);
	return (out);
}
