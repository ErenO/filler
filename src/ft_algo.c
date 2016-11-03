/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 10:52:19 by eozdek            #+#    #+#             */
/*   Updated: 2016/11/03 22:30:07 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void print_map(char *map, int curse)
{
	int i;

	i = 0;
	while (map[i] != 0)
	{
		if (i == curse)
			dprintf(2, "|");
		dprintf(2, "%c", map[i]);
		i++;
	}
	dprintf(2, "\n");
}

void print_piece(char *piece, int curse)
{
	int i;

	i = 0;
	while (piece[i] != 0)
	{
		if (i == curse)
			dprintf(2, "|");
		dprintf(2, "%c", piece[i]);
		i++;
	}
}

/*
	Check si la piece rentre, return 1 si c'est bon, 0 dans le cas contraire
*/

static int 	ft_curse_ok(t_p *p, int *count, int *map_place, int *piece_place)
{
	int j;

	j = 0;
	while (j < (p->col_piece) && p->line[(*map_place)] != 0)
	{
		// if (p->ptr[(*piece_place)] == '\n')
		// 	break ;
		// if (p->ptr[(*piece_place)] == '\0')
		// 	return (0);
			// dprintf(2, "%c", p->line[(*map_place)]);
		if (p->line[(*map_place)] == '\n' && p->ptr[(*piece_place)] == '.')
			break ;
		(*count) += (p->line[(*map_place)] == p->ch && p->ptr[(*piece_place)] == '*') ? 1 : 0;
		if (p->line[(*map_place)] == '\0')
		{
			// dprintf(2, "\n");
			return (2);
		}
		if ((p->line[(*map_place)] != p->ch &&  p->line[(*map_place)] != (p->ch + 32)
			&& p->line[(*map_place)] != '.' && p->line[(*map_place)] != '\n')
			|| ((j + p->col_piece) > p->col_map && p->ptr[(*piece_place)] == '*')
			|| (p->line[(*map_place)] == '\n' && p->ptr[(*piece_place)] == '*'))
			{
				// dprintf(2, "\n");
				return (0);
			}
		(*map_place) += 1;
		(*piece_place) += 1;
		j++;
	}
	// dprintf(2, "%c\n", p->line[(*map_place)]);
	return (1);
}

int		ft_check_piece(t_p *p, int x, int y)
{
	int i;
	int j;
	int count;
	int map_place;
	int piece_place;

	count = 0;
	map_place = (p->col_map + 1) * x;
	piece_place = 0;
	i = (p->line_map + p->line_piece) - (x + p->line_piece);
	if (i > 0 && ft_check_piece_exceed_bottom_map(p->ptr, i) == 0)
		return (0);
	j = (p->col_map + p->col_piece) - (y + p->col_piece);
	if (j > 0 && ft_check_piece_exceed_right_map(p->ptr, j, p->col_piece + 1) == 0)
		return (0);
	i = 0;
	// dprintf(2, "col_piece %d piece\n%s\n", p->col_piece, p->ptr);
	while (i < p->line_piece && (i + p->line_piece) < p->line_map)
	{
		j = 0;
		map_place = y + ((p->col_map + 1) * (x + i));
		piece_place = ((p->col_piece + 1) * i);
		// dprintf(2, "map_place %d, piece_place %d\n", map_place, piece_place);
		if (ft_curse_ok(p, &count, &map_place, &piece_place) == 0)
		{
			// dprintf(2, "count %d, x %d, y %d\n", count, x, y);
			return (0);
		}
		i++;
	}
	// dprintf(2, "count %d, x %d, y %d\n", count, x, y);
	return (count == 1) ? 1 : 0;
}

void ft_put_solve(t_p *p, int x, int y)
{
	dprintf(2, "\nX : %d, Y : %d\n", x, y);
	p->turn++;
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
	p->ptr = NULL;
	p->line = NULL;
	p->ptr = ft_strnew(0);
	p->line = ft_strnew(0);
}

int	ft_find_out_place(t_p *p)
{

	//map01 O
	// if (p->piece == 0)
	// 	return (ft_algo_bottom(p));
	// else
	// 	return (ft_algo_right(p));
	//map01 X
	// if (p->turn < 5)
	// 	return (ft_algo_top_left(p));
	if (p->piece == 0)
	{
			return (ft_algo_top_right(p));
	}
	else
		return (ft_algo_left(p));

	ft_putstr("0 0\n");
	return (0);
}
