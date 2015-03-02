/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 20:12:09 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/01 23:40:09 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void		set_dir(t_pos *dir, int x, int y)
{
	dir->x = x;
	dir->y = y;
}

void			key_hook(t_all *all)
{
	int		ch;
	t_pos	dir;

	ch = getch();
	if (ch)
	{
		if (ch == ECHAP)
			exit_normal(all);
		if (ch == K_LEFT)
			set_dir(&dir, -1, 0);
		else if (ch == K_RIGHT)
			set_dir(&dir, 1, 0);
		else if (ch == K_UP)
			set_dir(&dir, 0, -1);
		else if (ch == K_DOWN)
			set_dir(&dir, 0, 1);
		all->env.played = 1;
		if (ch == K_LEFT || ch == K_RIGHT || ch == K_UP
		|| ch == K_DOWN)
			ft_move(all, dir);
	}
}
