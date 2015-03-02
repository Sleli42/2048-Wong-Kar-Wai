/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:33:03 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/01 23:39:34 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void			display_numbers(t_all *all)
{
	int		i;
	int		j;
	int		goback;
	t_pos	p;

	i = 0;
	j = 0;
	p.x = all->env.size.x / 2;
	p.y = all->env.size.y / 2;
	while (i < all->map.size)
	{
		goback = p.x;
		while (j < all->map.size)
		{
			display_case_nb(all, p, i, j);
			p.x += all->env.size.x;
			j++;
		}
		p.x = goback;
		p.y += all->env.size.y;
		j = 0;
		i++;
	}
}

static void			display_xgrid(t_all *all)
{
	int sizegrid;
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	sizegrid = all->env.row / 4;
	x = sizegrid;
	while (i < 3)
	{
		while (y < (all->env.col / 5) * 4)
		{
			mvprintw(y, x, "|");
			y++;
		}
		x += sizegrid;
		y = 0;
		i++;
	}
	all->env.size.x = sizegrid;
}

static void			display_ygrid(t_all *all)
{
	int sizegrid;
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	sizegrid = all->env.col / 5;
	x = sizegrid;
	while (i < 4)
	{
		while (y < all->env.row)
		{
			mvprintw(x, y, "-");
			y++;
		}
		x += sizegrid;
		y = 0;
		i++;
	}
	all->env.size.y = sizegrid;
}

void				display_grid(t_all *all)
{
	attron(COLOR_PAIR(2));
	display_xgrid(all);
	display_ygrid(all);
	attroff(all->env.color_pair);
	display_numbers(all);
}
