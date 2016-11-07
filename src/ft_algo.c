/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erenozdek <erenozdek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 10:52:19 by eozdek            #+#    #+#             */
/*   Updated: 2016/11/07 20:19:16 by erenozdek        ###   ########.fr       */
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

void	ft_find_character_place(t_p *p)
{
	int i;
	int curse;

	i = 0;
	curse = 0;
	while (p->line[i] != 0)
	{
		curse = i % (p->col_map + 1);
		if (p->line[i] == p->ch && curse < (p->col_map / 2))
			p->ch_place = 1;
		else if (p->line[i] == p->ch && curse > (p->col_map / 2))
			p->ch_place = 2;
		i++;
	}
}
/*
	Check si la piece rentre, return 1 si c'est bon, 0 dans le cas contraire
*/

static int 	ft_curse_ok(t_p *p, int *count, int *map_place, int *piece_place)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < (p->col_piece) && p->line[(*map_place)] != 0)
	{
		if (p->line[(*map_place)] != '\n' && i != 1)
		{
			(*count) += (p->line[(*map_place)] == p->ch && p->ptr[(*piece_place)] == '*') ? 1 : 0;
			if (p->line[(*map_place)] == '\0')
				return (2);
			if ((p->line[(*map_place)] == p->opp || p->line[(*map_place)] == (p->opp + 32))
				&& p->ptr[(*piece_place)] == '*')
				return (0);
			if (((j + p->col_piece) > p->col_map && p->ptr[(*piece_place)] == '*'))
				return (0);
			if (p->line[(*map_place)] == '\n' && p->ptr[(*piece_place)] == '*')
				return (0);
			(*map_place) += 1;
		}
		else
		{
			i = 1;
			if (p->ptr[(*piece_place)] == '*')
				return (0);
		}
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
	i = (p->line_map + p->line_piece) - (x + p->line_piece);
	if (i > 0 && ft_check_piece_exceed_bottom_map(p->ptr, i) == 0)
		return (0);
	j = (p->col_map + p->col_piece) - (y + p->col_piece);
	if (j > 0 && ft_check_piece_exceed_right_map(p->ptr, j, p->col_piece + 1) == 0)
		return (0);
	i = 0;
	while (i < p->line_piece && (i + p->line_piece) < p->line_map)
	{
		j = 0;
		map_place = y + ((p->col_map + 1) * (x + i));
		piece_place = ((p->col_piece + 1) * i);
		if (ft_curse_ok(p, &count, &map_place, &piece_place) == 0)
			return (0);
		i++;
	}
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
	//map00 X
	if (p->col_map < 20 && p->ch_place == 1)
	{
		dprintf(2, "a\n");
		if (p->turn < 30)
		{
			if (p->turn < 10)
				return (ft_algo_top_left(p));
			if (p->turn % 2 == 0)
				return (ft_algo_top_left(p));
			else
				return (ft_algo_left(p));
		}
		else
		{
			return (ft_algo_right(p));
		}

	}
	else if (p->col_map < 20 && p->ch_place == 2)
	{
		dprintf(2, "b\n");
		if (p->turn < 5)
			return (ft_algo_top_right(p));
		if (p->turn % 2 == 0)
			return (ft_algo_right(p));
		else
			return (ft_algo_bottom(p));

	}
	else if (p->col_map < 50 && p->ch_place == 1)
	{
		dprintf(2, "d\n");
		//map01 O
		if (p->turn < 3)
		{
			if (!ft_algo_middle_bottom(p))
				return (ft_algo_right(p));
			else
				return (1);
		}
		if (p->turn < 30)
			return (ft_algo_top_left(p));
		if (p->turn < 100)
			return (ft_algo_right(p));
		if (p->turn < 200)
			return (ft_algo_bottom(p));
		if (p->turn >= 200)
			return (ft_algo_left(p));
	}
	else if (p->col_map < 50 && p->ch_place == 2)
	{
		dprintf(2, "c\n");
		//map01 X
		if (p->turn < 5)
			return (ft_algo_middle_top(p));
		if (p->turn < 10)
			return (ft_algo_left(p));
		if (p->turn % 2 == 0)
		{
			return (ft_algo_top_right(p));
		}
		else
			return (ft_algo_left(p));
	}
	else if (p->col_map >= 50 && p->ch_place == 1)
	{
		dprintf(2, "e\n");
		//map02 X
		if (p->turn < 300)
		{
			if (p->turn < 30)
				return (ft_algo_top_left(p));
			if (p->turn % 2 == 0)
				return (ft_algo_bottom(p));
			else
				return (ft_algo_right(p));
		}
		else
		{
			// if (p->turn % 2 == 0)
				if (!ft_algo_middle_bottom(p))
				{
					return (ft_algo_right(p));
				}
				else
					return (1);
			// else
				// return (ft_algo_right(p));
		}
		// if (p->turn < 100)
		// 	return (ft_algo_right(p));
		// if (p->turn < 200)
		// 	return (ft_algo_bottom(p));
		// if (p->turn >= 200)
		// 	return (ft_algo_left(p));
	}
	else if (p->col_map >= 50 && p->ch_place == 2)
	{
		dprintf(2, "f\n");
		//map02 O
		if (p->turn < 20)
			return (ft_algo_bottom_right(p));
		if (p->turn % 2 == 0)
			return (ft_algo_top_right(p));
		else
			return (ft_algo_left(p));
	}

	ft_putstr("0 0\n");
	return (0);
}

//map01 O
// if (p->turn < 3)
// 	return (ft_algo_middle_bottom(p));
//map02 X
// if (p->piece == 0)
// return (ft_algo_bottom(p));
// else
// return (ft_algo_right(p));
// if (p->turn < 30)
// 	return (ft_algo_top_left(p));
// if (p->turn < 100)
// 	return (ft_algo_right(p));
// if (p->turn < 200)
// 	return (ft_algo_bottom(p));
// if (p->turn >= 200)
// 	return (ft_algo_left(p));
//map01 X
// if (p->turn < 5)
// 	return (ft_algo_middle_top(p));
// if (p->turn < 10)
// 	return (ft_algo_left(p));
// if (p->piece == 0)
// {
// 	return (ft_algo_top_right(p));
// }
// else
// 	return (ft_algo_left(p));
//map02 O
// if (p->turn < 20)
// 	return (ft_algo_bottom_right(p));
// if (p->piece == 0)
// 	return (ft_algo_top_right(p));
// else
// 	return (ft_algo_left(p));
