/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:44:15 by pthevaku          #+#    #+#             */
/*   Updated: 2026/06/01 10:42:23 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_conversions(int fd, va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(fd, va_arg(args, int)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr_count(fd, va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(fd, va_arg(args, char *)));
	else if (c == 'p')
		return (ft_print_ptr(fd, va_arg(args, unsigned long)));
	else if (c == 'i')
		return (ft_putchar(fd, va_arg(args, int)));
	else if (c == 'u')
		return (ft_print_unsigned(fd, va_arg(args, int)));
	else if (c == 'x')
		return ((ft_print_lower_hex(fd, va_arg(args, int))));
	else if (c == 'X')
		return (ft_print_upper_hex(fd, va_arg(args, int)));
	else if (c == '%')
		return (ft_putchar(fd, '%'));
	else if (c == 'f')
		return (ft_print_float(fd, va_arg(args, double) * 100));
	else
		return (ft_putchar(fd, c));
}

int	ft_printf(int fd, const char *n, ...)
{
	va_list	arg;
	int		i;
	int		count;

	va_start(arg, n);
	i = 0;
	count = 0;
	while (n[i])
	{
		if (n[i] == '%' && n[i + 1])
		{
			count = count + ft_check_conversions(fd, arg, n[i + 1]);
			i = i + 2;
		}
		else
		{
			count = count + ft_putchar(fd, n[i]);
			i++;
		}
	}
	va_end(arg);
	return (count);
}
/*
int	main(void)
{
	int	a;

	a = 5;
	printf("dsklkkkl %c %c %d\n\n", 'c', 'd' , 1);
	printf("%d\n", ft_printf("Cinq%c%s%d%i%u%x%pCinq",
'b' ,"cinq" ,12345, 2, 4294967295, 42, &a));
	printf("%d\n", printf("Cinq%c%s%d%i%lu%x%pCinq",
 'b' ,"cinq" ,12345, 2, 4294967295, 42, &a));


	printf("%d\n", ft_printf("\n%x      %X", 420, -429496700));
	printf("%d\n", printf("\n%x     %X", 420, -429496700));

	printf("%d\n", ft_printf("\n%p", &a));
	printf("%d\n", printf("\n%p", &a));
	printf("%d\n", ft_printf("\n%p", &a));
}*/
