/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:25:07 by pthevaku          #+#    #+#             */
/*   Updated: 2026/06/01 10:36:01 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(int fd, const char *n, ...);
int	ft_putchar(int fd, char c);
int	ft_putstr(int fd, char *str);
int	ft_putnbr_count(int fd, int nb);
int	ft_print_unsigned(int fd, unsigned int nb);
int	ft_print_lower_hex(int fd, unsigned int nb);
int	ft_print_upper_hex(int fd, unsigned int nb);
int	ft_print_ptr(int fd, unsigned long nb);
int	ft_print_float(int fd, double n);

#endif
