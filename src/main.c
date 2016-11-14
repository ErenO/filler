/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erenozdek <erenozdek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 02:06:07 by eozdek            #+#    #+#             */
/*   Updated: 2016/11/14 21:22:00 by erenozdek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		init_struct_p(t_p *p)
{
	p->x = 0;
	p->y = 0;
	p->ch_place = 0;
	p->turn = 0;
	p->line_map = 0;
	p->col_map = 0;
	p->col_piece = 0;
	p->line_piece = 0;
	p->piece = 0;
	p->check_map = 0;
	p->tab = NULL;
	p->ptr = ft_strnew(0);
	p->line = ft_strnew(0);
	p->piece_size = 0;
	p->nb_line = -1;
}

int			main(void)
{
	t_p		*p;
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 8;
	p = (t_p *)malloc(sizeof(t_p));
	init_struct_p(p);
	while (get_next_line(0, &line) == 1)
	{
		dprintf(2, "%s\n", line);
		i == 0 ? game_player(line, p) : 0;
		i == 1 ? ft_map_size(line, p) : "";
		if (i > 2)
		{
			ft_piece_big_size(line, p);
			ft_stock_map(line, p);
			ft_stock_piece(line, p);
		}
		i++;
		j = 0;
	}
	free(p);
	return (0);
}
