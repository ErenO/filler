/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erenozdek <erenozdek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 10:52:19 by eozdek            #+#    #+#             */
/*   Updated: 2016/11/02 01:13:11 by erenozdek        ###   ########.fr       */
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
	int max;

	i = 0;
	number = 0;
	max = count[0];
	while (i < 4)
	{
		if (max > count[i])
			max = count[i];
		i++;
	}
	return (max);
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
	i = ft_max(count);
	if (i == 0)
	{
		p->quarter_x = 0;
		p->quarter_y = 0;
		p->quarter_xmax = p->line_piece / 2;
		p->quarter_ymax = p->col_piece / 2;
	}
	else if (i == 1)
	{
		p->quarter_x = 0;
		p->quarter_y =  p->col_piece / 2;
		p->quarter_xmax = p->line_piece / 2;
		p->quarter_ymax = p->col_piece;
	}
	else if (i == 2)
	{
		p->quarter_x = p->line_piece / 2;
		p->quarter_y = 0;
		p->quarter_xmax = p->line_piece;
		p->quarter_ymax = p->col_piece / 2;
	}
	else if (i == 3)
	{
		p->quarter_x = p->line_piece / 2;
		p->quarter_y = p->col_piece / 2;
		p->quarter_xmax = p->line_piece;
		p->quarter_ymax = p->col_piece;
	}
	count[0] = count[0] + count[2];
	count[1] = count[1] + count[3];
	if (count[0] > count[1])
		return (0);
	else
		return (1);
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
	// dprintf(2, "X %d, rest %d\n",x,  p->line_map - p->line_piece);
	// dprintf(2, "Y %d, rest %d\n", y, p->col_map - p->col_piece);
	i = (p->line_map + p->line_piece) - (x + p->line_piece);
	// if (i > 0)
	// {
		// dprintf(2, "hX%d, Y%d\n", x, y);
	// }
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
	// if (p->piece == 0 && count == 1)
	// {
	// 	p->firstX = x;
	// 	p->firstY = y;
	// 	p->piece = 1;
	// }
	return (count == 1) ? 1 : 0;
}

void ft_put_solve(t_p *p, int x, int y)
{
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
	int i;

	i = 0;
	// dprintf(2, "part %d\n", ft_find_last_move(p));
	i = ft_find_last_move(p);
	// if (ft_algo_diagonal(p) == 1)
	// 	return (1);
	// if (ft_algo_opp_diagonal(p) == 1)
	// 	return (1);
	// if (ft_algo_center_horizontal(p) == 1)
	// 	return (1);
	if (ft_algo_center_vertical(p) == 1)
		return (1);
	// if (ft_algo_quarter(p) == 1)
	// 	return (1);
	// if (ft_algo_left_vertical(p) == 1)
		// return (1);
	// if (ft_algo_top(p) == 1)
	// 	return (1);
	// if (p->turn < 50 || p->piece == 0)
	// 	return (ft_algo_left(p));
	// else if (p->piece == 1)
	// 	return (ft_algo_right(p));
	// else
	// 	return (ft_algo_right(p));
	if (p->turn < 20)
	{
		return (ft_algo_top(p));
	}
	if (p->piece == 0)
	{
		return (ft_algo_top(p));
	}
	else
	{
		return (ft_algo_left(p));
	}
	// if (i == 0)
	// 	return (ft_algo_right(p));
	// else
	// 	return (ft_algo_left(p));
	ft_putstr("0 0\n");
	return (0);
}

// if (i == 0)
// {
// 	while (x < (p->line_map / 2))
// 	{
// 		y = 0;
// 		while (y < p->col_map)
// 		{
// 			ret = ft_check_piece(p, x, y);
// 			if (ret == 1)
// 			{
// 				dprintf(2, "\nX : %d, Y : %d\n", x, y);
// 				ft_put_solve(p ,x , y);
// 				// dprintf(2, "map\n%s\npiece\n%s\n", p->line, p->ptr);
// 				return (1);
// 			}
// 			else if (ret == 2)
// 			return (0);
// 			y++;
// 		}
// 		x++;
// 	}
// }
// if (i == 1)
// {
// 	x = p->line_map / 2;
// 	while (x < p->line_map)
// 	{
// 		y = 0;
// 		while (y < p->col_map)
// 		{
// 			ret = ft_check_piece(p, x, y);
// 			if (ret == 1)
// 			{
// 				dprintf(2, "\nX : %d, Y : %d\n", x, y);
// 				ft_put_solve(p ,x , y);
// 				// dprintf(2, "map\n%s\npiece\n%s\n", p->line, p->ptr);
// 				return (1);
// 			}
// 			else if (ret == 2)
// 			return (0);
// 			y++;
// 		}
// 		x++;
// 	}
// }
