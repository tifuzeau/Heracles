/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parseur_client.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 15:00:56 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 15:16:39 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra_client.h"

static int		get_flag(int *i, const char *argv[], t_flag *flag)
{
	if (argv[*i] == NULL)
		return (END);
	if (ft_strequ(argv[*i], "--host") == SUCCESS)
	{
		dprintf(1, "parseur bug");
		if (argv[*i + 1] == NULL)
			ft_usage_client(argv[-1]);
		if ((flag->host = ft_strdup(argv[*i + 1])) == NULL)
			return (FAIL);
		*i += 2;
		return (SUCCESS);
	}
	if (ft_strequ(argv[*i], "--port") == SUCCESS)
	{
		if (argv[*i + 1] == NULL)
			ft_usage_client(argv[-1]);
		if (ft_str_isdigit(argv[*i + 1]) != SUCCESS)
			ft_usage_client(argv[-1]);
		if ((flag->port = ft_strdup(argv[*i + 1])) == NULL)
			return (FAIL);
		*i += 2;
		return (SUCCESS);
	}
	return (FAIL);
}

t_flag			*parseur_client(int argc, const char **argv)
{
	int					i;
	int					ret;
	t_flag				*out;

	i = 0;
	ret = END;
	if ((out = ft_flagnew_client()) == NULL)
	{
		fprintf(stderr, "Fail malloc pleas retry\n");
		exit(EXIT_FAILURE);
	}
	while (i < argc && (ret = get_flag(&i, argv, out) == SUCCESS))
		i++;
	if (ret == FAIL)
	{
		ft_flagdel_client(&out);
		return (NULL);
	}
	return (out);
}
