/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:00:02 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/08 23:36:15 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_print_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
	{
		ft_putstr_fd("(null)\n", 1);
		return ;
	}
	while (matrix[i])
	{
		ft_putstr_fd(matrix[i++], 1);
	}
}
