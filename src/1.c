/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:38:48 by eozdek            #+#    #+#             */
/*   Updated: 2016/10/17 17:11:30 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
//
// int		game_player(char *line, t_p *p)
// {
// 	if (line[10] == '1')
// 	{
// 		p->ch = 'O';
// 		return (1);
// 	}
// 	else
// 	{
// 		p->ch = 'X';
// 		// dprintf(2, "\t%c", p->ch);
// 		return (0);
// 	}
// }
//
// void	ft_map_size(char *line, t_p *p)
// {
// 	int j;
//
// 	j = 8;
// 	p->i = ft_atoi(line + 8);
// 	while (line[j] >= '0' && line[j] <= '9')
// 		j++;
// 	p->j = ft_atoi(line + j);
// }
//
// void	ft_piece_size(char *line, t_p *p)
// {
// 	int j;
//
// 	j = 6;
// 	if (ft_strncmp(line, "Piece", 5) == 0)
// 	{
// 		p->n = ft_atoi(line + 6);
// 		while (line[j] >= '0' && line[j] <= '9')
// 			j++;
// 		p->m  = ft_atoi(line + j);
// 		p->piece = j;
// 	}
// }
//
void	ft_stock_map(char *line, t_p *p)
{
	int i;

	i = 0;
	while ((line[i] >= '0' && line[i] <= '9') || line[i] == ' ')
		i++;
	if (ft_strncmp(line, "Piece", 5) != 0)
		p->line = ft_strjoin(ft_strsub(line, i, ft_strlen(line) - i), "\n");
}

void	ft_stock_piece(char *line, t_p *p, int i)
{
	int j;

	j = 0;
	if (p->col_piece > p->col_map || p->line_piece > p->line_map)
		error();
	if (p->piece > 0 && p->piece < i && (line[0] == '.' || line[0] == '*'))
	{
		p->ptr = ft_strjoin(line, "\n");
		while (line[j] != '\0')
		{
			if (line[j] == '*')
			{
				p->nb++;
			}
			j++;
		}
		// dprintf(2, "\t%s", p->ptr);
	}
	// if (p->piece > 0 && p->piece < i && (line[0] != '.' || line[0] != '*'))
	// {
	// 	tab_init(p);
	// 	tab_put(p);
	//
	// }
}
