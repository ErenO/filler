/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:06:10 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/02 18:06:17 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_integer_table(int *tab, int size)
{
	int j;
	int i;
	int c;

	i = 0;
	j = 0;
	c = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (tab[i] < tab[j])
			{
				c = tab[j];
				tab[j] = tab[i];
				tab[i] = c;
			}
			j++;
		}
		i++;
		j = 0;
	}
}
