/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:58:10 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/03 08:43:48 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			words(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			j++;
		}
	}
	return (j);
}

static char			*wordsplus(char const *s, char c, int *i)
{
	char	*s1;
	int		n;
	int		j;

	n = *i;
	j = 0;
	if (!s || !c)
		return (NULL);
	while (s[n] && s[n] != c)
		n++;
	if ((s1 = (char *)malloc(sizeof(char ) * (n - *i))) == NULL)
		return (NULL);
	if (s1)
	{
		while (n > *i)
		{
			s1[j] = s[*i];
			j++;
			*i += 1;
		}
		s1[j] = '\0';
		return (s1);
	}
	return (0);
}

char				**ft_strsplit(char const *s, char c)
{
	int		n;
	int		*i;
	int		j;
	char	**ret;

	n = 0;
	i = &n;
	j = 0;
	ret = NULL;
	if (s)
		ret = (char **)malloc(sizeof(char *) * ((words(s, c) + 1)));
	if (ret == NULL)
		return (NULL);
	while (j < words(s, c))
	{
		while (s[*i] == c)
			*i += 1;
		if (s[*i] != c && s[*i])
			ret[j++] = wordsplus(s, c, i);
	}
	ret[j] = 0;
	return (ret);
}
