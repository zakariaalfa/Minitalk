/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbendahh <zbendahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:52:00 by zbendahh          #+#    #+#             */
/*   Updated: 2023/02/28 16:16:39 by zbendahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

static void	size_bytes(void)
{
	g_reset.size = 0;
	while ((1 & (g_reset.c >> --g_reset.i)) == 1)
		g_reset.size++;
}

static void	put_in_arry(void)
{
	if (g_reset.a != 1)
	{
		size_bytes();
		g_reset.a = 1;
	}
	if (g_reset.b < g_reset.size)
	{
		g_reset.arry[g_reset.b] = g_reset.c;
		g_reset.b++;
	}
}

static void	write_(siginfo_t *info)
{
	put_in_arry();
	if (g_reset.size == 0)
	{
		g_reset.a = 0;
		write(1, &g_reset.c, 1);
	}
	else
	{
		if (g_reset.b == g_reset.size)
		{
			ft_putstr_fd(g_reset.arry, 1);
			g_reset.b = 0;
		}
	}
	if (g_reset.c == 0)
	{
		write (1, "\nMessage is sent from the PID : ", 33);
		ft_putnbr(info->si_pid);
		kill(info->si_pid, SIGUSR1);
	}
	g_reset.i = 0;
	g_reset.c = 0;
}

static void	handler(int signal, siginfo_t *info, void *ptr)
{
	(void)ptr;
	if (g_reset.pid != info->si_pid)
	{
		g_reset.i = 0;
		g_reset.c = 0;
		g_reset.a = 0;
		g_reset.b = 0;
		g_reset.pid = info->si_pid;
		ft_memset(g_reset.arry, 0, 4);
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
		write_(info);
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
