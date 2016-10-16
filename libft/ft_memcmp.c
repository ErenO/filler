/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:10:57 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/02 20:48:18 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*ptr;

	str = (unsigned char *)s1;
	ptr = (unsigned char *)s2;
	if (s1 == NULL || s2 == NULL || n == 0)
		return (0);
	i = 0;
	while (str[i] == ptr[i] && --n)
		i++;
	return (str[i] - ptr[i]);
}
