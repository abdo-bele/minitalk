/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:47:47 by aarchtou          #+#    #+#             */
/*   Updated: 2022/11/11 14:58:40 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_putchar(char c, int *len);
void	ft_puthex(unsigned int i, int *len);
int		ft_printf(const char *abdo, ...);
void	ft_puthexlong(size_t i, int *len);
void	ft_print(char *abdo, va_list arg, int *len);
void	ft_puthex1(unsigned int i, int *len);
void	ft_putnbr1(unsigned int nb, int *len);
void	ft_putnbr(int nb, int *len);
void	*ft_putstr(char *str, int *len);

#endif