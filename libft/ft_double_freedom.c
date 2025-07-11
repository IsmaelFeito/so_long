/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_freedom.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:58:55 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/11 21:34:53 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void ft_double_freedom(char ***matrix_ptr, int height)
{
    int i;
    char **matrix;

    if (!matrix_ptr || !*matrix_ptr)
        return;
    
    matrix = *matrix_ptr;
    i = 0;
    while (i < height && matrix[i] != NULL)
    {
        free(matrix[i]);
        matrix[i] = NULL;
        i++;
    }
    free(matrix);
    *matrix_ptr = NULL;
}
