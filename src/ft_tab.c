/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 13:27:16 by eozdek            #+#    #+#             */
/*   Updated: 2016/10/26 18:17:54 by eozdek           ###   ########.fr       */
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
			dprintf(2, "|");
		dprintf(2, "%c", map[i]);
		i++;
	}
	dprintf(2, "\n");
}

/*
	Check si la piece rentre, return 1 si c'est bon, 0 dans le cas contraire
*/

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
	while (i < p->line_piece && (i + p->line_piece) < p->line_map)
	{
		j = 0;
		map_place = y + ((p->col_map + 1) * (x + i));
		piece_place = ((p->col_piece + 1) * i);
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
			if (p->line[map_place] != p->ch &&  p->line[map_place] != (p->ch + 32)
				&& p->line[map_place] != '.' && p->line[map_place] != '\n')
				return (0);
			map_place++;
			piece_place++;
			j++;
		}
		i++;
	}
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

	y = 0;
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
				ft_put_solve(x, y);
				p->ptr = NULL;
				p->line = NULL;
				p->ptr = ft_strnew(0);
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
