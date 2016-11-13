/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_sdl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 01:25:56 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/26 16:26:55 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_render_texture_seconde(t_sdl *sdl, t_vm *vm)
{
	int i;

	i = 0;
	while (i < vm->bplr.nb_plyr)
	{
		SDL_RenderCopy(sdl->renderer, sdl->tex_play[i][0],
				NULL, &sdl->rect_player[i][0]);
		SDL_RenderCopy(sdl->renderer, sdl->tex_play[i][1],
				NULL, &sdl->rect_player[i][1]);
		SDL_RenderCopy(sdl->renderer, sdl->tex_play[i][2],
				NULL, &sdl->rect_player[i][2]);
		i++;
	}
}

void	ft_render_texture(t_sdl *sdl, t_vm *vm)
{
	int i;

	i = 0;
	SDL_RenderCopy(sdl->renderer, sdl->solid_texture, NULL, &sdl->solid_rect);
	while (i < 5)
	{
		SDL_RenderCopy(sdl->renderer, sdl->texture_tab[i],
				NULL, &sdl->texture_rect[i]);
		i++;
	}
	if (sdl->u == 1)
	{
		i = 0;
		while (i < 3)
		{
			SDL_RenderCopy(sdl->renderer, sdl->last_tex[i],
					NULL, &sdl->last_rect[i]);
			i++;
		}
		i = 0;
	}
	ft_render_texture_seconde(sdl, vm);
}

void	ft_case_color(t_vm *vm, t_sdl *sdl, int i)
{
	if (vm->data[i].pc)
		SDL_SetRenderDrawColor(sdl->renderer, 40, 209, 214, 255);
	else if (vm->data[i].num_plr == (int)vm->bplr.tab[0])
		SDL_SetRenderDrawColor(sdl->renderer, 2, 200, 22, 255);
	else if (vm->data[i].num_plr == (int)vm->bplr.tab[1])
		SDL_SetRenderDrawColor(sdl->renderer, 13, 13, 242, 255);
	else if (vm->data[i].num_plr == (int)vm->bplr.tab[2])
		SDL_SetRenderDrawColor(sdl->renderer, 228, 215, 42, 255);
	else if (vm->data[i].num_plr == (int)vm->bplr.tab[3])
		SDL_SetRenderDrawColor(sdl->renderer, 255, 0, 45, 255);
	else
		SDL_SetRenderDrawColor(sdl->renderer, 200, 200, 200, 255);
}

void	ft_render_arena(t_sdl *sdl, t_vm *vm)
{
	int x;
	int y;
	int i;

	x = 20;
	y = 20;
	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0 && i != 0)
		{
			x = 20;
			y += 20;
		}
		ft_case_color(vm, sdl, i);
		sdl->rect[i].x = x;
		sdl->rect[i].y = y;
		sdl->rect[i].w = 17;
		sdl->rect[i].h = 17;
		x += 20;
		SDL_RenderFillRect(sdl->renderer, &sdl->rect[i]);
		i++;
	}
	ft_render_texture(sdl, vm);
}
