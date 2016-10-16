/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:34:05 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/02 19:37:06 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	int		n;

	i = ft_strlen(s1) + 1;
	j = ft_strlen(s2) + 1;
	if (i >= j)
		i = j;
	n = ft_memcmp(s1, s2, i);
	return (n);
}
