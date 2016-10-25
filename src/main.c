/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erenozdek <erenozdek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 02:06:07 by eozdek            #+#    #+#             */
/*   Updated: 2016/10/25 16:21:12 by erenozdek        ###   ########.fr       */
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
			line = ft_stock_map(line, p, &i);
			line = ft_piece_size(line, p, &i);
		dprintf(2, "%s\n", line);
		i++;
		j = 0;
	}
	// dprintf(2,"\np->line\n%s\np->ptr\n%s\n\n", p->line, p->ptr);
	free(p);
	return (0);
}
