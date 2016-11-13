/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:27:42 by eozdek            #+#    #+#             */
/*   Updated: 2016/11/13 20:40:50 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_check_piece_exceed_bottom_map(char *piece, int index_l)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < index_l && piece[i] != 0)
	{
		if (piece[i] == '\n')
			j++;
		i++;
	}
	while (piece[i] != 0)
	{
		if (piece[i] == '*')
			return (0);
		i += 1;
	}
	return (1);
}

int		ft_check_piece_exceed_right_map(char *piece, int index_w, int width)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (piece[i] != 0)
	{
		if (piece[i] == '*' && i % width >= index_w)
			return (0);
		i += 1;
	}
	return (1);
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

int		ft_curse_ok(t_p *p, int *count, int *map_place, int *piece_place)
{
	int j;

	j = 0;
	while (j < (p->col_piece) && p->line[(*map_place)] != 0)
	{
		if (p->line[(*map_place)] != '\n')
		{
			(*count) += (p->line[(*map_place)] == p->ch
			&& p->ptr[(*piece_place)] == '*') ? 1 : 0;
			if (p->line[(*map_place)] == '\0')
				return (2);
			if (p->line[(*map_place)] == p->opp
			&& p->ptr[(*piece_place)] == '*')
				return (0);
			if (((j + p->y) > p->col_map && p->ptr[(*piece_place)] == '*'))
				return (0);
			if (p->line[(*map_place)] == '\n' && p->ptr[(*piece_place)] == '*')
				return (0);
			(*map_place) += 1;
		}
		(*piece_place) += 1;
		j++;
	}
	return (1);
}

int		ft_check_piece(t_p *p, int x, int y)
{
	int i;
	int count;
	int map_place;
	int piece_place;

	count = 0;
	map_place = (p->col_map + 1) * x;
	piece_place = 0;
	i = (p->line_map + p->line_piece) - (x + p->line_piece);
	if (i > 0 && ft_check_piece_exceed_bottom_map(p->ptr, i) == 0)
		return (0);
	i = (p->col_map + p->col_piece) - (y + p->col_piece);
	if (i > 0 && !ft_check_piece_exceed_right_map(p->ptr, i, p->col_piece + 1))
		return (0);
	i = 0;
	while (i < p->line_piece && (i + p->line_piece) <= p->line_map)
	{
		map_place = y + ((p->col_map + 1) * (x + i));
		piece_place = ((p->col_piece + 1) * i);
		if (ft_curse_ok(p, &count, &map_place, &piece_place) != 1)
			return (0);
		i++;
	}
	return (count == 1) ? 1 : 0;
}
