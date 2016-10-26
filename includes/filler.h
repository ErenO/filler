/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 02:11:17 by eozdek            #+#    #+#             */
/*   Updated: 2016/10/26 09:30:56 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H
#include "get_next_line.h"
#include <stdio.h>

typedef struct	s_p
{
	int		put_line;
	int		put_col;
	int		read;
	int		line_map;
	int		line_piece;
	int		col_map;
	int		col_piece;
	int		nb;
	int		piece;
	int		*ret;
	int		**tab;
	int		piece_size;
	int		check_map;
	char	ch; // le caratere X ou O
	char	*ptr; // la piece
	char	*line; // la map
}				t_p;

/*ft_read_map*/
void		init_struct_p(t_p *p);
void		ft_map_size(char *line, t_p *p);
void		ft_piece_big_size(char *line, t_p *p);
void		ft_stock_piece(char *line, t_p *p, int i);
char		*ft_stock_map(char *line, t_p *p);
// void		find_place(t_p *p);
// void		tab_init(t_p *p);
// void		tab_put(t_p *p);

/*ft_algo*/

//int
int			game_player(char *line, t_p *p);
/*ft_tab*/
int	ft_check_piece(t_p *p, int x, int y);
int ft_find_out_place(t_p *p);
void print_map(char *map, int curse);
void print_piece(char *piece, int curse);
void ft_put_solve(int x, int y);
#endif
