/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:39:36 by zbendahh          #+#    #+#             */
/*   Updated: 2023/02/28 14:53:05 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

struct	s_reset
{
	int		i;
	char	c;
	int		pid;
	int		a;
	int		b;
	int		size;
	char	arry[4];
}	g_reset;

#endif
