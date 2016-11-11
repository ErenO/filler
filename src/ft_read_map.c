/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erenozdek <erenozdek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 16:59:54 by eozdek            #+#    #+#             */
/*   Updated: 2016/11/12 00:24:22 by erenozdek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Connaitre quel caractère on utilise
*/

int		game_player(char *line, t_p *p)
{
	if (line[10] == '1')
	{
		p->ch = 'O';
		p->opp = 'X';
		return (1);
	}
	else
	{
		p->ch = 'X';
		p->opp = 'O';
		return (0);
	}
}

/*
** Connaitre la taille de la map
*/

void	ft_map_size(char *line, t_p *p)
{
	int j;

	j = 8;
	p->line_map = ft_atoi(line + 8);
	while (line[j] >= '0' && line[j] <= '9')
		j++;
	p->col_map = ft_atoi(line + j);
}

/*
** Connaitre la taille de la piece
*/

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
		p->col_piece = ft_atoi(line + j);
	}
}

/*
** stocker la map dans p->line
*/

void	ft_stock_map(char *line, t_p *p)
{
	int i;

	i = 0;
	if (line[0] != ' ' && ft_strncmp(line, "Plateau", 7) != 0)
	{
		while ((line[i] >= '0' && line[i] <= '9') || line[i] == ' ')
			i++;
		if (ft_strncmp(line, "Piece", 5) != 0 && !p->check_map)
			p->line = ft_strjoin(p->line, ft_strjoin(ft_strsub(line, i,
			ft_strlen(line) - i), "\n"));
		else
			p->check_map = 1;
	}
}

/*
** stocker la piece dans p->ptr et appeler l'algo
*/

void	ft_stock_piece(char *line, t_p *p)
{
	int ret;
	int j;

	j = 0;
	ret = 0;
	if (p->check_map == 1)
		p->piece_size--;
	if (p->put_line > 0)
	{
		p->put_line--;
		p->ptr = ft_strjoin(p->ptr, ft_strjoin(line, "\n"));
	}
	if (ft_strncmp(line, "Piece", 5) == 0 && p->put_line == -1)
		p->put_line = p->line_piece;
	if (p->ptr == NULL)
		p->ptr = ft_strnew(0);
	if (p->put_line == 0)
	{
		if (p->turn == 0)
			ft_find_character_place(p);
		ret = ft_find_out_place(p);
		p->put_line = -1;
	}
	if (ret == 1)
		p->check_map = 0;
}
