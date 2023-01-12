/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:31:19 by aarchtou          #+#    #+#             */
/*   Updated: 2022/11/11 19:07:23 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(char *abdo, va_list arg, int *len)
{
	if (*abdo == 'd')
		ft_putnbr(va_arg(arg, int), len);
	if (*abdo == 's')
		ft_putstr(va_arg(arg, char *), len);
	if (*abdo == 'c')
		ft_putchar(va_arg(arg, int), len);
	if (*abdo == 'p')
		ft_puthexlong(va_arg(arg, size_t), len);
	if (*abdo == 'i')
		ft_putnbr(va_arg(arg, int), len);
	if (*abdo == 'x')
		ft_puthex(va_arg(arg, unsigned int), len);
	if (*abdo == 'X')
		ft_puthex1(va_arg(arg, unsigned int), len);
	if (*abdo == 'u')
		ft_putnbr1(va_arg(arg, unsigned int), len);
	if (*abdo == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *abdo, ...)
{
	va_list	arg;
	int		i;
	int		t;

	i = 0;
	t = 0;
	va_start(arg, abdo);
	while (abdo[i])
	{
		if (abdo[i] == '%')
		{
			ft_print((char *)&abdo[i + 1], arg, &t);
			i++;
		}
		else
			ft_putchar(abdo[i], &t);
		i++;
	}
	va_end(arg);
	return (t);
}
