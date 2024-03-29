/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:23:25 by aarchtou          #+#    #+#             */
/*   Updated: 2023/01/17 11:56:34 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <string.h>
#include <stdlib.h>
#include <signal.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		b;
	long	r;

	i = 0;
	r = 0;
	b = 1;
	if (!str)
		return (0);
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			b = b * (-1);
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (r * b);
}

static void	action(int sig)
{
	static int	re = 0;

	if (sig == SIGUSR1)
		++re;
	else
		ft_printf("%d\n", re);
}

static void	en_to_server(int pid, char *str)
{
	int		i;
	char	c;
	int		a;

	a = 0;
	while (str[a])
	{
		i = 8;
		c = str[a++];
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(800);
		}
		usleep(800);
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int ac, char *av[])
{
	struct sigaction	s_sigaction;

	if (ac != 3 || !strlen(av[2]))
	{
		ft_printf("FORMAT IS INCORECT");
		return (0);
	}
	if (ft_atoi(av[1]) <= 0)
	{
		ft_printf("PID IS INCORECT");
		return (0);
	}
	ft_printf("sent    : %d\n", ft_strlen(av[2]));
	ft_printf("recived : ");
	s_sigaction.sa_handler = action;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	en_to_server(ft_atoi(av[1]), av[2]);
	return (0);
}
