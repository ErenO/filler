/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:56:52 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/31 10:00:32 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "struct_types.h"
# include "../../libft/ft_printf.h"
# include "op.h"
# include "process.h"
# include "reverse_octet.h"
# include "player.h"
# include "ir.h"
# include "vm_init.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define BPLR vm->bplr
# define CPU vm->cpu
# include <SDL2/SDL.h>
# include "../../SDL/SDL2_image.framework/Headers/SDL_image.h"
# include "../../SDL/SDL2_ttf.framework/Headers/SDL_ttf.h"
# define FALSE 0
# define TRUE 1
# define TEXTCOLOR (SDL_Color){255, 255, 255, 255}
# define BACKGROUNDCOLOR (SDL_Color){0, 0, 0, 255}
# define COLOR1 (SDL_Color){2, 200, 22, 255}
# define COLOR2 (SDL_Color){13, 13, 242, 255}
# define COLOR3 (SDL_Color){228, 215, 42, 255}
# define COLOR4 (SDL_Color){255, 0, 45, 255}

struct				s_cpu
{
	int				cur_cycle;
	int				cycle_to_check;
	int				cycle2die;
	int				nbchecks;
};

struct				s_octet
{
	int				num_plr;
	int				pc;
};

struct				s_vm
{
	int				dump;
	int				step;
	int				aff;
	int				verbose;
	int				color;
	int				visu;
	int				l_core;
	t_cpu			cpu;
	unsigned char	core[MEM_SIZE];
	t_octet			data[MEM_SIZE];
	t_base_player	bplr;
	int				nb_proc;
	t_process		*proc;
	int				num_last_plr_live;
	int				nbr_live;
	void			(*ftab[17])(t_vm*, t_process*);
};

struct				s_sdl
{
	int				u;
	int				aff;
	int				speed;
	char			*fontname;
	SDL_Rect		solid_rect;
	SDL_Rect		last_rect[3];
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	TTF_Font		*font;
	SDL_Rect		texture_rect[10];
	SDL_Rect		rect_player[4][3];
	SDL_Texture		*solid_texture;
	SDL_Texture		*last_tex[3];
	SDL_Texture		*texture_tab[10];
	SDL_Texture		*tex_play[4][3];
	SDL_Surface		*player[4][3];
	SDL_Event		event;
	SDL_Rect		rect[4096];
};

void				print_core(t_vm *vm);
int					ft_check_args(char *av);
int					ft_is_number(char *str);
int					ft_stock_dump(char **av, int *i, t_vm *vm);
int					ft_stock_color(t_vm *vm);
int					ft_stock_step(char **av, int *i, t_vm *vm);
int					ft_stock_verb(char **av, int *i, t_vm *vm);
int					ft_stock_aff(t_vm *vm);
int					ft_stock_verbose(char **av, int *i, t_vm *vm);
void				ft_check_other_num(t_base_player *bplr);

/*
** init
*/

t_process			*ft_add_link(t_process *proc, int plr, int pc,\
	t_process *father);
void				ft_init_pc(int plr, int pc, t_vm *vm, t_process *proc);
int					ft_init_lst_proc(t_vm *vm);
int					copy_plr(t_vm *vm, t_bin *plr, int i);
int					ft_init_arena(t_vm *vm);

/*
** init_2
*/
int					ft_init_proc(t_bin	*plr, t_process *proc);
void				vm_init(t_vm *vm);
int					ftab_init(t_vm *vm);
void				core_zero(t_vm *vm);

/*
** ft_init_arena
*/
int					ft_init_arena(t_vm *vm);

/*
** ft_check_champion.c
*/

void				ft_open_champion(char *line, t_bin *plr);

/*
** ft_stock_champion.c
*/

void				ft_stock_program(int fd, t_bin *plr);
void				ft_stock_comment(int fd, t_bin *plr);
void				ft_stock_prog_size(int fd, char *buff, t_bin *plr);
void				ft_stock_name(int fd, t_bin *plr);
void				ft_stock_magic(int fd, char *buff, t_bin *plr);

/*
** ft_handle.c
*/

void				ft_handle_args(int ac, char **av, t_vm *vm);
int					ft_check_args(char *av);
void				ft_handle_bonus(char **av, int *i, t_vm *vm);
void				ft_mem_champs(t_base_player *player, char *av);
int					ft_stock_num_plr(char **av, int *i, t_vm *vm);

/*
** ft_memrev.c
*/

void				memrev(char *buf, size_t count);

/*
** ft_print_champion.c
*/

void				print_prog(t_bin plr);
void				print_magic(t_bin plr, char *buff);
void				print_prog_name(t_bin plr);
void				print_prog_size(t_bin plr, char *buff);
void				print_comment(t_bin plr);

/*
** cpu.c
*/
int					cpu(t_vm *vm, t_sdl *sdl);
void				exec_proc(t_vm *vm, t_process *proc);
int					stock_types_args(t_process *proc, int i);
int					decode_ir(t_process *proc);
int					fetch_ir(t_process *tmp, unsigned char *core);
int					parse_proc(t_vm *vm);

/*
** ocp.c
*/
int					check_code(unsigned char ocp, int idx);
int					stock_code_args(t_ir *pir, unsigned char ocp, int u, int i);
int					j_init(int i, t_ir *pir, int *j);
int					get_args(t_process *proc, t_vm *vm);
int					check_ocp(unsigned char *ir, t_ir *pir);

/*
** stock_types.c
*/

int					stock_reg(t_process *proc, int i);
int					stock_dir(t_process *proc, int i);
int					stock_ind(t_process *proc, int i);

/*
** put_mem.c
*/

void				put_mem(t_vm *vm, t_process *proc, int off, int val);
void				put_memlong(t_vm *vm, t_process *proc, int val);

/*
** get_mem.c
*/

int					get_mem(t_vm *vm, int idx, int off);
int					get_mem_idx(t_vm *vm, short int idx, short int off);
int					get_memlong(t_vm *vm, int idx);
int					get_memlong_idx(t_vm *vm, short int idx);

/*
** ft_store.c
*/

void				ft_st(t_vm *vm, t_process *proc);
void				ft_sti(t_vm *vm, t_process *proc);

/*
** ft_load.c
*/

void				ft_ld(t_vm *vm, t_process *proc);
void				ft_lld(t_vm *vm, t_process *proc);
void				ft_ldi(t_vm *vm, t_process *proc);
void				ft_lldi(t_vm *vm, t_process *proc);

/*
** ft_aff.c
*/

void				ft_aff(t_vm *vm, t_process *proc);

/*
** ft_b, t_process *procasic_functions.c
*/
void				ft_add(t_vm *vm, t_process *proc);
void				ft_sub(t_vm *vm, t_process *proc);
void				ft_or(t_vm *vm, t_process *proc);
void				ft_xor(t_vm *vm, t_process *proc);
void				ft_and(t_vm *vm, t_process *proc);

void				ft_zjmp(t_vm *vm, t_process *proc);
void				ft_fork(t_vm *vm, t_process *proc);
void				ft_lfork(t_vm *vm, t_process *proc);

void				ft_live(t_vm *vm, t_process *proc);

/*
** ft_fetch_next.c
*/
void				ft_fetch_next(t_vm *vm, t_process *proc);

void				ft_print(t_vm *vm);
int					check_cycle(t_vm *vm);

void				print_t_proc(t_vm *vm);

/*
** ft_wait
*/
int					ft_wait(void);
int					to_kill_or_not_to_kill_proc(t_vm *vm);
void				ft_print_operations(t_process *proc, int arg[3]);
void				ft_print_header(t_vm *vm);

/*
** ft_display_arena
*/

int					ft_disp(t_sdl *sdl, t_vm *vm);
void				init_sdl_window(t_sdl *sdl);
void				quit(t_sdl *sdl);
int					ft_setup_ttf(t_sdl *sdl);
void				init(SDL_Window **window, SDL_Renderer **renderer);

/*
** ft_visu
*/

void				display_winner(t_sdl *sdl, t_vm *vm);
void				init_struct_sdl(t_sdl *sdl);
SDL_Color			ft_make_color(Uint8 r, Uint8 g, Uint8 b);
SDL_Color			ft_color_player(int color);
void				display_first(t_sdl *sdl, t_vm *vm);
void				ft_poll_event(t_sdl *sdl);
/*
** ft_query_sdl
*/

void				ft_query_corewar_texture(t_sdl *sdl, SDL_Surface *solid);
void				ft_query_base_texture(t_sdl *sdl);
void				ft_handle_query_player(t_sdl *sdl, t_vm *vm);
void				ft_query_player_texture(int i, int j, int nb, t_sdl *sdl);

/*
** ft_render_sdl
*/
void				ft_render__texture_seconde(t_sdl *sdl, t_vm *vm);
void				ft_render_texture(t_sdl *sdl, t_vm *vm);
void				ft_case_color(t_vm *vm, t_sdl *sdl, int i);
void				ft_render_arena(t_sdl *sdl, t_vm *vm);

/*
** ft_texture_sdl
*/

SDL_Texture			*surface_to_texture(SDL_Surface *surf,\
	SDL_Renderer *renderer);
void				player_texture(char *str, int nb, int j, t_sdl *sdl);
void				handle_btexture(t_sdl *sdl, t_vm *vm,\
	SDL_Surface *texture[5]);
int					handle_player_texture(t_sdl *sdl, t_vm *m);
void				create_text_textures(t_sdl *sdl, t_vm *vm);
void				create_last_texture(t_sdl *sdl, t_vm *vm,\
	int tmp, char *win);
void				create_first_texture(t_sdl *sdl, t_vm *vm);

/*
** main
*/
void				ft_print(t_vm *vm);
void				print_corepc(t_octet *core);
void				print_t_vm(t_vm *vm);
void				print_t_bplr(t_base_player *bplr);
void				print_t_plr(t_list_player *lplr);
void				print_core(t_vm *vm);

/*
** ft_simple_sdl
*/
void				ft_init_sdl_cpu(t_sdl *sdl, t_vm *vm);
void				ft_quit_sdl_cpu(t_sdl *sdl, t_vm *vm);
void				ft_check_bonus(t_vm *vm);

/*
** ft_print_winner
*/
t_bin				*who_win(t_vm *vm);
void				print_corenum_plr(t_octet *core);
void				print_options(void);
void				print_finish(t_vm *vm);

int					ft_stock_l_core(char **av, int *i, t_vm *vm);
#endif
