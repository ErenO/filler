/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 11:55:49 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/02 20:36:12 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	h;

	i = 0;
	j = 0;
	h = 0;
	if (s2[i] == '\0')
		return (char *)(&s1[i]);
	while (s1[i] != '\0')
	{
		h = i;
		while ((s1[i] == s2[j]) && (i < n) && (s2[j] != '\0'))
		{
			i++;
			j++;
			if (s2[j] == '\0')
				return (char *)&(s1[i - j]);
		}
		j = 0;
		i = h;
		i++;
	}
	return (NULL);
}
