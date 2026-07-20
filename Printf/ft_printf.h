/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:05:53 by ttertrai          #+#    #+#             */
/*   Updated: 2026/05/06 17:22:01 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

size_t	print_arg(const char c, va_list args);
int		ft_printf(const char *str, ...);
size_t	print_base(ssize_t nb, char *base, size_t len_base);
size_t	ft_putnbr_base(ssize_t nb, char *base, size_t len_base, char check);
size_t	ft_putchar_cnt(const char c);
size_t	ft_putstr_cnt(const char *str);
char	*ft_strchr(const char *str, int c);

#endif
