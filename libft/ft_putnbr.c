/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:55:47 by zbendahh          #+#    #+#             */
/*   Updated: 2023/02/25 20:36:53 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	u;

	u = n;
	if (u < 0)
	{
		u = (-1) * u;
		ft_putchar('-');
	}
	if (u >= 10)
		ft_putnbr((u / 10));
	ft_putchar(((u % 10) + '0'));
}
