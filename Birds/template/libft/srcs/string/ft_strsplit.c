/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:19:01 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:19:01 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	dim_split(char const *s, char c)
{
	size_t	y;

	y = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s && *s != c)
			s++;
		y++;
	}
	return (y);
}

static size_t	ft_dim_x(char const *s, char c)
{
	size_t x;

	x = 1;
	while (*s != c && *s)
	{
		s++;
		x++;
	}
	return (x);
}

static char		*split(char **str, char c)
{
	int			x;
	char		*out;
	char		*pt_str;
	char		*pt_out;

	pt_str = *str;
	x = ft_dim_x(*str, c) + 1;
	if ((out = ft_strnew(x)) == NULL)
		return (NULL);
	pt_out = out;
	while (*pt_str && *pt_str != c)
	{
		*pt_out = *pt_str;
		pt_out++;
		pt_str++;
	}
	*pt_out = '\0';
	*str = pt_str;
	return (out);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		y;
	char		**out;
	char		**pt_out;

	if (s == NULL)
		return (NULL);
	y = dim_split(s, c);
	if ((out = ft_strnew_2d(y)) == NULL)
		return (NULL);
	pt_out = out;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		*pt_out = split((char **)&s, c);
		pt_out++;
	}
	return (out);
}
