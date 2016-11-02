/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erenozdek <erenozdek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 02:11:17 by eozdek            #+#    #+#             */
/*   Updated: 2016/11/01 17:43:23 by erenozdek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H
#include "get_next_line.h"
#include <stdio.h>

typedef struct	s_p
{
	int 	turn;
	int		firstX;
	int		firstY;
	int		quarter_x;
	int		quarter_y;
	int		quarter_xmax;
	int 	quarter_ymax;
	int		algo_x;
	int		algo_y;
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

int 		ft_check_piece_exceed_bottom_map(char *piece, int index_l);
int 		ft_check_piece_exceed_right_map(char *piece, int index_w, int width);
int 		ft_algo_left_vertical(t_p *p);
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
int 		ft_algo_quarter(t_p *p);
int 		ft_algo_diagonal(t_p *p);
int 	ft_algo_opp_diagonal(t_p *p);
int ft_algo_left(t_p *p);
int ft_algo_right(t_p *p);
int ft_algo_bottom(t_p *p);
int ft_algo_top(t_p *p);
#endif
