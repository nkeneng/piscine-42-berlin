/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:22:21 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/17 23:45:36 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "utils.h"

int	extract_lines(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (
			str[i + 1] == '\0'
			|| (str[i] == '\n' && (str[i + 1] != '\0' && str[i + 1] != '\n'))
		)
			count++;
		i++;
	}
	return (count);
}

ssize_t	get_file_size(const char *filePath)
{
	int		fd;
	ssize_t	file_size;
	ssize_t	bytes_read;
	char	buffer[1024];

	file_size = 0;
	fd = open(filePath, O_RDONLY);
	if (fd == -1)
	{
		return (-1);
	}
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		file_size += bytes_read;
	}
	if (bytes_read == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (file_size);
}

char	*read_file(char *file_name)
{
	int		fd;
	char	*buffer;
	ssize_t	bytes_read;
	ssize_t	file_size;

	file_size = 1024;
	buffer = malloc(file_size + 1);
	if (buffer == NULL)
	{
		ft_putstr("Malloc failed");
		free(buffer);
		return (NULL);
	}
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error opening file");
		free(buffer);
		return (NULL);
	}
	bytes_read = read(fd, buffer, file_size);
	if (bytes_read == -1)
	{
		ft_putstr("Error reading file");
		close(fd);
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	close(fd);
	return (buffer);
}
