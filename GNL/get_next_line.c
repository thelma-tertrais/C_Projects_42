/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttertrai <thelma.tertrais@42.learner.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:22:16 by ttertrai          #+#    #+#             */
/*   Updated: 2026/05/12 11:08:46 by ttertrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *store)
{
	char	*newline;
	int		i;

	if (!store || store[0] == '\0')
		return (NULL);
	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (store[i] == '\n')
		i++;
	newline = malloc(sizeof(char) * (i + 1));
	if (!newline)
		return (NULL);
	i = 0;
	while (store[i] && store[i] != '\n')
	{
		newline[i] = store[i];
		i++;
	}
	if (store[i] == '\n')
		newline[i++] = '\n';
	newline[i] = '\0';
	return (newline);
}

char	*clean_store(char *str)
{
	int		i;
	int		j;
	char	*store;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	store = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!store)
		return (NULL);
	j = 0;
	while (str[i])
		store[j++] = str[i++];
	store[j] = '\0';
	free (str);
	return (store);
}

char	*read_to_char(int fd, char *store)
{
	char	*buffer;
	long	read_size;
	char	*tmp;

	read_size = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_newline(store) && read_size > 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_size] = '\0';
		tmp = ft_strjoin(store, buffer);
		free(store);
		store = tmp;
	}
	free(buffer);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = read_to_char(fd, store);
	if (!store)
		return (NULL);
	result = extract_line(store);
	store = clean_store(store);
	return (result);
}

/*
int	main(void)
{
	char	*line;
	int		fd;

	fd = open("slay.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/
