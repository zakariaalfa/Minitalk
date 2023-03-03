/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:41:49 by zbendahh          #+#    #+#             */
/*   Updated: 2023/02/26 16:21:49 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

static void	handler(int signal, siginfo_t *info, void *ptr)
{
	(void)ptr;
	if (g_reset.pid != info->si_pid)
	{
		g_reset.i = 0;
		g_reset.c = 0;
		g_reset.pid = info->si_pid;
		write(1, "\n", 1);
	}
	if (signal == SIGUSR1)
		g_reset.c = g_reset.c << 1;
	else if (signal == SIGUSR2)
	{
		g_reset.c = g_reset.c << 1;
		g_reset.c = g_reset.c | 1;
	}
	if (g_reset.i++ == 7)
	{
		write(1, &g_reset.c, 1);
		g_reset.i = 0;
		g_reset.c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	write(1, "The PID : ", 11);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
