/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:00:02 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/23 02:59:40 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void ft_print_matrix(char **matrix, int height)
{
    int i;
    int j;

    if (!matrix)
        return;
    
    i = 0;
    while (i < height)
    {
        if (matrix[i] == NULL)
            break;

        j = 0;
        while (matrix[i][j] != '\0')
        {
            write(1, &matrix[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}
