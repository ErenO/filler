/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erenozdek <erenozdek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 13:27:16 by eozdek            #+#    #+#             */
/*   Updated: 2016/11/02 01:14:31 by erenozdek        ###   ########.fr       */
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
	// (void)index_l;
	// (void)piece;

	while (j < index_l && piece[i] != 0)
	{
		if (piece[i] == '\n')
			j++;
		i++;
	}
	// dprintf(2, "piece\n%s\n", piece);
	while (piece[i] != 0)
	{
		// dprintf(2, "%c", piece[i]);
	 	if (piece[i] == '*')
		{
			// print_map(piece, i);
			return (0);
		}
		i += 1;
	}
	// dprintf(2, "\n");
	return (1);
}

int 	ft_check_piece_exceed_right_map(char *piece, int index_w, int width)
{
	int i;
	int j;

	i = 0;
	j = 0;
	// dprintf(2, "hello\n");
	while (piece[i] != 0)
	{
		// if (i % width >= index_w)
		// {
			// dprintf(2, "i:%d;width:%d;index_w:%d\n", i, width, index_w);
		// }
		if (piece[i] == '*' && i % width >= index_w)
		{
			// print_map(piece, i);
			return (0);
		}
		i += 1;
	}
	// dprintf(2, "\n");
	return (1);
}

int ft_algo_center_horizontal(t_p *p)
{
	int x;
	int y;
	int ret;
	int center;

	center = p->line_map / 2;
	x = center - 1;
	y = 0;
	ret = 0;
	while (x < center)
	{
		y = 0;
		while (y < p->col_map)
		{
			ret = ft_check_piece(p, x, y);
			if (ret == 1)
			{
				dprintf(2, "\nX : %d, Y : %d\n", x, y);
				ft_put_solve(p, x, y);
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int ft_algo_center_vertical(t_p *p)
{
	int x;
	int y;
	int ret;
	int center;

	center = p->col_map / 2;
	x = 0;
	y = center;
	ret = 0;
	while (x < p->line_map)
	{
		y = center;
		while (y < center)
		{
			ret = ft_check_piece(p, x, y);
			if (ret == 1)
			{
				dprintf(2, "\nX : %d, Y : %d\n", x, y);
				ft_put_solve(p, x, y);
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int ft_algo_left_vertical(t_p *p)
{
	int x;
	int y;
	int ret;
	int center;

	center = 0;
	x = 0;
	y = 0;
	ret = 0;
	while (x < p->line_map)
	{
		y = 0;
		while (y < center)
		{
			ret = ft_check_piece(p, x, y);
			if (ret == 1)
			{
				dprintf(2, "\nX : %d, Y : %d\n", x, y);
				ft_put_solve(p, x, y);
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int ft_algo_quarter(t_p *p)
{
	int x;
	int y;
	int ret;

	x = p->quarter_x;
	y = p->quarter_y;
	ret = 0;
	while (x < p->quarter_xmax)
	{
		y = p->quarter_y;
		while (y < p->quarter_ymax)
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
	return (0);
}

int 	ft_algo_diagonal(t_p *p)
{
	int x;
	int y;
	int ret;
	int center;

	center = 2;
	x = 0;
	y = 0;
	ret = 0;
	while (x < p->line_map || y < p->col_map)
	{
			ret = ft_check_piece(p, x, y);
			if (ret == 1)
			{
				dprintf(2, "\nX : %d, Y : %d\n", x, y);
				ft_put_solve(p, x, y);
				return (1);
			}
			y++;
		x++;
	}
	return (0);
}
int 	ft_algo_opp_diagonal(t_p *p)
{
	int x;
	int y;
	int ret;
	int center;

	center = 2;
	x = p->line_map;
	y = p->col_map;
	ret = 0;
	while (x > 0 || y > 0)
	{
		ret = ft_check_piece(p, x, y);
		if (ret == 1)
		{
			dprintf(2, "\nX : %d, Y : %d\n", x, y);
			ft_put_solve(p, x, y);
			return (1);
		}
		y--;
		x--;
	}
	return (0);
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
		while (x > 0)
		{
			ret = ft_check_piece(p, x, y);
			if (ret == 1)
			{
				dprintf(2, "\nX : %d, Y : %d\n", x, y);
				ft_put_solve(p ,x , y);
				// dprintf(2, "map\n%s\npiece\n%s\n", p->line, p->ptr);
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
	while (y > 0)
	{
		x = p->line_map;
		while (x > 0)
		{
			ret = ft_check_piece(p, x, y);
			if (ret == 1)
			{
				dprintf(2, "\nX : %d, Y : %d\n", x, y);
				ft_put_solve(p ,x , y);
				// dprintf(2, "map\n%s\npiece\n%s\n", p->line, p->ptr);
				p->piece = 0;
				return (1);
			}
			else if (ret == 2)
				return (0);
			x--;
		}
		y--;
	}
	ft_putstr("0 0\n");
	return (0);
}

int ft_algo_top(t_p *p)
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
		while (y > 0)
		{
			ret = ft_check_piece(p, x, y);
			if (ret == 1)
			{
				dprintf(2, "\nX : %d, Y : %d\n", x, y);
				ft_put_solve(p ,x , y);
				// dprintf(2, "map\n%s\npiece\n%s\n", p->line, p->ptr);
				p->piece = 1;
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
	while (x > 0)
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
				p->piece = 1;
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
