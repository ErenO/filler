/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 16:59:54 by eozdek            #+#    #+#             */
/*   Updated: 2016/10/16 17:00:09 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void init_struct_p(t_p *p)
{
	p->i = 0;
	p->j = 0;
	p->n = 0;
	p->m = 0;
	p->piece = 0;
	p->nb = 0;
	p->tab = NULL;
	p->ptr = ft_strnew(0);
	p->line = ft_strnew(0);
}
