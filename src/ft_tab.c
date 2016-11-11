/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 13:27:16 by eozdek            #+#    #+#             */
/*   Updated: 2016/11/11 17:16:28 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int ft_algo_left(t_p *p)
{
	int x;
	int y;
	int ret;

	x = 0;
	y = 0;
	ret = 0;
	dprintf(2, "algo left\n");
	while (y < p->col_map)
	{
		x = p->line_map;
		while (x >= 0)
		{
			ret = ft_check_piece(p, x, y);
			if (ret == 1)
			{
				ft_put_solve(p ,x , y);
				p->piece = 0;
				return (1);
			}
			else if (ret == 2)
				return (0);
			x--;
		}
		y++;
	}
	ft_putstr("0 0\n");
	return (0);
}

int ft_algo_right(t_p *p)
{
	int x;
	int y;
	int ret;

	x = 0;
	y = p->col_map;
	ret = 0;
	dprintf(2, "algo right\n");
	while (y >= 0)
	{
		x = 0;
		while (x < p->line_map)
		{
			ret = ft_check_piece(p, x, y);
			if (ret == 1)
			{
				ft_put_solve(p ,x , y);
				return (1);
			}
			else if (ret == 2)
				return (0);
			x++;
		}
		y--;
	}
	ft_putstr("0 0\n");
	return (0);
}

int 	ft_algo_middle_top(t_p *p)
{
	int x;
	int y;
	int ret;

	x = p->line_map / 2;
	y = 0;
	ret = 0;
	dprintf(2, "algo middle top\n");
	while (x < p->line_map)
	{
		y = p->col_map / 4;
		while (y < p->col_map)
		{
			ret = ft_check_piece(p, x, y);
			if (ret == 1)
			{
				ft_put_solve(p ,x , y);
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

int 	ft_algo_middle_bottom(t_p *p)
{
	int x;
	int y;
	int ret;

	x = p->line_map / 2;
	y = p->col_map;
	ret = 0;
	dprintf(2, "algo middle bottom\n");
	while (x >= 0)
	{
		y = p->col_map;
		while (y >= 0)
		{
			ret = ft_check_piece(p, x, y);
			if (ret == 1)
			{
				ft_put_solve(p ,x , y);
				return (1);
			}
			else if (ret == 2)
				return (0);
			y--;
		}
		x--;
	}
	// ft_putstr("0 0\n");
	return (0);
}

/*
** top left
*/
int ft_algo_top_left(t_p *p)
{
	int x;
	int y;
	int ret;

	x = 0;
	y = 0;
	ret = 0;
	dprintf(2, "algo top left\n");
	while (x < p->line_map)
	{
		y = 0;
		while (y < p->col_map)
		{
			ret = ft_check_piece(p, x, y);
			if (ret == 1)
			{
				ft_put_solve(p ,x , y);
				return (1);
			}
			else if (ret == 2)
				return (0);
			y++;
		}
		x++;
	}
	ft_putstr("0 0\n");
	return (0);
}
/*
** top right
*/

int ft_algo_top_right(t_p *p)
{
	int x;
	int y;
	int ret;

	x = 0;
	y = p->col_map;
	ret = 0;
	dprintf(2, "algo top right\n");
	while (x < p->line_map)
	{
		y = p->col_map;
		while (y > 0 )
		{
			ret = ft_check_piece(p, x, y);
			if (ret == 1)
			{
				ft_put_solve(p ,x , y);
				return (1);
			}
			else if (ret == 2)
				return (0);
			y--;
		}
		x++;
	}
	ft_putstr("0 0\n");
	return (0);
}

int ft_algo_bottom(t_p *p)
{
	int x;
	int y;
	int ret;

	x = p->line_map;
	y = 0;
	ret = 0;
	dprintf(2, "algo bottom\n");
	while (x >= 0)
	{
		y = 0;
		while (y < p->col_map)
		{
			ret = ft_check_piece(p, x, y);
			if (ret == 1)
			{
				ft_put_solve(p ,x , y);
				return (1);
			}
			else if (ret == 2)
				return (0);
			y++;
		}
		x--;
	}
	ft_putstr("0 0\n");
	return (0);
}

int ft_algo_bottom_right(t_p *p)
{
	int x;
	int y;
	int ret;

	x = p->line_map;
	y = p->col_map;
	ret = 0;
	dprintf(2, "algo bottom right\n");
	while (x >= 0)
	{
		y = p->col_map;
		while (y >= 0)
		{
			ret = ft_check_piece(p, x, y);
			if (ret == 1)
			{
				ft_put_solve(p ,x , y);
				return (1);
			}
			else if (ret == 2)
				return (0);
			y--;
		}
		x--;
	}
	ft_putstr("0 0\n");
	return (0);
}
