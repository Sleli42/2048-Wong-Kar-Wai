/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:59:16 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/01 23:11:50 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <form.h>
# include <stdio.h>
# include <stdlib.h>
# include <ncurses.h>
# include <strings.h>
# include "libft.h"

# define MAP_SIZE 4
# define CURENT_POS all->map.tab[pos.y][pos.x]
# define NEXT_POS all->map.tab[pos.y + dir.y][pos.x + dir.x]
# define M_RIGHTBOT (dir.x == 1 || dir.y == 1)
# define M_LEFTTOP (dir.x == -1 || dir.y == -1)

enum	e_const
{
	WIN_VALUE = 2048
};

typedef enum	e_dir
{
	TOP = 1,
	BOT,
	LEFT,
	RIGHT
}				t_dir;

typedef enum	e_keys
{
	ECHAP = 27,
	K_RIGHT = 261,
	K_LEFT = 260,
	K_UP = 259,
	K_DOWN = 258,
	K_ONE = 49,
	K_TWO = 50,
	K_THREE = 51,
}				t_keys;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef enum	e_er
{
	NOFILE,
	NO_COLORS,
	SYSCALL,
}				t_er;

typedef struct	s_env
{
	int			row;
	int			col;
	t_pos		size;
	int			theme;
	int			color_pair;
	int			played;
	int			moved;
	size_t		score;
	int			win;
}				t_env;

typedef struct	s_map
{
	int			**tab;
	int			size;
}				t_map;

typedef struct	s_all
{
	t_env		env;
	t_map		map;
}				t_all;

/*
** main.c
*/
void			choose_color_theme(t_all *all, int color);

/*
** inits.c
*/
void			init_game(t_all *all);

/*
** displays.c
*/
void			display_grid(t_all *all);

/*
** displays2.c
*/
void			display_case_nb(t_all *all, t_pos p, int i, int j);

/*
** displays3.c
*/
void			displays_all(t_all *all);

/*
** display_edges.c
*/
void			display_edges(t_all *all);

/*
** display_loose.c
*/
void			display_loose(t_all *all);

/*
** gen_new.c
*/
void			gen_new_number(t_all *all);

/*
** hook_gen.c
*/
void			key_hook(t_all *all);

/*
** check.c
*/
void			check_game_play(t_all *all);

/*
** check_resize_win.c
*/
void			check_valid_win(t_all *all);

/*
** moves.c
*/
void			ft_move(t_all *all, t_pos dir);

/*
** menu.c
*/
void			start_menu(t_all *all);

/*
** exit.c
*/
void			exit_normal(t_all *all);

/*
** error.c
*/
void			ft_error(int er);

#endif
