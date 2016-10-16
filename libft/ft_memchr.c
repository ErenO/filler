/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:09:57 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/02 20:40:37 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	int				i;

	i = 0;
	s1 = (unsigned char *)s;
	while (n--)
	{
		if (s1[i] == (unsigned char)c)
			return (s1 + i);
		i++;
	}
	return (NULL);
}
