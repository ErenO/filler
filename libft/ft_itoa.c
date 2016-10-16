/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:20:00 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/03 08:33:01 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_isnegative(int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

static int		ft_lennb(int nb)
{
	int i;

	i = 2;
	while (nb /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	ft_isnegative(&n, &neg);
	len = ft_lennb(n);
	len += neg;
	if ((s = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	s[--len] = '\0';
	while (len--)
	{
		s[len] = n % 10 + '0';
		n /= 10;
	}
	if (neg)
		s[0] = '-';
	return (s);
}
