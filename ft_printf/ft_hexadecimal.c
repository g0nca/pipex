/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:55:19 by ggomes-v          #+#    #+#             */
/*   Updated: 2024/11/13 11:39:05 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadecimal(unsigned long nbr, char str)
{
	int		count;
	char	*hexa;

	count = 0;
	if (str == 'x')
		hexa = "0123456789abcdef";
	if (str == 'X')
		hexa = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		count += ft_hexadecimal((nbr / 16), str);
		count += ft_hexadecimal((nbr % 16), str);
	}
	else
		count += ft_putchar((*(hexa + nbr)));
	return (count);
}
