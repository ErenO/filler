/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 13:27:16 by eozdek            #+#    #+#             */
/*   Updated: 2016/10/26 10:07:10 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void print_map(char *map, int curse)
{
	int i;

	i = 0;
	dprintf(2, "\n");
	while (map[i] != 0)
	{
		if (i == curse)
		{
			dprintf(2, "|");
		}
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
// sta

int		ft_check_piece(t_p *p, int x, int y)
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
	// dprintf(2, "A\n");
	while (i < p->line_piece && (i + p->line_piece) < p->line_map)
	{
		j = 0;
		map_place = y + ((p->col_map + 1) * (x + i));
		piece_place = ((p->col_piece + 1) * i);
		// print_map(p->ptr, piece_place);
		while (j < p->col_piece && p->line[map_place] != 0)
		{
			// dprintf(2, "%d\n", map_place);
			// print_map(p->line, map_place);

			if (p->line[map_place] == '\n' && p->ptr[piece_place] != '*')
				break ;
			if (p->line[map_place] == p->ch && p->ptr[piece_place] == '*')
				count++;
			if ((j + p->col_piece) > p->col_map && p->ptr[piece_place] == '*')
			{
				// dprintf(2, "B\n");
				return (0);
			}
			if (p->line[map_place] == '\0')
			{
				// dprintf(2, "B\n");
				return (2);
			}
			if (p->line[map_place] != p->ch &&  p->line[map_place] != (p->ch + 32)
				&& p->line[map_place] != '.' && p->line[map_place] != '\n')
			{
				// dprintf(2, "B\n");
				return (0);
			}
			map_place++;
			piece_place++;
			j++;
		}
		i++;
	}
	// dprintf(2, "B\n");
	return (count == 1) ? 1 : 0;
}

void ft_put_solve(int x, int y)
{
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
}

int	ft_find_out_place(t_p *p)
{
	int x;
	int y;
	int ret;

	x = 0;
	y = 0;
	ret = 0;
	while (x < p->col_map)
	{
		y = 0;
		while (y < p->line_map)
		{
			ret = ft_check_piece(p, x, y);
			if (ret == 1)
			{
				dprintf(2, "\nX : %d, Y : %d\n", x, y);
				ft_put_solve(x, y);
				p->ptr = NULL;
				p->line = NULL;
				p->ptr = ft_strnew(0);
				p->line = ft_strnew(0);
				return (1);
			}
			else if (ret == 2)
				return (0);
			y++;
		}
		x++;
	}
	return (0);
}
