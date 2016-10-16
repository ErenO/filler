/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:10:06 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/02 20:37:33 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *s;

	s = (char *)malloc(sizeof(*s) * (len + 1));
	ft_memcpy(s, src, len);
	ft_memcpy(dst, s, len);
	free(s);
	return (dst);
}
