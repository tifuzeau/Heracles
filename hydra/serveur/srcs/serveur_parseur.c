/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parseur.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 11:42:46 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 14:56:39 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hydra.h"

int				get_flag(int *i, const char *argv[], t_flag *flag)
{
	if (argv[*i] == NULL)
		return (END);
	if (ft_strequ(argv[*i], "-d") == SUCCESS)
	{
		flag->flag = flag->flag | ARG_D;
		*i += 1;
		return (SUCCESS);
	}
	if (ft_strequ(argv[*i], "--port") == SUCCESS)
	{
		if (argv[*i + 1] == NULL)
			ft_usage(argv[-1]);
		if (ft_str_isdigit(argv[*i + 1]) != SUCCESS)
			ft_usage(argv[-1]);
		if ((flag->port = ft_strdup(argv[*i + 1])) == NULL)
			return (FAIL);
		*i += 2;
		return (SUCCESS);
	}
	return (FAIL);
}

t_flag			*parseur(int argc, const char **argv)
{
	int					i;
	int					ret;
	t_flag				*out;

	i = 0;
	ret = END;
	if ((out = ft_flagnew()) == NULL)
	{
		fprintf(stderr, "Fail malloc pleas retry\n");
		exit(EXIT_FAILURE);
	}
	while (i < argc && (ret = get_flag(&i, argv, out) == SUCCESS))
		i++;
	if (ret == FAIL)
	{
		ft_flagdel(&out);
		return (NULL);
	}
	return (out);
}
