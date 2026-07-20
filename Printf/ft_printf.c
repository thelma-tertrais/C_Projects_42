/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:16:44 by ttertrai          #+#    #+#             */
/*   Updated: 2026/05/12 16:56:08 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_arg(const char c, va_list ap)
{
	int		count;
	char	*lower_hex;
	char	*upper_hex;

	count = 0;
	lower_hex = "0123456789abcdef";
	upper_hex = "0123456789ABCDEF";
	if (c == 'a')
		count += ft_putstr_cnt("slay");
	if (c == '%')
		count += ft_putchar_cnt('%');
	else if (c == 'c')
		count += ft_putchar_cnt(va_arg(ap, int));
	else if (c == 's')
		count += ft_putstr_cnt(va_arg(ap, char *));
	else if (c == 'p')
		count += ft_putnbr_base(va_arg(ap, unsigned long), lower_hex, 16, c);
	else if (c == 'd' || c == 'i')
		count += ft_putnbr_base(va_arg(ap, int), "0123456789", 10, c);
	else if (c == 'u')
		count += ft_putnbr_base(va_arg(ap, unsigned), "0123456789", 10, c);
	else if (c == 'x')
		count += ft_putnbr_base(va_arg(ap, unsigned int), lower_hex, 16, c);
	else if (c == 'X')
		count += ft_putnbr_base(va_arg(ap, unsigned int), upper_hex, 16, c);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	char	*check;
	va_list	ap;
	int		count;
	int		i;

	count = 0;
	i = 0;
	check = "acspdiuxX%";
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr(check, str[i + 1]))
		{
			count = count + print_arg(str[i + 1], ap);
			i++;
		}
		else
			count = count + ft_putchar_cnt(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
/*
#include <stdio.h>

int	main()
{

	int	test;
	char	*str;
	char	c;
	
	c = 50;
	str = &c;
	test = ft_printf("%c, %s, %d, %i, %p, %u, %x, %X, %%\n", 'c',
			"hey there", 42, -42, str, -1, 0, 4211211111, '1');
	ft_printf("%d\n", test);
	test = printf("%c, %s, %d, %i, %p, %u, %x, %X, %%\n", 'c',
			"hey there", 42, -42, str, -1, 0, 4211211111, '1');
	printf("%d", test);
	test = ft_printf("hello %a");
	ft_printf("%d\n", test);
}
*/
