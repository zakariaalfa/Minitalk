/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:32:19 by zbendahh          #+#    #+#             */
/*   Updated: 2023/02/26 16:16:17 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
	i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long	r;
	int		p;
	int		i;

	r = 0;
	p = 1;
	i = space(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			p = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		r = (r * 10 + str[i] - 48);
		i++;
	}
	return (r * p);
}
