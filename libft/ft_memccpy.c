/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:20:59 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/02 20:43:11 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	b;

	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	b = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == b)
		{
			return (s1 + (i + 1));
		}
		i++;
	}
	return (NULL);
}
