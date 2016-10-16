/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:34:41 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/02 19:41:05 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;
	int n;

	i = 0;
	j = 0;
	n = 0;
	while (s2[n] != '\0')
		n++;
	if (n == 0)
		return ((char *)s1);
	while (s1[i])
	{
		while (s1[i + j] == s2[j])
		{
			if (j == n - 1)
				return ((char *)s1 + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
