/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_sdl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 01:06:59 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/26 16:21:16 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

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
