/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erenozdek <erenozdek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 13:27:16 by eozdek            #+#    #+#             */
/*   Updated: 2016/10/25 17:04:44 by erenozdek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"



/*
	Check si la piece rentre, return 1 si c'est bon, 0 dans le cas contraire
*/
// sta

int		ft_check_piece(t_p *p, int line, int column)
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
		map_place = line + ((p->col_map + 1) * (column + i));
		piece_place = ((p->col_piece + 1) * i);
		// print_map(p->line, map_place);
		// print_piece(p->ptr, piece_place);
		while (j < p->col_piece && p->line[map_place] != 0)
		{
			if (p->line[map_place] == '\n' && p->ptr[piece_place] != '*')
				break ;
			if (p->line[map_place] == p->ch && p->ptr[piece_place] == '*')
				count++;
			if ((j + p->col_piece) > p->col_map && p->ptr[piece_place] == '*')
				return (0);
			if (p->line[map_place] == '\0')
				return (2);
			if (p->line[map_place] != p->ch &&  p->line[map_place] != (p->ch + 32) && p->line[map_place] != '.' && p->line[map_place] != '\n')
				return (0);
			map_place++;
			piece_place++;
			j++;
		}
		i++;
	}
	return (count == 1) ? 1 : 0;
}

int	ft_find_out_place(t_p *p)
{
	int x;
	int y;
	int ret;
	int valid;

	y = 0;
	valid = 0;
	ret = 0;
	while (y < p->line_map)
	{
		x = 0;
		while (x < p->col_map)
		{
			ret = ft_check_piece(p, x, y);
			if (ret == 1)
			{
				dprintf(2, "\nX : %d, Y : %d\n", x, y);
				// ft_putnbr(y);
				// ft_putchar(' ');
				// ft_putnbr(x);
				// ft_putchar('\n');
				printf("%d %d\n", x, y);
				p->ptr = NULL;
				p->ptr = ft_strnew(0);
				p->line = NULL;
				p->line = ft_strnew(0);
				return (1);
			}
			else if (ret == 2)
				return (0);
			x++;
		}
		y++;
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
