/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:59 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:18:59 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char *pt_s1;
	char *pt_s2;

	if (n == 0)
		return (0);
	pt_s1 = (char *)s1;
	pt_s2 = (char *)s2;
	while (*pt_s1 && (*pt_s1 == *pt_s2) && n > 1)
	{
		pt_s1++;
		pt_s2++;
		n--;
	}
	return ((unsigned char)*pt_s1 - (unsigned char)*pt_s2);
}
