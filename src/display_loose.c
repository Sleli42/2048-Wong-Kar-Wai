/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_loose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:49:37 by jripoute          #+#    #+#             */
/*   Updated: 2015/03/01 23:38:42 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void		save_scores_fd(t_all *all, char *author, char *score)
{
	int		fd;
	char	*str;
	char	*str2;

	fd = open("scores.txt", O_RDWR | O_APPEND | O_CREAT, S_IRWXU);
	if (fd == -1)
	{
		ft_putstr("No file found\n");
		ft_error(NOFILE);
	}
	ft_putstr_fd(author, fd);
	ft_putstr_fd(" = ", fd);
	ft_putstr_fd(score, fd);
	ft_putstr_fd(" pts \n", fd);
}

void			display_loose(t_all *all)
{
	int		ch;
	char	*author;

	author = NULL;
	mvprintw(all->env.col - 3, all->env.row / 2 - 7,
		"You Loose ! Press ESC to quit");
	while (getch() != ECHAP)
		;
	endwin();
	ft_putstr("Enter your name : ");
	get_next_line(1, &author);
	if (author)
		save_scores_fd(all, author, ft_itoa(all->env.score));
	exit_normal(all);
}
