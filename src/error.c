/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 01:36:28 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/01 23:23:41 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_error(int er)
{
	endwin();
	if (er == NO_COLORS)
		ft_putstr("Your terminal don't support colors.\n");
	if (er == NOFILE)
		ft_putstr("Permission denied or no file found\n");
	exit(0);
}
