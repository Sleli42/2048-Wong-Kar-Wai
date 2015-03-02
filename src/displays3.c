/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 20:12:09 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/01 23:39:47 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void		display_victory(t_all *all)
{
	char *str;

	str = "U win !";
	mvprintw(all->env.col - 4, 5,
		"%s", str);
}

static void		display_scores(t_all *all)
{
	mvprintw(all->env.col - 3, 5,
		"Score : %d", all->env.score);
}

void			displays_all(t_all *all)
{
	getmaxyx(stdscr, all->env.col, all->env.row);
	check_valid_win(all);
	display_grid(all);
	display_scores(all);
	if (all->env.win)
		display_victory(all);
	attron(COLOR_PAIR(2));
	display_edges(all);
	attroff(COLOR_PAIR(2));
}
