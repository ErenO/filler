/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 21:17:24 by eozdek            #+#    #+#             */
/*   Updated: 2016/11/13 21:33:26 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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


SDL_Texture		*surface_to_texture(SDL_Surface *surf, SDL_Renderer *renderer)
{
	SDL_Texture *texture;

	texture = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_FreeSurface(surf);
	return (texture);
}

void			player_texture(char *str, int nb, int j, t_sdl *sdl)
{
	if (j == 0 && nb == 0)
		sdl->player[j][nb] = TTF_RenderText_Blended(sdl->font, str, COLOR1);
	else if (j == 1 && nb == 0)
		sdl->player[j][nb] = TTF_RenderText_Blended(sdl->font, str, COLOR2);
	else if (j == 2 && nb == 0)
		sdl->player[j][nb] = TTF_RenderText_Blended(sdl->font, str, COLOR3);
	else if (j == 3 && nb == 0)
		sdl->player[j][nb] = TTF_RenderText_Blended(sdl->font, str, COLOR4);
	else
		sdl->player[j][nb] = TTF_RenderText_Blended(sdl->font, str, TEXTCOLOR);
	sdl->tex_play[j][nb] = SDL_CreateTextureFromSurface(sdl->renderer,
	sdl->player[j][nb]);
	free(str);
}

void			handle_btexture(t_sdl *sdl, t_vm *vm, SDL_Surface *texture[5])
{
	int		j;
	char	*str;

	j = 0;
	while (j < 5)
	{
		if (j == 0)
			str = ft_strjoin_clean(ft_strdup("Cycle : "),
					ft_itoa(CPU.cur_cycle));
		else if (j == 1)
			str = ft_strjoin("CYCLE_TO_DIE : ", ft_itoa(CPU.cycle2die));
		else if (j == 2)
			str = ft_strjoin("CYCLE_DELTA : ", ft_itoa(CYCLE_DELTA));
		else if (j == 3)
			str = ft_strjoin("NBR_LIVE : ", ft_itoa(vm->nbr_live));
		else if (j == 4)
			str = ft_strjoin("MAX_CHECKS : ", ft_itoa(MAX_CHECKS));
		texture[j] = TTF_RenderText_Blended(sdl->font, str, TEXTCOLOR);
		sdl->texture_tab[j] = SDL_CreateTextureFromSurface(sdl->renderer,
		texture[j]);
		free(str);
		j++;
	}
}

int				handle_player_texture(t_sdl *sdl, t_vm *vm)
{
	t_list_player	*cur;
	char			*str;
	char			*str1;
	int				j;
	int				i;

	cur = vm->bplr.lst_plyr;
	j = 0;
	i = 0;
	while (j < vm->bplr.nb_plyr)
	{
		str = ft_strjoin_clean(ft_strdup("Player "), ft_itoa(j + 1));
		str = ft_strjoin_clean(str, ft_strdup(" : "));
		str = ft_strjoin_clean(str, ft_strdup(cur->plr->name));
		player_texture(str, 0, j, sdl);
		str = ft_strdup("Last live : ");
		player_texture(str, 1, j, sdl);
		str1 = ft_itoa(cur->plr->last_live);
		player_texture(str1, 2, j, sdl);
		cur = cur->next;
		j++;
	}
	return (j);
}

void			create_text_textures(t_sdl *sdl, t_vm *vm)
{
	SDL_Surface		*solid;
	SDL_Surface		*texture[5];
	int				i;
	int				tmp;
	t_bin			*win;

	tmp = 0;
	solid = NULL;
	win = NULL;
	i = 0;
	ft_query_corewar_texture(sdl, solid);
	handle_btexture(sdl, vm, texture);
	handle_player_texture(sdl, vm);
	ft_query_base_texture(sdl);
	ft_handle_query_player(sdl, vm);
	if (sdl->u == 1)
	{
		win = who_win(vm);
		if (win->num_plyr < 0)
			tmp = (-1 * win->num_plyr);
		else
			tmp = win->num_plyr;
		create_last_texture(sdl, vm, tmp, win->prog_name);
	}
}

int		ft_setup_ttf(t_sdl *sdl)
{
	if (TTF_Init() == -1)
		ft_error("TTF Init error");
	sdl->font = TTF_OpenFont(sdl->fontname, 27);
	if (sdl->font == NULL)
		ft_error("TTF font error");
	return (1);
}

void		init_struct_sdl(t_sdl *sdl)
{
	sdl->u = 0;
	sdl->aff = 0;
	sdl->speed = 5;
	sdl->window = NULL;
	sdl->renderer = NULL;
	sdl->fontname = ft_strdup("SDL/Capture-it/Capture_it.ttf");
}

void	init(SDL_Window **window, SDL_Renderer **renderer)
{
	int x;
	int y;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_error("SDL_Init error");
	}
	x = SDL_WINDOWPOS_CENTERED;
	y = SDL_WINDOWPOS_CENTERED;
	*window = SDL_CreateWindow("SDL Window", x, y, 1800, 1500,
	SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
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

void	quit(t_sdl *sdl)
{
	SDL_DestroyRenderer(sdl->renderer);
	SDL_DestroyWindow(sdl->window);
	SDL_Quit();
}

void	init_sdl_window(t_sdl *sdl)
{
	init(&sdl->window, &sdl->renderer);
	ft_setup_ttf(sdl);
}

int		ft_disp(t_sdl *sdl, t_vm *vm)
{
	create_text_textures(sdl, vm);
	SDL_SetRenderDrawColor(sdl->renderer, 127, 127, 127, 255);
	SDL_RenderClear(sdl->renderer);
	// SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 255);
	// SDL_RenderDrawLine(sdl->renderer, 1325, 10, 1325, 1300);
	// SDL_RenderDrawLine(sdl->renderer, 1325, 10, 1750, 10);
	// SDL_RenderDrawLine(sdl->renderer, 1750, 10, 1750, 1300);
	// SDL_RenderDrawLine(sdl->renderer, 1325, 1300, 1750, 1300);
	// ft_render_arena(sdl, vm);
	SDL_RenderPresent(sdl->renderer);
	// SDL_Delay(sdl->speed);
	ft_poll_event(sdl);
	sdl->aff++;
	return (0);
}
