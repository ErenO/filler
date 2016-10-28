/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erenozdek <erenozdek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 13:27:16 by eozdek            #+#    #+#             */
/*   Updated: 2016/10/28 18:36:06 by erenozdek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_error()
{
	write(1, "ERROR\n", 6);
	exit(0);
}

int 	ft_check_piece_exceed_map(char *piece, int index_w, int index_l, int width, int length)
{
	int i;
	int j;

	i = 0;
	j = 0;
	(void)length;
	while (piece[i] != 0)
	{
		if (piece[i] == '\n')
			j++;
		// dprintf(2, "i:%d;j%d;width:%d;index_w:%d;index_l:%d;length:%d\n", i, j, width, index_w, index_l, length);
		if (piece[i] == '*' && i % width >= index_w && length == 1)
		{
			print_map(piece, i);
			return (0);
		}
	 	if (piece[i] == '*' && j >= index_l && length == 0)
		{
			print_map(piece, i);
			return (0);
		}
		i += 1;
	}
	dprintf(2, "\n");
	return (1);
}

int ft_algo_center_horizontal(t_p *p)
{
	int x;
	int y;
	int ret;
	int center;

	center = p->line_map / 2 + 1;
	x = center - 2;
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

	center = p->col_map / 2 + 1;
	x = 0;
	y = center - 2;
	ret = 0;
	while (x < p->line_map)
	{
		y = center - 2;
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
