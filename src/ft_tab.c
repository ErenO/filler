/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erenozdek <erenozdek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 13:27:16 by eozdek            #+#    #+#             */
/*   Updated: 2016/11/07 12:12:17 by erenozdek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_error()
{
	write(1, "ERROR\n", 6);
	exit(0);
}

int 	ft_check_piece_exceed_bottom_map(char *piece, int index_l)
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

int 	ft_check_piece_exceed_right_map(char *piece, int index_w, int width)
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

int ft_algo_left(t_p *p)
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
