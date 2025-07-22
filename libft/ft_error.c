/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 01:46:02 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/22 01:09:08 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_error(char *message)
{
	if (!message)
		return ;
	write(2, "Error:\n", 7);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
}
