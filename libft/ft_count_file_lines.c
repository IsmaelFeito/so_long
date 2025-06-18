/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_file_lines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:10:20 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/06/18 21:19:34 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int ft_count_file_lines(const char *file_name)
{
	int 	fd;
	int		count;
	char	*line;

	line = "";
	count = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		perror("Error abriendo archivo");
		exit(EXIT_FAILURE);
	}
	while((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	close(fd);
	return count;
}
