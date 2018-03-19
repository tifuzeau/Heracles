/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnclr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:59 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:18:59 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_strnclr(char *str, size_t n)
{
	while (n)
	{
		*str = '\0';
		str++;
		n--;
	}
}
