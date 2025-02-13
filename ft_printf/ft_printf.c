/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:48:47 by ggomes-v          #+#    #+#             */
/*   Updated: 2024/11/15 10:48:34 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_check(const char *str, va_list args)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count += ft_putchar(va_arg(args, int));
	if (*str == 's')
		count += ft_putstr(va_arg(args, char *));
	if (*str == 'd' || *str == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (*str == 'u')
		count += ft_unsigned_int(va_arg(args, unsigned int));
	if (*str == 'x' || *str == 'X')
		count += ft_hexadecimal(va_arg(args, unsigned int), *str);
	if (*str == 'p')
		count += ft_pointeraddress(va_arg(args, unsigned long));
	if (*str == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			count += ft_format_check(&format[i], args);
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end (args);
	return (count);
}
/*
int main(void)
{
    int     a = 5;
    int     *ptr = &a;
    ft_printf("FT_PRINTF:%p\n", ptr);
    printf("PRINTF:%p\n", ptr);

    ft_printf("---------->Endereo de A<---------\nFT_PRINTF:%p\n", &a);
    printf("PRINTF:%p\n", &a);
    return (0);
}

int	main()
{
	int INT_MAX = 2147483647;
	int INT_MIN = -2147483648;
	unsigned int UINT_MAX = 4294967295;
    printf("  MY: %i\n", ft_printf("%c	", 'c'));
    printf("  OR: %i\n\n",    printf("%c	", 'c'));
    printf("  MY: %i\n", ft_printf(" p %p	", (void *)321321321321321));
    printf("  OR: %i\n\n",    printf(" p %p	", (void *)321321321321321));
    printf("  MY: %i\n", ft_printf(" p %p ", (void *)0));
    printf("  OR: %i\n\n",    printf(" p %p ", (void *)0));
    printf("  MY: %i\n", ft_printf("  d %d	", 31313131));
    printf("  OR: %i\n\n",    printf("  d %d	", 31313131));
    printf("  MY: %i\n", ft_printf("   s %s	", "string"));
    printf("  OR: %i\n\n",    printf("   s %s	", "string"));
    printf("  MY: %i\n", ft_printf("    i %i	", -1));
    printf("  OR: %i\n\n",    printf("    i %i	", -1));
    printf("  MY: %i\n", ft_printf("    i %i	", INT_MIN));
    printf("  OR: %i\n\n",    printf("    i %i	", INT_MIN));
    printf("  MY: %i\n", ft_printf("    i %i	", INT_MAX));
    printf("  OR: %i\n\n",    printf("    i %i	", INT_MAX));
    printf("  MY: %i\n", ft_printf("     u %u	", UINT_MAX));
    printf("  OR: %i\n\n",    printf("     u %u	", UINT_MAX));
    printf("  MY: %i\n", ft_printf("     u %u	", 543487));
    printf("  OR: %i\n\n",    printf("     u %u	", 543487));
    printf("  MY: %i\n", ft_printf("     u %u	", 0));
    printf("  OR: %i\n\n",    printf("     u %u	", 0));
    printf("  MY: %i\n", ft_printf("      X %X	", 31));
    printf("  OR: %i\n\n",    printf("      X %X	", 31));
    printf("  MY: %i\n", ft_printf("       x %x	", 31));
    printf("  OR: %i\n\n",    printf("       x %x	", 31));
    printf("  MY: %i\n", ft_printf("only text, only text!	"));
    printf("  OR: %i\n\n",    printf("only text, only text!	"));
    printf("MY %i\n", ft_printf("MX C:%c P:%p D:%d S:%s\n", 'c', 
			    (void *)32132, 313, "str"));
    printf("OR %i\n\n", printf("MX C:%c P:%p D:%d S:%s\n", 'c', 
			    (void *)32132, 313, "str"));
    printf("MY: %i\n", ft_printf("MIX I:2%i U:%u X:%X x:%x %%\n", 
			    -313, 31313131, 31, 31));
    printf("OR: %i\n\n", printf("MIX I:2%i U:%u X:%X x:%x %%\n", 
			    -313, 31313131, 31, 31));
}*/
