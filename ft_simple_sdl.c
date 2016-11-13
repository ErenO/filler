/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sdl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:18:19 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/26 18:08:46 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		ft_init_sdl_cpu(t_sdl *sdl, t_vm *vm)
{
	if (vm->visu == 1)
	{
		init_sdl_window(sdl);
	}
}

void		ft_quit_sdl_cpu(t_sdl *sdl, t_vm *vm)
{
	if (vm->visu == 1)
	{
		if (vm->dump != vm->cpu.cur_cycle)
			sdl->u = 1;
		ft_disp(sdl, vm);
		SDL_Delay(3000);
		quit(sdl);
	}
}

void		ft_check_bonus(t_vm *vm)
{
	if (vm->dump > 0 || vm->step > 0 || vm->verbose > 0 || vm->color > 0)
		vm->visu = 0;
}
