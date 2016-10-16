/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 11:56:12 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/02 19:38:32 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	if ((char)c == '\0')
		return (char *)(&str[i + 1]);
	while (str[i] != '\0')
	{
		if (str[i] == ((char)c))
			return (char *)(&str[i]);
		else
			i--;
	}
	return (NULL);
}
