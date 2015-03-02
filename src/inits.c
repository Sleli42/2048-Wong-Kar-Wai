/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 01:37:41 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/01 23:40:16 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void		check_win_value(int value)
{
	while ((value % 2 == 0) && value > 1)
		value /= 2;
	if (value == 1)
		return ;
	else
	{
		ft_putstr_fd("Bad Win Value : ", 2);
		ft_putendl_fd(ft_itoa(WIN_VALUE), 2);
		exit(1);
	}
}

static void		init_tab(t_all *all, int size)
{
	int i;

	i = 0;
	all->map.size = size;
	all->map.tab = (int **)ft_memalloc(sizeof(int *) * size + 1);
	if (!all->map.tab)
		ft_error(SYSCALL);
	while (i < size)
	{
		all->map.tab[i] = (int *)ft_memalloc(sizeof(int) * size);
		if (!all->map.tab[i])
			ft_error(SYSCALL);
		i++;
	}
	all->map.tab[i] = NULL;
}

static void		init_colors(t_all *all)
{
	start_color();
	init_pair(1, 0, COLOR_WHITE);
	init_pair(2, 0, COLOR_MAGENTA);
	init_pair(3, COLOR_BLACK, COLOR_WHITE);
	init_pair(4, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(5, COLOR_WHITE, 27);
	init_pair(6, COLOR_WHITE, COLOR_BLUE);
	init_pair(7, COLOR_WHITE, COLOR_YELLOW);
	init_pair(8, COLOR_WHITE, COLOR_RED);
	init_pair(9, COLOR_WHITE, COLOR_GREEN);
	init_pair(10, COLOR_WHITE, 93);
	init_pair(11, COLOR_WHITE, 203);
	init_pair(12, COLOR_WHITE, 53);
	init_pair(13, COLOR_WHITE, 167);
	init_pair(14, COLOR_WHITE, 54);
	all->env.theme = 0;
}

static void		init_ncurses(t_all *all)
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	curs_set(FALSE);
	noecho();
	srand(time(NULL));
	if (has_colors() == FALSE)
		ft_error(NO_COLORS);
	getmaxyx(stdscr, all->env.col, all->env.row);
}

void			init_game(t_all *all)
{
	check_win_value(WIN_VALUE);
	init_ncurses(all);
	init_colors(all);
	init_tab(all, MAP_SIZE);
	gen_new_number(all);
	gen_new_number(all);
	all->env.theme = 1;
	all->env.played = 0;
	all->env.score = 0;
	all->env.win = 0;
}
