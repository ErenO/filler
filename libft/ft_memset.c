/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:43:40 by eozdek            #+#    #+#             */
/*   Updated: 2015/11/27 15:41:45 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s1;

	s1 = (unsigned char *)b;
	while (len--)
	{
		*s1 = (unsigned char)c;
		if (len)
			s1++;
	}
	return (b);
}
