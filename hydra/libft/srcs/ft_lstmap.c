/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:46 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:18:46 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*begin_lst;
	t_list		*new_lst;

	begin_lst = (*f)(lst);
	new_lst = begin_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst->next = (*f)(lst);
		lst = lst->next;
		new_lst = new_lst->next;
	}
	new_lst->next = NULL;
	return (begin_lst);
}
