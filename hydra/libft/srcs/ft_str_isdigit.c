/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_isdigit.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:53 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 13:11:09 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_str_isdigit(const char *str)
{
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str == '\0')
		return (SUCCESS);
	return (FAIL);
}
