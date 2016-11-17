/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erenozdek <erenozdek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 10:52:19 by eozdek            #+#    #+#             */
/*   Updated: 2016/11/17 13:00:53 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_big_map(t_p *p)
{
	if (p->ch_place == 1)
	{
		if (p->turn < 300)
		{
			if (p->turn < 30)
				return (ft_algo_top_left(p));
			if (p->turn % 2 == 0)
				return (ft_algo_bottom(p));
			return (ft_algo_right(p));
		}
		return (!ft_algo_middle_bottom(p)) ? ft_algo_right(p) : 1;
	}
	else if (p->ch_place == 2)
	{
		if (p->turn > 500)
			return (ft_algo_bottom_right(p));
		if (p->turn % 2 == 0 && p->turn < 100)
			return (ft_algo_top_right(p));
		if (p->turn < 150)
			return (ft_algo_left(p));
		if (p->turn % 2 == 0)
			return (!ft_algo_middle_right(p)) ? ft_algo_left(p) : 1;
		return (!ft_algo_middle_top(p)) ? ft_algo_bottom(p) : 1;
	}
	return (0);
}

int		ft_middle_map(t_p *p)
{
	if (p->ch_place == 1)
	{
		if (p->turn < 3)
			return (!ft_algo_middle_bottom(p)) ? ft_algo_right(p) : (1);
		if (p->turn < 30)
			return (ft_algo_top_left(p));
		if (p->turn < 100)
			return (ft_algo_right(p));
		if (p->turn < 200)
			return (ft_algo_bottom(p));
		if (p->turn >= 200)
			return (ft_algo_left(p));
	}
	else if (p->ch_place == 2)
	{
		if (p->turn < 5)
			return (ft_algo_middle_top(p));
		if (p->turn < 10)
			return (ft_algo_left(p));
		if (p->turn % 2 == 0)
			return (ft_algo_top_right(p));
		else
			return (ft_algo_left(p));
	}
	return (0);
}

int		ft_small_map(t_p *p)
{
	if (p->ch_place == 1)
	{
		if (p->turn < 10)
			return (ft_algo_bottom_right(p));
		if (p->turn % 2 == 0)
			return (ft_algo_top_right(p));
		else
			return (ft_algo_right(p));
	}
	else if (p->ch_place == 2)
	{
		if (p->turn < 10)
			return (ft_algo_top_left(p));
		if (p->turn % 2 == 0)
			return (ft_algo_top_right(p));
		else
			return (ft_algo_left(p));
	}
	return (0);
}

int		ft_put_solve(t_p *p, int x, int y)
{
	p->turn++;
	dprintf(2, "p->turn %d\np->ch_place %d\n", p->turn, p->ch_place);
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
	p->ptr = NULL;
	p->line = NULL;
	p->ptr = ft_strnew(0);
	p->line = ft_strnew(0);
	return (1);
}

int		ft_find_out_place(t_p *p)
{
	if (p->col_map < 20)
		return (ft_small_map(p));
	else if (p->col_map < 50)
		return (ft_middle_map(p));
	else if (p->col_map >= 50)
		return (ft_big_map(p));
	ft_putstr("0 0\n");
	return (0);
}
