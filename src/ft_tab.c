/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 13:27:16 by eozdek            #+#    #+#             */
/*   Updated: 2016/10/23 09:49:06 by eozdek           ###   ########.fr       */
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
	int m;

	m = 0;
	i = 0;
	count = 0;
	map_place = 0;
	piece_place = 0;
	// dprintf(2, "\nhello\n");
	dprintf(2, "\nX : %d, Y : %d\n", line, column);
	// dprintf(2, "p->ptr\n%s\n", p->ptr);
	while (i < p->line_piece && (i + p->line_piece) < p->line_map)
	{
		j = 0;
		map_place = line + ((p->line_map) * (column + i));
		piece_place = line + ((p->line_piece) * i);
		while (j < p->col_piece && p->line[map_place] != 0)
		{
			dprintf(2, "%c", p->line[map_place]);
			dprintf(2, "mapplace %d, p->line_map %d, line %d, i %d, column %d\n", map_place, p->line_map, line, i, column);
			if (p->line[map_place] == '\n' && p->ptr[piece_place] != '*')
				break ;
			if (p->line[map_place] == p->ch)
			{
				// dprintf(2, "\np->line[map_place]: |%d|, map_place: |%d|\n", p->line[map_place], map_place);
				count++;
			}

			if ((j + p->col_piece) > p->col_map && p->ptr[piece_place] == '*')
			{
				// dprintf(2, "\n2\n");
				return (0);
			}
			if (p->line[map_place] != p->ch &&  p->line[map_place] != (p->ch + 32) && p->line[map_place] != '.' && p->line[map_place] != '\n')
			{
				// dprintf(2, "\np->line[map_place]: |%d|, map_place: |%d|, p->ch %c\n", p->line[map_place], map_place, p->ch);
				return (0);
			}
			map_place++;
			piece_place++;
			j++;
			m++;
		}
		dprintf(2, "EOF\n");
		// dprintf(2, "NONNNN");
		i++;
	}
	// dprintf(2, "\nm:%d\n", m);
	if (count == 1)
	{
		dprintf(2, "\nhello\n");
		return (1);
	}
	else
	{
		// dprintf(2, "\nOUIIIII%d\n", count);
		// dprintf(2, "\nX : %d, Y : %d\n", line, column);
		return (0);
	}
	// return (count == 1) ? 1 : 0;
}

int	ft_find_out_place(t_p *p)
{
	int i;
	int j;
	int valid;

	i = 0;
	valid = 0;
	// dprintf(2, "\nhello\n");
	while (i < p->line_map)
	{
		j = 0;
		while (j < p->col_map)
		{
			if (ft_check_piece(p, j, i))
			{
				dprintf(2, "\nX : %d, Y : %d\n", j, i);
				// ft_putnbr(j);
				// ft_putchar(' ');
				// ft_putnbr(i);
				// ft_putchar('\n');
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
