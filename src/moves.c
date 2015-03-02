/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 04:30:28 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/01 23:38:31 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		tab_limit(int y, int x)
{
	if (y >= 0 && x >= 0 && y <= 3 && x <= 3)
		return (1);
	return (0);
}

static int		move_block(t_all *all, t_pos dir, t_pos pos)
{
	int i;

	i = 0;
	while (tab_limit(pos.y, pos.x)
		&& tab_limit(pos.y + dir.y, pos.x + dir.x)
		&& NEXT_POS == 0)
	{
		NEXT_POS = CURENT_POS;
		CURENT_POS = 0;
		pos.y += dir.y;
		pos.x += dir.x;
		i++;
	}
	if (tab_limit(pos.y, pos.x) && tab_limit(pos.y + dir.y, pos.x + dir.x)
		&& (NEXT_POS > 0 && NEXT_POS == CURENT_POS))
	{
		i = 1;
		NEXT_POS = CURENT_POS * 2;
		if (NEXT_POS == WIN_VALUE)
			all->env.win = 1;
		all->env.score += NEXT_POS;
		CURENT_POS = 0;
		return (i);
	}
	return (i);
}

static int		init_pos_move(t_all *all, t_pos *pos, t_pos dir, int *victor)
{
	if (M_RIGHTBOT)
	{
		pos->x = MAP_SIZE - 1;
		pos->y = MAP_SIZE - 1;
		*victor = -1;
		return (1);
	}
	if (M_LEFTTOP)
	{
		pos->x = 0;
		pos->y = 0;
		*victor = 1;
		return (2);
	}
	return (-1);
}

static int		check_dir(int mode, int pos)
{
	if (mode == 1)
	{
		if (pos >= 0)
			return (1);
	}
	if (mode == 2)
	{
		if (pos < MAP_SIZE)
			return (1);
	}
	return (0);
}

void			ft_move(t_all *all, t_pos dir)
{
	t_pos	pos;
	int		mode;
	int		victor;

	mode = init_pos_move(all, &pos, dir, &victor);
	while (check_dir(mode, pos.y))
	{
		while (check_dir(mode, pos.x))
		{
			if (CURENT_POS > 0)
			{
				if (move_block(all, dir, pos))
					all->env.moved = 1;
			}
			pos.x += victor;
		}
		pos.y += victor;
		if (mode == 1)
			pos.x = MAP_SIZE - 1;
		else
			pos.x = 0;
	}
}
