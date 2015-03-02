/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_edges.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:48:50 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/01 22:49:04 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		display_edges(t_all *all)
{
	int i;

	i = 0;
	while (i < all->env.row)
	{
		mvprintw(0, i, "-");
		mvprintw(all->env.col - 1, i, "-");
		i++;
	}
	i = 0;
	while (i < all->env.col)
	{
		mvprintw(i, 0, "|");
		mvprintw(i, all->env.row - 1, "|");
		i++;
	}
}
