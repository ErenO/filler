/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:27:13 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/02 19:37:37 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	int		h;

	if (!n)
		return (0);
	i = ft_strlen(s1) + 1;
	j = ft_strlen(s2) + 1;
	if (i >= j)
		i = j;
	if (n < i)
		i = n;
	h = ft_memcmp(s1, s2, i);
	return (h);
}
