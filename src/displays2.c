/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 20:12:09 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/01 23:39:41 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void		fill_square(t_all *all, int x, int y)
{
	int i;
	int j;

	i = 0;
	attron(COLOR_PAIR(all->env.color_pair));
	while (i < all->env.size.y - 1)
	{
		j = 0;
		while (j < all->env.size.x - 1)
		{
			mvprintw(y, x, " ");
			x++;
			j++;
		}
		x -= j;
		y++;
		i++;
	}
}

static int		choose_color_case(t_all *all, int nb)
{
	if (nb == 2)
		all->env.color_pair = 4;
	else if (nb == 4)
		all->env.color_pair = 5;
	else if (nb == 8)
		all->env.color_pair = 6;
	else if (nb == 16)
		all->env.color_pair = 7;
	else if (nb == 32)
		all->env.color_pair = 8;
	else if (nb == 64)
		all->env.color_pair = 9;
	else if (nb == 128)
		all->env.color_pair = 10;
	else if (nb == 256)
		all->env.color_pair = 11;
	else if (nb == 512)
		all->env.color_pair = 12;
	else if (nb == 1024)
		all->env.color_pair = 13;
	else if (nb == 2048)
		all->env.color_pair = 14;
	else
		all->env.color_pair = 3;
}

void			display_case_nb(t_all *all, t_pos p, int i, int j)
{
	choose_color_case(all, all->map.tab[i][j]);
	fill_square(all, p.x - all->env.size.x / 2 + 1,
		p.y - all->env.size.y / 2 + 1);
	attron(A_UNDERLINE);
	if (all->map.tab[i][j])
	{
		mvprintw(p.y, (p.x - ft_intlen(all->map.tab[i][j])), "%d",
			all->map.tab[i][j]);
	}
	attroff(A_UNDERLINE | COLOR_PAIR(all->env.color_pair));
}
