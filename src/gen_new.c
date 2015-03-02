/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:41:04 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/01 22:48:15 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	gen_new_number(t_all *all)
{
	int		i;
	int		nb;
	t_pos	pos;

	i = 0;
	pos.x = 0;
	pos.y = 0;
	nb = ft_rand_a_b(1, 3);
	while (i == 0 || all->map.tab[pos.y][pos.x] != 0)
	{
		pos.y = ft_rand_a_b(0, MAP_SIZE);
		pos.x = ft_rand_a_b(0, MAP_SIZE);
		i++;
	}
	all->map.tab[pos.y][pos.x] = nb * 2;
	all->env.moved = 0;
}
