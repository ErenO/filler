/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 11:56:40 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/02 19:27:04 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		n;
	char	*s1;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	n = 0;
	while (ft_isspace(s[i]))
		i++;
	s1 = (char *)malloc(sizeof(char) * (j + 1));
	if (s1 == NULL)
		return (NULL);
	if (s1)
	{
		while (ft_isspace(s[j]))
			j--;
		while (i <= j)
			s1[n++] = s[i++];
		s1[n] = '\0';
		return (s1);
	}
	return (NULL);
}
