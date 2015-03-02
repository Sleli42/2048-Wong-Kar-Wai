/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:37:49 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/01 23:41:04 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void		free_map(t_map *map)
{
	int i;

	i = 0;
	while (map->tab[i])
	{
		free(map->tab[i]);
		i++;
	}
	free(map->tab);
}

void			exit_normal(t_all *all)
{
	free_map(&all->map);
	endwin();
	exit(0);
}
