/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:50:07 by ggomes-v          #+#    #+#             */
/*   Updated: 2024/11/13 11:43:38 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_int(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count = ft_putnbr(n / 10);
	}
	count += ft_putchar((n % 10) + '0');
	return (count);
}
