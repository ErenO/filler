/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_query_sdl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 01:23:40 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/26 18:05:20 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_query_player_texture(int i, int j, int nb, t_sdl *sdl)
{
	SDL_QueryTexture(sdl->tex_play[i][nb], NULL, NULL,
		&sdl->rect_player[i][nb].w, &sdl->rect_player[i][nb].h);
	if (nb < 2)
		sdl->rect_player[i][nb].x = 1370;
	else
		sdl->rect_player[i][nb].x = 1540;
	if (nb < 2)
	{
		sdl->rect_player[i][nb].y = 20 +
		sdl->solid_rect.h + (50 * (j + 2));
	}
	else
	{
		sdl->rect_player[i][nb].y = 20 +
		sdl->solid_rect.h + (50 * (j + 2));
	}
}

void	ft_handle_query_player(t_sdl *sdl, t_vm *vm)
{
	int i;
	int k;
	int j;

	i = 0;
	j = 5;
	while (i < vm->bplr.nb_plyr)
	{
		k = 0;
		while (k < 3)
		{
			ft_query_player_texture(i, j, k++, sdl);
			if (k < 2)
				j++;
		}
		j++;
		i++;
	}
}

void	ft_query_base_texture(t_sdl *sdl)
{
	int i;

	i = 0;
	while (i < 5)
	{
		SDL_QueryTexture(sdl->texture_tab[i], NULL, NULL,
		&sdl->texture_rect[i].w, &sdl->texture_rect[i].h);
		sdl->texture_rect[i].x = sdl->solid_rect.x - 50;
		sdl->texture_rect[i].y = sdl->solid_rect.y + 50 +
		sdl->solid_rect.h + (50 * i);
		i++;
	}
}

void	ft_query_corewar_texture(t_sdl *sdl, SDL_Surface *solid)
{
	solid = TTF_RenderText_Blended(sdl->font, "COREWAR GAME", BACKGROUNDCOLOR);
	sdl->solid_texture = surface_to_texture(solid, sdl->renderer);
	SDL_QueryTexture(sdl->solid_texture, NULL, NULL,
		&sdl->solid_rect.w, &sdl->solid_rect.h);
	sdl->solid_rect.x = 1420;
	sdl->solid_rect.y = 20;
}
