/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:06:36 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/02 19:07:13 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;
	t_list *tmp;
	t_list *tmp1;

	if (!lst || !f)
		return (NULL);
	tmp1 = f(lst);
	ret = ft_lstnew(tmp1->content, tmp1->content_size);
	if (ret)
	{
		tmp = ret;
		lst = lst->next;
		while (lst != 0)
		{
			tmp1 = f(lst);
			if (!(tmp->next = ft_lstnew(tmp1->content, tmp1->content_size)))
				return (NULL);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (ret);
}
