/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 03:17:11 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/26 17:50:52 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		init_struct_sdl(t_sdl *sdl)
{
	sdl->u = 0;
	sdl->aff = 0;
	sdl->speed = 5;
	sdl->window = NULL;
	sdl->renderer = NULL;
	sdl->fontname = ft_strdup("SDL/Capture-it/Capture_it.ttf");
}

SDL_Color	ft_color_player(int color)
{
	if (color == 1)
		return (COLOR1);
	else if (color == 2)
		return (COLOR2);
	else if (color == 3)
		return (COLOR3);
	else if (color == 4)
		return (COLOR4);
	return (COLOR1);
}

void		create_last_texture(t_sdl *sdl, t_vm *vm, int tmp, char *win)
{
	SDL_Surface		*last[3];
	char			*str;
	int				i;

	i = 0;
	(void)vm;
	while (i < 3)
	{
		if (i == 0)
			str = ft_strjoin("Contestant ", ft_itoa(tmp));
		else if (i == 1)
			str = ft_strjoin(win, ",");
		else if (i == 2)
			str = ft_strdup("has won !");
		last[i] = TTF_RenderText_Blended(sdl->font, str, ft_color_player(tmp));
		sdl->last_tex[i] = surface_to_texture(last[i], sdl->renderer);
		SDL_QueryTexture(sdl->last_tex[i], NULL, NULL,
		&sdl->last_rect[i].w, &sdl->last_rect[i].h);
		sdl->last_rect[i].x = sdl->solid_rect.x - 50;
		sdl->last_rect[i].y = 1000 + (i * 50);
		i++;
	}
}

void		ft_poll_event(t_sdl *sdl)
{
	while (SDL_PollEvent(&sdl->event))
	{
		if (sdl->event.type == SDL_QUIT
			|| sdl->event.key.keysym.sym == SDLK_ESCAPE)
		{
			TTF_CloseFont(sdl->font);
			quit(sdl);
			if (sdl->u == 0)
				exit(0);
			else
				sdl->u = 0;
		}
		else if (sdl->event.key.keysym.sym == SDLK_KP_PLUS)
			sdl->speed -= (sdl->speed - 1) >= 0 ? 1 : 0;
		else if (sdl->event.key.keysym.sym == SDLK_KP_MINUS)
			sdl->speed += (sdl->speed + 1) < 6 ? 1 : 0;
	}
}
