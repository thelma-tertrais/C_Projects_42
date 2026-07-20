/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:10:10 by ttertrai          #+#    #+#             */
/*   Updated: 2026/05/12 10:53:00 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_to_char(int fd, char *store);
char	*clean_store(char *str);
char	*extract_line(char *store);
int		ft_strlen(char *str);
int		ft_newline(char *str);
void	*ft_memcpy(void *s1, void *s2, size_t n);
char	*ft_strjoin(char *str1, char *str2);

#endif
