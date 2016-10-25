/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erenozdek <erenozdek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 16:59:54 by eozdek            #+#    #+#             */
/*   Updated: 2016/10/25 16:46:48 by erenozdek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_struct_p(t_p *p)
{
	p->line_map = 0;
	p->col_map = 0;
	p->col_piece = 0;
	p->line_piece = 0;
	p->piece = 0;
	p->curse_map = 0;
	p->curse_piece = 0;
	p->check_map = 0;
	p->nb = 0;
	p->tab = NULL;
	p->ptr = ft_strnew(0);
	p->line = ft_strnew(0);
	p->piece_size = 0;
}

/* Connaitre quel caractère on utilise */

int		game_player(char *line, t_p *p)
{
	if (line[10] == '1')
	{
		p->ch = 'O';
		return (1);
	}
	else
	{
		p->ch = 'X';
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

char 	*ft_piece_size(char *line, t_p *p, int *index)
{
	int j;

	j = 6;
	if (ft_strncmp(line, "Piece", 5) == 0)
	{
		dprintf(2, "%s\n", line);
		p->piece_size = ft_atoi(line + 6);
		p->line_piece = ft_atoi(line + 6);
		while (line[j] >= '0' && line[j] <= '9')
			j++;
		p->col_piece  = ft_atoi(line + j);
		p->piece = j;
		line = ft_stock_piece(line, p, index);
	}
	return (line);
}

/* stocker la map dans p->line */

char 	*ft_stock_map(char *line, t_p *p, int *index)
{
	int i;
	int j;

	i = 0;
	j = 0;
	// dprintf(2, "bonjour\n");
	if ((j = ft_strncmp(line, "    0", 4)) == 0)
	{
		while (get_next_line(0, &line) == 1 && i < p->line_map)
		{
			j = 0;
			while ((line[j] >= '0' && line[j] <= '9') || line[j] == ' ')
				j++;
			p->line = ft_strjoin(p->line, ft_strjoin(ft_strsub(line, j, ft_strlen(line) - j), "\n"));
			dprintf(2, "%s\n", line);
			i++;
			(*index) += 1;
		}
	}
	// dprintf(2, "p->line\n%s\n", p->line);
	return (line);
}

char	*ft_stock_piece(char *line, t_p *p, int *index)
{
	int ret;
	int i;

	i = 0;
	ret = 0;
	// if (p->col_piece > p->col_map || p->line_piece > p->line_map)
	// 	error();
	// dprintf(2, "piece length %zu\n", ft_strlen(p->ptr));
	// dprintf(2, "hello\n");
	if (p->ptr == NULL)
		p->ptr = ft_strnew(0);
	while (get_next_line(0, &line) == 1 && i < p->line_piece)
	{
		p->ptr = ft_strjoin(p->ptr, ft_strjoin(line, "\n"));
		dprintf(2, "%s\n", line);
		// dprintf(2, "p->ptr: %s line: %s\n", p->ptr, line);
		(*index) += 1;
		i++;
	}
	ret = ft_find_out_place(p);
	// dprintf(2, "\np->piece_size: %d\np->check_map: %d\np->line_piece: %d\n", p->piece_size, p->check_map, p->line_piece);
	return (line);
}
