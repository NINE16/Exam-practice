/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_exa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:00:34 by nnemeth           #+#    #+#             */
/*   Updated: 2022/07/07 15:57:49 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_putnbr(unsigned int i, int base);

char	ft_putchar(char s)
{
	return (write(1, &s, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putint(int i)
{
	int	count;

	count = 0;
	if (i < 0)
	{
		count += ft_putchar('-');
		i *= -1;
	}
	count += ft_putnbr(i, 10);
	return (count);
}

int	ft_putnbr(unsigned int i, int base)
{
	char	*base_set;
	int		count;
	int		n;

	base_set = "0123456789abcdef";
	count = 0;
	if (i / base > 0)
		count += ft_putnbr(i / base, base);
	n = i % base;
	count += ft_putchar(base_set[n]);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;
	int		i;

	i = 0;
	count = 0;
	va_start (args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				count = count + ft_putstr(va_arg(args, char *));
			if (format[i] == 'd')
				count += ft_putint(va_arg(args, int));
			if (format[i] == 'x')
				count += ft_putnbr(va_arg(args, unsigned int), 16);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
int	main(void)
{
	char	*str = "This is a string";
	char	*empty = NULL;
	int		integer = 32;
	int		hexadecimal = 32;
	ft_printf("(%s)", str);
	// ft_printf("(%s)", empty);
	ft_printf("(%d)", integer);
	ft_printf("(%x)", hexadecimal);
	return (0);
}