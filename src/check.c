/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 20:12:09 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/01 23:20:18 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		mathias_check2(t_all *all, int *k)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j <= 3)
	{
		while (i <= 2)
		{
			if (all->map.tab[i][j] != all->map.tab[i + 1][j])
				*k += 1;
			i++;
		}
		i = 0;
		j++;
	}
}

static int		mathias_check(t_all *all)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i <= 3)
	{
		while (j <= 2)
		{
			if (all->map.tab[i][j] != all->map.tab[i][j + 1])
				k++;
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	mathias_check2(all, &k);
	return (k == 24) ? 1 : 0;
}

static int		check_valid_tab(t_all *all)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (all->map.tab[i])
	{
		while (j <= 3)
		{
			if (all->map.tab[i][j] == 0)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void			check_game_play(t_all *all)
{
	if (all->env.played)
	{
		if (check_valid_tab(all) == 0)
		{
			if (mathias_check(all) == 1)
				display_loose(all);
		}
		else if (all->env.moved)
			gen_new_number(all);
		all->env.played = 0;
	}
}
