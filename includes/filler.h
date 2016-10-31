/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 02:11:17 by eozdek            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/10/27 14:13:33 by eozdek           ###   ########.fr       */
=======
/*   Updated: 2016/10/28 13:31:30 by erenozdek        ###   ########.fr       */
>>>>>>> bca124e0e88eb9f693e56e654baaf542c4bb2e23
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
	char	opp;
	char	*ptr; // la piece
	char	*line; // la map
}				t_p;

void		init_struct_p(t_p *p);
void		ft_map_size(char *line, t_p *p);
void		ft_piece_big_size(char *line, t_p *p);
void		ft_stock_piece(char *line, t_p *ap);
void		ft_stock_map(char *line, t_p *p);
void		print_map(char *map, int curse);
void		print_piece(char *piece, int curse);
void		ft_put_solve(t_p *p, int x, int y);
void		ft_error();
int 		ft_check_piece_exceed_map(char *piece, int index_w, int index_l, int width, int length);
int			game_player(char *line, t_p *p);
int			ft_check_piece(t_p *p, int x, int y);
int			ft_find_out_place(t_p *p);
int			ft_find_last_move(t_p *p);
int			ft_algo_center_horizontal(t_p *p);
int			ft_algo_center_vertical(t_p *p);

#endif
