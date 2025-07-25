/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 21:04:20 by ifeito-m          #+#    #+#             */
/*   Updated: 2025/07/25 01:57:47 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"


int	ft_putstr(char *s)
{
	int		i;
	int		j;
	int		result;

	i = 0;
	j = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i] != '\0')
	{
		result = ft_putchar(s[i]);
		if (result == -1)
		{
			return (-1);
		}
		j += result;
		i++;
	}
	return (j);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}

int	ft_put_uns(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_put_uns(n / 10);
		i += ft_put_uns(n % 10);
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}

int	ft_put_hexa(unsigned int n, int upper)
{
	const char	*digits;
	char		buff[9];
	int			i;
	char		count;

	if (upper == 0)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	i = 0;
	count = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while (n > 0)
	{
		buff[i++] = digits[n % 16];
		n /= 16;
	}
	while (i > 0)
	{
		ft_putchar(buff[--i]);
		count++;
	}
	return (count);
}

int	ft_put_ptr(void *p)
{
	unsigned long long	addr;
	char				buffer[19];
	const char			*hex_digits;
	int					i;
	int					length;

	hex_digits = "0123456789abcdef";
	if (p == NULL)
		return (ft_putstr("(nil)"));
	i = 18;
	addr = (unsigned long long)p;
	buffer[i--] = '\0';
	while (addr != 0)
	{
		buffer[i--] = hex_digits[addr % 16];
		addr /= 16;
	}
	buffer[i--] = 'x';
	buffer[i--] = '0';
	length = ft_putstr(&buffer[i + 1]);
	return (length);
}
