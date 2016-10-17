/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 02:06:07 by eozdek            #+#    #+#             */
/*   Updated: 2016/10/17 16:54:58 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "filler.h"
#include "../includes/filler.h"
#include <stdio.h>

int main(void)
{
	t_p *p;
	char *line;
	int i;
	int j;

	i = 0;
	j = 8;
	p = (t_p *)malloc(sizeof(t_p));
	init_struct_p(p);
	while (get_next_line(0, &line) == 1)
	{
		if (i == 0)
			game_player(line, p);
		if (i == 1)
			ft_map_size(line, p);
		if (i > 2)
		{
			ft_piece_size(line, p);
			ft_stock_map(line, p);
			// ft_piece_size(line, p);
			ft_stock_piece(line, p, i);
		}
		// ft_putstr("2, 10");
		dprintf(2, "%s\n", line);
		i++;
		j = 0;
	}
	free(p);
	return (0);
}
