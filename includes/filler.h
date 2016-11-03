/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 02:11:17 by eozdek            #+#    #+#             */
/*   Updated: 2016/11/03 20:56:54 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "get_next_line.h"
# include <stdio.h>

typedef struct		s_p
{
	int		turn;
	int		algo_x;
	int		algo_y;
	int		put_line;
	int		put_col;
	int		line_map;
	int		line_piece;
	int		col_map;
	int		col_piece;
	int		piece;
	int		**tab;
	int		piece_size;
	int		check_map;
	char	ch;
	char	opp;
	char	*ptr;
	char	*line;
}			t_p;

int			ft_check_piece_exceed_bottom_map(char *piece, int index_l);
int			ft_check_piece_exceed_right_map(char *piece, int index_w,
	int width);
void		init_struct_p(t_p *p);
void		ft_map_size(char *line, t_p *p);
void		ft_piece_big_size(char *line, t_p *p);
void		ft_stock_piece(char *line, t_p *ap);
void		ft_stock_map(char *line, t_p *p);
void		print_map(char *map, int curse);
void		print_piece(char *piece, int curse);
void		ft_put_solve(t_p *p, int x, int y);
void		ft_error();
int			ft_check_piece_exceed_map(char *piece, int index_w,
	int index_l, int width, int length);
int			game_player(char *line, t_p *p);
int			ft_check_piece(t_p *p, int x, int y);
int			ft_find_out_place(t_p *p);
int			ft_algo_left(t_p *p);
int			ft_algo_right(t_p *p);
int			ft_algo_bottom(t_p *p);
int			ft_algo_top_left(t_p *p);
int			ft_algo_top_right(t_p *p);
int			ft_algo_middle_top(t_p *p);

#endif
