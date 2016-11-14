/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_map_place.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erenozdek <erenozdek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 13:27:16 by eozdek            #+#    #+#             */
/*   Updated: 2016/11/14 22:37:05 by erenozdek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_algo_left(t_p *p)
{
	int x;
	int y;
	int ret;

	x = 0;
	y = 0;
	ret = 0;
	while (y < p->col_map)
	{
		x = p->line_map;
		while (x >= 0)
		{
			if ((ret = ft_find_solution(p, x, y)) != 2)
				return (ret);
			x--;
		}
		y++;
	}
	ft_putstr("0 0\n");
	return (0);
}

int		ft_algo_right(t_p *p)
{
	int x;
	int y;
	int ret;

	x = 0;
	y = p->col_map;
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
	ft_putstr("0 0\n");
	return (0);
}

int		ft_algo_top_left(t_p *p)
{
	int x;
	int y;
	int ret;

	x = 0;
	y = 0;
	ret = 0;
	while (x < p->line_map)
	{
		y = 0;
		while (y < p->col_map)
		{
			if ((ret = ft_find_solution(p, x, y)) != 2)
				return (ret);
			y++;
		}
		x++;
	}
	ft_putstr("0 0\n");
	return (0);
}

int		ft_algo_top_right(t_p *p)
{
	int x;
	int y;
	int ret;

	x = 0;
	y = p->col_map;
	ret = 0;
	while (x < p->line_map)
	{
		y = p->col_map;
		while (y >= 0)
		{
			if ((ret = ft_find_solution(p, x, y)) != 2)
				return (ret);
			y--;
		}
		x++;
	}
	ft_putstr("0 0\n");
	return (0);
}

int		ft_algo_bottom(t_p *p)
{
	int x;
	int y;
	int ret;

	x = p->line_map;
	y = 0;
	ret = 0;
	while (x >= 0)
	{
		y = 0;
		while (y < p->col_map)
		{
			if ((ret = ft_find_solution(p, x, y)) != 2)
				return (ret);
			y++;
		}
		x--;
	}
	ft_putstr("0 0\n");
	return (0);
}
