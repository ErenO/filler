/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:59:47 by eozdek            #+#    #+#             */
/*   Updated: 2016/10/16 16:51:49 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
//
void init_p(t_p *p)
{
	p->i = 0;
	p->j = 0;
	p->n = 0;
	p->m = 0;
	p->piece = 0;
	p->nb = 0;
	p->tab = NULL;
	p->ptr = ft_strnew(0);
	p->line = ft_strnew(0);
}
//
// void	error()
// {
// 	write(1, "ERROR\n", 6);
// 	exit(0);
// }
//
// void	tab_init(t_p *p)
// {
// 	int i;
//
// 	i = 0;
// 	p->tab = (int**)malloc(sizeof(int*) * p->nb);
// 	while (i < p->nb)
// 	{
// 		p->tab[i] = (int*)malloc(sizeof(int) * 2);
// 		i++;
// 	}
// }
//
// void	tab_put(t_p *p)
// {
// 	int i;
// 	int j;
// 	int n;
//
// 	i = 0;
// 	j = 0;
// 	n = 0;
// 	while (p->ptr[i] != '\0')
// 	{
// 		if (p->ptr[i] == '*')
// 		{
// 			p->tab[j][0] = j;
// 			p->tab[j][1] = i;
// 		}
// 		if (p->ptr[i] == '\n')
// 		{
// 			j++;
// 		}
// 		i = p->ptr[i] == '\n' ? 0 : i++;
// 	}
// }
