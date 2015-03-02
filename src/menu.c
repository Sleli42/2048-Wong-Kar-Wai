/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 20:12:09 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/01 23:37:55 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void		put_logo(t_all *all)
{
	int y;
	int x;

	y = 2;
	x = all->env.row / 2 - 19;
	mvprintw(y, x, "  #####    ###   #        ##### ");
	mvprintw(++y, x, " #     #  #   #  #    #  #     # ");
	mvprintw(++y, x, "       # #     # #    #  #     # ");
	mvprintw(++y, x, "  #####  #     # #    #   #####  ");
	mvprintw(++y, x, " #       #     # ####### #     # ");
	mvprintw(++y, x, " #        #   #       #  #     # ");
	mvprintw(++y, x, " #######   ###        #   #####  ");
}

static void		display_menu_text(t_all *all)
{
	put_logo(all);
	display_edges(all);
	mvprintw(all->env.col / 2 - 5,
		(all->env.row / 2) - ft_strlen("1 - Play"), "1 - Play");
	mvprintw(all->env.col / 2 - 3,
		(all->env.row / 2) - ft_strlen("2 - Options") + 3, "2 - Options");
	mvprintw(all->env.col / 2 - 1,
		(all->env.row / 2) - ft_strlen("3 - Quit"), "3 - Quit");
	refresh();
}

static void		settings_menu(t_all *all)
{
	int		ch;
	int		cursory;

	cursory = 6;
	while (42)
	{
		clear();
		mvprintw(2, all->env.row / 2 - 12, "=== Settings Menu ===");
		mvprintw(cursory, all->env.row / 2 - 2 - 12, "-");
		mvprintw(6, all->env.row / 2 - 12, "Color Theme : ");
		mvprintw(6, all->env.row / 2 + 2, "%d", all->env.theme);
		refresh();
		ch = getch();
		if (ch == ECHAP)
			break ;
		if (ch == K_DOWN)
			cursory += 2;
		if (ch == K_UP)
			cursory -= 2;
	}
}

void			start_menu(t_all *all)
{
	int ch;

	while (ch != K_ONE)
	{
		display_menu_text(all);
		ch = getch();
		if (ch == ECHAP || ch == K_THREE)
			exit_normal(all);
		else if (ch == K_TWO)
			settings_menu(all);
		clear();
		refresh();
	}
}
