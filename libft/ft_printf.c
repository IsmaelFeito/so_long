/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:03:14 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/25 01:58:00 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	letter(char c, va_list	vargs)
{
	if (c == 'c')
		return (ft_putchar(va_arg(vargs, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(vargs, char *)));
	else if (c == 'p')
		return (ft_put_ptr(va_arg(vargs, void *)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(vargs, int)));
	else if (c == 'u')
		return (ft_put_uns(va_arg(vargs, unsigned int)));
	else if (c == 'x')
		return (ft_put_hexa(va_arg(vargs, unsigned int), 1));
	else if (c == 'X')
		return (ft_put_hexa(va_arg(vargs, unsigned int), 0));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(char *str, ...)
{
	va_list	vargs;
	int		i;
	int		j;

	va_start(vargs, str);
	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			j += letter(str[i], vargs);
		}
		else
			j += ft_putchar(str[i]);
		i++;
	}
	va_end(vargs);
	return (j);
}
