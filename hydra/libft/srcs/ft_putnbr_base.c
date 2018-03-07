/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:51 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:18:51 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		recur_put(unsigned int nbr, char *base, unsigned int size_base)
{
	if (nbr > size_base - 1)
	{
		recur_put(nbr / size_base, base, size_base);
		recur_put(nbr % size_base, base, size_base);
		return ;
	}
	else
		ft_putchar(base[nbr]);
}

void			ft_putnbr_base(int nbr, char *base)
{
	int		size_base;

	size_base = ft_strlen(base);
	if (size_base <= 1)
		return ;
	if (ft_valide_base(base, size_base) != 1)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		recur_put(-nbr, base, size_base);
	}
	else
		recur_put(nbr, base, size_base);
}
