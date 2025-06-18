/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:23:59 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/06/18 13:00:20 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_strc_map(char ***map, char **temp_map, int matrix_len)
{
	int i;

	i = 0;
	*map = malloc(sizeof(char *) * matrix_len);
	if (!*map)
	{
		ft_putstr_fd("Error malloc alocation\n", 2);
		exit (1);
	}
	while(i < matrix_len - 1 && temp_map[i] != NULL)
	{
		(*map)[i] = ft_strdup(temp_map[i]);
		if(!(*map)[i])
		{
			ft_putstr_fd("Error malloc copyng\n", 2);
			while (i-- > 0)
				free((*map)[i]);
			freedom((void **) (*map));
			exit(1);
		}
		i++;
	}
	(*map)[i] = NULL;
}
