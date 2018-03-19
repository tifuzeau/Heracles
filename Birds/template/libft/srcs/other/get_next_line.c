/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 18:07:02 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/13 16:14:58 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
static int			ft_strend_line(char *str)
{
	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

static char			*read_and_write(const int fd, char *buf,
		t_read *last, int bol)
{
	char	*tmp;

	if (bol == 0)
	{
		tmp = last->str;
		ft_strcpy(buf, last->str);
		free(last->str);
		last->str = NULL;
		last->fd = -1;
	}
	else
	{
		last->fd = fd;
		tmp = ft_strchr(buf, '\n');
		if ((last->str = ft_strdup(tmp + 1)) == NULL)
			return (NULL);
		if ((tmp = ft_strndup(buf, (tmp - buf))) == NULL)
			return (NULL);
		free(buf);
	}
	return (tmp);
}

static char			*last(int const fd, char *buf, int bol)
{
	size_t			i;
	char			*tmp;
	static t_read	*last[MAX_FD_CALL + 1] = { NULL};

	tmp = buf;
	i = 0;
	if (bol == 0)
	{
		while (last[i] && last[i]->fd != fd && i != MAX_FD_CALL)
			i++;
		if (last[i] && i != MAX_FD_CALL)
			read_and_write(fd, buf, last[i], 0);
	}
	else if (ft_strend_line(buf) == 1)
	{
		while (last[i] && last[i]->fd != -1 && i != MAX_FD_CALL)
			i++;
		if (last[i] == NULL)
			if ((last[i] = (t_read *)malloc(sizeof(t_read))) == NULL)
				return (NULL);
		tmp = read_and_write(fd, buf, last[i], 1);
	}
	if (i == MAX_FD_CALL)
		return (NULL);
	return (tmp);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];

	ret = 1;
	ft_strnclr(buf, BUFF_SIZE + 1);
	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	last(fd, buf, 0);
	while ((*line = ft_strjoinfree(line, (char **)&buf, 1)) != NULL)
	{
		if (ft_strend_line(buf) == 1 || ret == 0)
			break ;
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			break ;
		buf[ret] = '\0';
	}
	if ((*line = last(fd, *line, 1)) == NULL || ret == -1)
	{
		if (*line != NULL)
			ft_strdel(line);
		return (-1);
	}
	return ((ret == 0 && (*line == NULL || **line == '\0')) ? 0 : 1);
}
