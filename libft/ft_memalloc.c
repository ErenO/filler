/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:09:29 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/02 18:50:46 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ret;

	ret = malloc(sizeof(size_t) * (size));
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
