/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 11:48:03 by lubaujar          #+#    #+#             */
/*   Updated: 2014/11/13 19:49:30 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	unsigned int	len_s1;
	unsigned int	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (n == 0)
		return (0);
	if (len_s1 > n)
		n = len_s1 + 1;
	if (len_s2 > n)
		n = len_s2 + 1;
	return (ft_memcmp(s1, s2, n));
}
