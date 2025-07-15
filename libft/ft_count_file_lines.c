/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_file_lines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:10:20 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/15 09:04:58 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_count_file_lines(const char *file_name)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Error abriendo archivo");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}
