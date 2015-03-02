/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_resize_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:40:09 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/01 22:59:40 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	check_valid_win(t_all *all)
{
	if (all->env.col < 17 || all->env.row < 41)
	{
		while (all->env.col < 17 || all->env.row < 41)
		{
			clear();
			getmaxyx(stdscr, all->env.col, all->env.row);
			mvprintw(all->env.col / 2, all->env.row / 2,
				"Insufisant win size");
			mvprintw(all->env.col - 3, all->env.row / 2,
				"x = %d, y = %d", all->env.row, all->env.col);
			refresh();
			sleep(1);
		}
	}
}
