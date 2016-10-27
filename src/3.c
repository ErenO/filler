/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 06:00:04 by eozdek            #+#    #+#             */
/*   Updated: 2016/10/16 16:51:20 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
//
// int		tab_match(int i, int j, t_p *p, int *tab)
// {
// 	int n;
// 	int m;
//
// 	n = 0;
// 	while (n < p->nb)
// 	{
// 		m = p->nb - 1;
// 		while (m > 0)
// 		{
// 			if (m = n)
// 				m--;
// 			if (p->line[tab[m][0] + i] == p->ch)
// 			{
//
// 			}
// 			m--;
// 		}
// 		n++;
// 	}
// }
//
// void	find_place(t_p *p)
// {
// 	int i;
// 	int j;
// 	int tab;
//
// 	i = 0;
// 	j = 0;
// 	tab = (int*)malloc(sizeof(int) * 2);
// 	while (i < p->i)
// 	{
// 		if (p->line[i + p->j + 1] == p->ch && p->line[i] != p->ch)
// 		// s'il y a le caractere la prochaine ligne ou juste apres on regarde si c'est possible de le poser
// 		{
// 			if (tab_match(i, j, p, tab) == 1)
// 			{
// 				ft_putnbr(tab[0]);
// 				ft_putchar(' ');
// 				ft_putnbr(tab[1]);
// 				ft_putchar('\n');
// 				break;
// 			}
// 		}
// 		if (p->line[i + 1] == p->ch && p->line[i] != p->ch)
// 		if (p->line[i] == '\n')
// 			j++;
// 		i++;
// 	}
// }
