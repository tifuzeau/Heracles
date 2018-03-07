/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_isalpha.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:53 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:18:53 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_str_isalpha(const char *str)
{
	while ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}
