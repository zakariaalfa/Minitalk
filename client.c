/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:58:12 by zbendahh          #+#    #+#             */
/*   Updated: 2023/02/28 16:21:23 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

static void	send(int pid, char c)
{
	int	i;

	i = 7;
	if (c < 0 || c > 127)
		return ;
	while (i >= 0)
	{
		kill(pid, (1 & (c >> i)) + SIGUSR1);
		i--;
		usleep(800);
	}
}

int	main(int ac, char **av)
{
	int		pid;
	size_t	i;

	if (ac == 3)
	{
		i = 0;
		while (i < ft_strlen(av[1]))
		{
			if (ft_isdigit(av[1][i]) != 1)
				return (write(1, "Invalid Pid.\n", 14));
			else if (ft_atoi(av[1]) < 0)
				return (write(1, "Invalid Pid.\n", 14));
			i++;
		}
		pid = ft_atoi(av[1]);
		i = 0;
		while (av[2][i])
			send(pid, av[2][i++]);
		send(pid, av[2][i]);
		return (0);
	}
	write(1, "Invalid Args.\n", 15);
	return (1);
}
