/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:09:14 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/02 20:31:32 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		n;

	i = 0;
	n = ft_strlen(s1);
	if ((s2 = (char *)malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	if (s1)
	{
		while (n--)
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
	return (NULL);
}
