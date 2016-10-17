/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 16:59:54 by eozdek            #+#    #+#             */
/*   Updated: 2016/10/17 11:13:13 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void init_struct_p(t_p *p)
{
	p->line_map = 0;
	p->col_map = 0;
	p->col_piece = 0;
	p->line_piece = 0;
	p->piece = 0;
	p->nb = 0;
	p->tab = NULL;
	p->ptr = ft_strnew(0);
	p->line = ft_strnew(0);
}

/* Connaitre quel caractère on utilise */

int		game_player(char *line, t_p *p)
{
	if (line[10] == '1')
	{
		p->ch = 'O';
		// dprintf(2, "\n\n%c\n", p->ch);
		return (1);
	}
	else
	{
		p->ch = 'X';
		// dprintf(2, "\n\n%c\n", p->ch);
		return (0);
	}
}

/* Connaitre la taille de la map */

void	ft_map_size(char *line, t_p *p)
{
	int j;

	j = 8;
	p->col_map = ft_atoi(line + 8);
	// dprintf(2, "\n\n%d\n", p->i);
	while (line[j] >= '0' && line[j] <= '9')
		j++;
	p->line_map = ft_atoi(line + j);
	// dprintf(2, "\n\n%d\n", p->j);
}

/* Connaitre la taille de la piece */

void	ft_piece_size(char *line, t_p *p)
{
	int j;

	j = 6;
	if (ft_strncmp(line, "Piece", 5) == 0)
	{
		p->col_piece = ft_atoi(line + 6);
		while (line[j] >= '0' && line[j] <= '9')
			j++;
		p->line_piece  = ft_atoi(line + j);
		p->piece = j;
	}
}
