/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 02:11:17 by eozdek            #+#    #+#             */
/*   Updated: 2016/10/17 12:25:24 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H
#include "get_next_line.h"
#include <stdio.h>

typedef struct	s_p
{
	int		line_map;
	int		line_piece;
	int		col_map;
	int		col_piece;
	int		nb;
	int		piece;
	int		*ret;
	int		**tab;
	char	ch; // le caratere X ou O
	char	*ptr; // la piece
	char	*line; // la map
}				t_p;

//void
// void		error();
void		init_struct_p(t_p *p);
void		ft_map_size(char *line, t_p *p);
// void		ft_piece_size(char *line, t_p *p);
// void		ft_stock_piece(char *line, t_p *p, int i);
// void		ft_stock_map(char *line, t_p *p);
// void		find_place(t_p *p);
// void		tab_init(t_p *p);
// void		tab_put(t_p *p);

//int
int			game_player(char *line, t_p *p);


#endif
