/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erenozdek <erenozdek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 10:52:19 by eozdek            #+#    #+#             */
/*   Updated: 2016/10/28 18:36:44 by erenozdek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void print_map(char *map, int curse)
{
	int i;

	i = 0;
	// dprintf(2, "map_place %d\n", curse);
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

static int		ft_max(int count[4])
{
	int i;
	int number;

	i = 0;
	number = 0;
	while (i < 3)
	{
		if (count[i] < count[i + 1])
			number = i + 1;
		i++;
	}
	return (number);
}

int		ft_find_last_move(t_p *p)
{
	int i;
	int j;
	int count[4];

	i = 0;
	j = 0;
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	count[3] = 0;
	while (p->line[i] != '\0')
	{
		if (p->line[i] == '\n')
			j++;
		if (p->line[i] == p->opp || p->line[i] == (p->opp - 32))
		{
			if (j < (p->line_map / 2) && (i % (p->col_map + 1)) < (p->col_map / 2))
				count[0]++;
			if (j > (p->line_map / 2) && (i % (p->col_map + 1)) > (p->col_map / 2))
				count[1]++;
			if (j > (p->line_map / 2) && (i % (p->col_map + 1)) < (p->col_map / 2))
				count[2]++;
			if (j < (p->line_map / 2) && (i % (p->col_map + 1)) > (p->col_map / 2))
				count[3]++;
		}
		i++;
	}
	return (ft_max(count));
}

/*
	Check si la piece rentre, return 1 si c'est bon, 0 dans le cas contraire
*/

static int 	ft_curse_ok(t_p *p, int *count, int *map_place, int *piece_place)
{
	int j;

	j = 0;
	while (j < p->col_piece && p->line[(*map_place)] != 0)
	{
		if (p->line[(*map_place)] == '\n' && p->ptr[(*piece_place)] == '.')
			break ;
		(*count) += (p->line[(*map_place)] == p->ch && p->ptr[(*piece_place)] == '*') ? 1 : 0;
		if (p->line[(*map_place)] == '\0')
			return (2);
		if ((p->line[(*map_place)] != p->ch &&  p->line[(*map_place)] != (p->ch + 32)
			&& p->line[(*map_place)] != '.' && p->line[(*map_place)] != '\n')
			|| ((j + p->col_piece) > p->col_map && p->ptr[(*piece_place)] == '*')
			|| (p->line[(*map_place)] == '\n' && p->ptr[(*piece_place)] == '*'))
			return (0);
		(*map_place) += 1;
		(*piece_place) += 1;
		j++;
	}
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
	i = 0;
	if (y > (p->col_map - p->col_piece) || x > (p->line_map - p->line_piece))
	{
		i = y - (p->col_map - p->col_piece);
		j = x - (p->line_map - p->line_piece);
		// dprintf(2, " %d, ", )
		if (!ft_check_piece_exceed_map(p->ptr, i, j, p->col_piece + 1, y > (p->col_map - p->col_piece)))
		{
			// dprintf(2, "map\n");
			// print_map(p->line, map_place);
			return (0);
		}
		// dprintf(2, "hello\n", p->);
	}
	i = 0;
	while (i < p->line_piece && (i + p->line_piece) < p->line_map)
	{
		j = 0;
		map_place = y + ((p->col_map + 1) * (x + i));
		piece_place = ((p->col_piece + 1) * i);
		// print_map(p->line, map_place);
		if (ft_curse_ok(p, &count, &map_place, &piece_place) == 0)
			return (0);
		i++;
	}
	return (count == 1) ? 1 : 0;
}
// dprintf(2, "map_place %d count %d\n", map_place, count);
// dprintf(2, "map\n");
// print_map(p->line, map_place);
// dprintf(2, "piece\n");
// print_map(p->ptr, piece_place);

void ft_put_solve(t_p *p, int x, int y)
{
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
	int x;
	int y;
	int ret;

	x = 0;
	y = 0;
	ret = 0;
	// dprintf(2, "part %d\n", ft_find_last_move(p));
	if (ft_algo_center_horizontal(p) == 1)
		return (1);
	if (ft_algo_center_vertical(p) == 1)
		return (1);
	while (x < p->line_map)
	{
		y = 0;
		while (y < p->col_map)
		{
			ret = ft_check_piece(p, x, y);
			if (ret == 1)
			{
				dprintf(2, "\nX : %d, Y : %d\n", x, y);
				ft_put_solve(p ,x , y);
				// dprintf(2, "map\n%s\npiece\n%s\n", p->line, p->ptr);
				return (1);
			}
			else if (ret == 2)
				return (0);
			y++;
		}
		x++;
	}
	// ft_putstr("0 0\n");
	return (0);
}
