/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_valide_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:19:03 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:19:03 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int				ft_valide_base(char *base, int size_base)
{
	int		i;
	int		j;
	char	c;
	char	*pt_base;

	i = 0;
	while (i < size_base)
	{
		j = 0;
		c = base[i];
		pt_base = base;
		if (c == '+' || c == '-' || (c < ' ' || c > '~'))
			return (0);
		while (*pt_base)
		{
			if (c == *pt_base)
				j++;
			pt_base++;
		}
		if (j > 1)
			return (0);
		i++;
	}
	return (1);
}
