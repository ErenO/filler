/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_middle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:37:27 by eozdek            #+#    #+#             */
/*   Updated: 2016/11/13 20:33:38 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_algo_middle_right(t_p *p)
{
	int x;
	int y;
	int ret;

	x = 0;
	y = p->col_map / 4;
	ret = 0;
	while (y >= 0)
	{
		x = 0;
		while (x < p->line_map)
		{
			if ((ret = ft_find_solution(p, x, y)) != 2)
				return (ret);
			x++;
		}
		y--;
	}
	return (0);
}

int		ft_algo_middle_top(t_p *p)
{
	int x;
	int y;
	int ret;

	x = p->line_map / 2;
	y = 0;
	ret = 0;
	while (x < p->line_map)
	{
		y = p->col_map;
		while (y >= p->col_map / 4)
		{
			if ((ret = ft_find_solution(p, x, y)) != 2)
				return (ret);
			y--;
		}
		x++;
	}
	return (0);
}

int		ft_algo_middle_bottom(t_p *p)
{
	int x;
	int y;
	int ret;

	x = p->line_map / 2;
	y = p->col_map;
	ret = 0;
	while (x >= 0)
	{
		y = p->col_map;
		while (y >= 0)
		{
			if ((ret = ft_find_solution(p, x, y)) != 2)
				return (ret);
			y--;
		}
		x--;
	}
	return (0);
}

int		ft_algo_bottom_right(t_p *p)
{
	int x;
	int y;
	int ret;

	x = p->line_map;
	y = p->col_map;
	ret = 0;
	while (x >= 0)
	{
		y = p->col_map;
		while (y >= 0)
		{
			if ((ret = ft_find_solution(p, x, y)) != 2)
				return (ret);
			y--;
		}
		x--;
	}
	ft_putstr("0 0\n");
	return (0);
}

int		ft_find_solution(t_p *p, int x, int y)
{
	int ret;

	ret = 0;
	p->x = x;
	p->y = y;
	ret = ft_check_piece(p, x, y);
	if (ret == 1)
		return (ft_put_solve(p, x, y));
	else if (ret == 2)
		return (0);
	return (2);
}
