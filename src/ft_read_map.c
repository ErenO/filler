/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erenozdek <erenozdek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 16:59:54 by eozdek            #+#    #+#             */
/*   Updated: 2016/11/01 17:00:49 by erenozdek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_struct_p(t_p *p)
{
	p->turn = 0;
	p->firstX = 0;
	p->firstY = 0;
	p->quarter_x = 0;
	p->quarter_y = 0;
	p->quarter_xmax = 0;
	p->quarter_ymax = 0;
	p->algo_x = 0;
	p->algo_y = 0;
	p->line_map = 0;
	p->col_map = 0;
	p->col_piece = 0;
	p->line_piece = 0;
	p->piece = 0;
	p->check_map = 0;
	p->nb = 0;
	p->tab = NULL;
	p->ptr = ft_strnew(0);
	p->line = ft_strnew(0);
	p->piece_size = 0;
	p->put_line = -1;
}

/* Connaitre quel caractère on utilise */

int game_player(char *line, t_p *p)
{
	if (line[10] == '1')
	{
		p->ch = 'O';
		p->opp = 'x';
		return (1);
	}
	else
	{
		p->ch = 'X';
		p->opp = 'o';
		return (0);
	}
}

/* Connaitre la taille de la map */

void	ft_map_size(char *line, t_p *p)
{
	int j;

	j = 8;
	p->line_map = ft_atoi(line + 8);
	while (line[j] >= '0' && line[j] <= '9')
		j++;
	p->col_map = ft_atoi(line + j);
}

/* Connaitre la taille de la piece */

void	ft_piece_big_size(char *line, t_p *p)
{
	int j;

	j = 6;
	if (ft_strncmp(line, "Piece", 5) == 0)
	{
		p->piece_size = ft_atoi(line + 6);
		p->line_piece = ft_atoi(line + 6);
		while (line[j] >= '0' && line[j] <= '9')
			j++;
		p->col_piece  = ft_atoi(line + j);
	}
}

/* stocker la map dans p->line */

void 	ft_stock_map(char *line, t_p *p)
{
	int i;

	i = 0;
	if (line[0] != ' ' && ft_strncmp(line, "Plateau", 7) != 0)
	{
		while ((line[i] >= '0' && line[i] <= '9') || line[i] == ' ')
			i++;
		if (ft_strncmp(line, "Piece", 5) != 0 && !p->check_map)
			p->line = ft_strjoin(p->line, ft_strjoin(ft_strsub(line, i, ft_strlen(line) - i), "\n"));
		else
			p->check_map = 1;
	}
}

void ft_stock_piece(char *line, t_p *p)
{
	int ret;
	int j;

	j = 0;
	ret = 0;
	// if (p->col_piece > p->col_map || p->line_piece > p->line_map)
	// 	error();
	if (p->check_map == 1)
		p->piece_size--;
	if (p->put_line > 0)
	{
		p->put_line--;
		p->ptr = ft_strjoin(p->ptr, ft_strjoin(line, "\n"));
	}
	if (ft_strncmp(line, "Piece", 5) == 0 && p->put_line == -1)
	{
		p->put_line = p->line_piece;
		// dprintf(2, "put_line %d\n", p->put_line);
	}
	if (p->ptr == NULL)
	{
		p->ptr = ft_strnew(0);
	}
	if (p->put_line == 0)
	{
		// dprintf(2, "piece\n%shello\n", p->ptr);
		ret = ft_find_out_place(p);
		p->put_line = -1;
	}
	if (ret == 1)
	{
		p->check_map = 0;
	}
}
