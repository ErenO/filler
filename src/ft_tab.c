/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 13:27:16 by eozdek            #+#    #+#             */
/*   Updated: 2016/10/24 09:00:30 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


// static void print_map(char *map, int curse)
// {
// 	int i;
//
// 	i = 0;
// 	dprintf(2, "\n");
// 	while (map[i] != 0)
// 	{
// 		if (i == curse)
// 		{
// 			dprintf(2, "|");
// 		}
// 		dprintf(2, "%c", map[i]);
// 		i++;
// 	}
// 	dprintf(2, "\n");
// }

// static void print_piece(char *piece, int curse)
// {
// 	int i;
//
// 	i = 0;
// 	while (map[i] != 0)
// 	{
// 		if (i == curse)
// 		{
// 			dprintf(2, "|");
// 		}
// 		dprintf(2, "%c", map[i]);
// 		i++;
// 	}
// }


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
	int m;

	m = 0;
	i = 0;
	count = 0;
	map_place = 0;
	piece_place = 0;
	// dprintf(2, "A");
	// dprintf(2, "\nX : %d, Y : %d, long : %d, \npiece line: %d, col_piece %d", column, line, p->col_map, line, p->col_piece);
	// dprintf(2, "p->ptr\n%s\n", p->ptr);
	while (i < p->line_piece && (i + p->line_piece) < p->line_map)
	{
		j = 0;
		map_place = line + ((p->col_map + 1) * (column + i));
		piece_place = ((p->col_piece + 1) * i);
		// print_map(p->line, map_place);
		// print_map(p->ptr, piece_place);
		while (j < p->col_piece && p->line[map_place] != 0)
		{
			// dprintf(2, "%c", p->line[map_place]);
			// dprintf(2, "mapplace %d, p->line_map %d, line %d, i %d, column %d\n", map_place, p->line_map, line, i, column);
			if (p->line[map_place] == '\n' && p->ptr[piece_place] != '*')
				break ;
			if (p->line[map_place] == p->ch && p->ptr[piece_place] == '*')
			{
				// dprintf(2, "\np->line[map_place]: |%d|, map_place: |%d|\n", p->line[map_place], map_place);
				count++;
			}
			if ((j + p->col_piece) > p->col_map && p->ptr[piece_place] == '*')
			{
				dprintf(2, "0\n");
				return (0);
			}
			if (p->line[map_place] == '\0')
			{
				dprintf(2, "1\n");
				return (2);
			}
			if (p->line[map_place] != p->ch &&  p->line[map_place] != (p->ch + 32) && p->line[map_place] != '.' && p->line[map_place] != '\n')
			{
				// dprintf(2, "\np->line[map_place]: |%d|, map_place: |%d|, p->ch %c\n", p->line[map_place], map_place, p->ch);
				dprintf(2, "map\n%s", p->line);
				// print_map(p->line, map_place);
				// print_map(p->ptr, piece_place);
				dprintf(2, "2\n");
				return (0);
			}
			map_place++;
			piece_place++;
			j++;
			m++;
		}
		// dprintf(2, "EOF\n");
		// dprintf(2, "NONNNN");
		i++;
	}
	// dprintf(2, "B\n");
	// dprintf(2, "\nm:%d\n", m);
	if (count == 1)
	{
		dprintf(2, "3\n");
		// dprintf(2, "\nOK\n");
		return (1);
	}
	else
	{
		dprintf(2, "4\n");
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
	int ret;
	int valid;

	i = 0;
	valid = 0;
	ret = 0;
	while (i < p->line_map)
	{
		j = 0;
		while (j < p->col_map)
		{
			ret = ft_check_piece(p, j, i);
			if (ret == 1)
			{
				dprintf(2, "\nX : %d, Y : %d\n", j, i);
				ft_putnbr(i);
				ft_putchar(' ');
				ft_putnbr(j);
				ft_putchar('\n');
				p->ptr = NULL;
				p->ptr = ft_strnew(0);
				p->line = NULL;
				p->line = ft_strnew(0);
				return (1);
			}
			else if (ret == 2)
			{
				return (2);
			}
			j++;
		}
		i++;
	}
	return (0);
}
