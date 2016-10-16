/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:51:19 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/02 20:37:20 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *s1;
	char *s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	if (n == 0 || s1 == s2)
		return (dst);
	while (--n)
		*s1++ = *s2++;
	*s1 = *s2;
	return (dst);
}
