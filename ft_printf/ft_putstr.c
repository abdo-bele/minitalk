/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:31:36 by aarchtou          #+#    #+#             */
/*   Updated: 2022/11/11 13:04:51 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_putstr(char *str, int *len)
{
	int	a;
	int	i;

	a = 0;
	i = 0;
	if (!str)
	{
		return ((*len) += write (1, "(null)", 6), NULL);
	}
	while (str[a])
	{
		i = write (1, &str[a], 1);
		(*len)++;
		a++;
	}
	return (0);
}
