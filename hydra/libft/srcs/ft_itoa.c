/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:45 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:18:45 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_intout(int n, char *out, int len)
{
	out[len] = ((n % 10) + '0');
	if (n > 9)
		ft_intout(n / 10, out, --len);
}

char		*ft_itoa(int n)
{
	char		*out;
	size_t		len;

	len = ft_sizeint(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if ((out = ft_strnew(len)) == NULL)
		return (NULL);
	if (n < 0)
	{
		out[0] = '-';
		n = -n;
		ft_intout(n, out, len - 1);
	}
	else
		ft_intout(n, out, len - 1);
	return (out);
}
