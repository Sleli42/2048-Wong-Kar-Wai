/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:59:45 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/01 23:04:38 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		main(void)
{
	t_all	all;

	init_game(&all);
	start_menu(&all);
	while (77)
	{
		displays_all(&all);
		key_hook(&all);
		check_game_play(&all);
		clear();
		refresh();
	}
	endwin();
	return (0);
}
