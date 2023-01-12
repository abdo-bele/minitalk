/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:04:08 by aarchtou          #+#    #+#             */
/*   Updated: 2022/11/11 14:58:32 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nb0(char *h, int *len)
{
	h = "0x0";
	ft_putstr(h, len);
	return ;
}

void	ft_nb01(char *h, int *len)
{
	h = "0";
	ft_putstr(h, len);
	return ;
}

void	ft_puthex(unsigned int i, int *len)
{
	int				a;
	unsigned int	b;
	char			*h;
	char			*bas;

	h = NULL;
	if (i == 0)
		return (ft_nb01(h, len));
	b = i;
	a = 0;
	bas = "0123456789abcdef";
	while (b > 0 && a++ >= 0)
		b = b / 16;
	h = malloc(a + 1);
	h[a] = '\0';
	while (--a >= 0 && i > 0)
	{
		h[a] = bas[(i % 16)];
		i = i / 16;
	}
	ft_putstr(h, len);
	free(h);
}

void	ft_puthex1(unsigned int i, int *len)
{
	int				a;
	unsigned int	b;
	char			*h;
	char			*bas;

	h = NULL;
	if (i == 0)
		return (ft_nb01(h, len));
	b = i;
	a = 0;
	bas = "0123456789ABCDEF";
	while (b > 0 && a++ >= 0)
		b = b / 16;
	h = malloc(a + 1);
	h[a] = '\0';
	while (--a >= 0 && i > 0)
	{
		h[a] = bas[(i % 16)];
		i = i / 16;
	}
	ft_putstr(h, len);
	free(h);
}

void	ft_puthexlong(size_t i, int *len)
{
	int		a;
	size_t	b;
	char	*h;
	char	*bas;

	h = NULL;
	if (i == 0)
		return (ft_nb0(h, len));
	b = i;
	a = 0;
	bas = "0123456789abcdef";
	while (b > 0 && a++ >= 0)
		b = b / 16;
	h = malloc(a + 3);
	h[a + 2] = '\0';
	while ((--a + 2) >= 0 && i > 0)
	{
		h[a + 2] = bas[(i % 16)];
		i = i / 16;
	}
	h[0] = '0';
	h[1] = 'x';
	ft_putstr(h, len);
	free(h);
}
