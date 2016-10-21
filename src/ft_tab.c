/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 13:27:16 by eozdek            #+#    #+#             */
/*   Updated: 2016/10/21 16:25:20 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

void	tab_put(t_p *p)
{
	int i;
	int j;
	int n;

	i = 0;
	j = 0;
	n = 0;
	while (p->ptr[i] != '\0')
	{
		if (p->ptr[i] == '*')
		{
			p->tab[j][0] = j;
			p->tab[j][1] = i;
		}
		if (p->ptr[i] == '\n')
		{
			j++;
		}
		i = p->ptr[i] == '\n' ? 0 : i++;
	}
}

/*
	Check si la piece rentre, return 1 si c'est bon, 0 dans le cas contraire
*/

int	ft_check_piece(t_p *p, int line, int column)
{
	int i;
	int j;
	int count;
	int map_place;
	int piece_place;

	i = 0;
	count = 0;
	map_place = 0;
	piece_place = 0;
	while (i < p->line_piece && (i + p->line_piece) < p->line_map)
	{
		j = 0;
		while (j < p->col_piece)
		{
			map_place = j + column + ((p->line_map + 1) * (line + i));
			piece_place = j + column + ((p->line_piece + 1) * i);
			if (p->line[map_place] == p->ch && p->ptr[piece_place] == '*')
			{
				count++;
			}
			if ((j + p->col_piece) > p->col_map && p->ptr[piece_place] == '*')
			{
				return (0);
			}
			if (p->line[map_place] != p->ch || p->line[map_place] != '.')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (count == 1) ? 1 : 0;
}

int ft_find_out_place(t_p *p)
{
	int i;
	int j;
	int valid;

	i = 0;
	valid = 0;
	while (i < p->line_map)
	{
		j = 0;
		while (j < p->col_map)
		{
			if ((valid = ft_check_piece(p, j, i)))
			{
				ft_putnbr(j);
				ft_putchar(' ');
				ft_putnbr(i);
				ft_putchar('\n');
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

//
// void ft_piece_form_size(t_p *p)
// {
// 	int i;
// 	int j;
// 	int longueur;
// 	int largeur;
// 	int place;
//
// 	i = 0;
// 	j = 0;
// 	longueur = 0;
// 	largeur = 0;
// 	place = 0;
// 	while (i < p->line_piece)
// 	{
// 		j = 0;
// 		while (j < p->col_piece)
// 		{
// 			place = (i * (p->line_piece + 1)) + j;
// 			if (p->ptr[place] == '*')
// 			{
//
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
