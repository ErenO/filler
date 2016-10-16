/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:18:45 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/02 18:53:53 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	if (s == NULL && f == NULL)
		return (NULL);
	i = ft_strlen(s);
	if ((ret = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ret[i] = f(s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
