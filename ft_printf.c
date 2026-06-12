/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaisfuzita <thaisfuzita@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:55:27 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/06/12 00:16:04 by thaisfuzita      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checktype(va_list *arguments, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*arguments, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*arguments, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(*arguments, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*arguments, int)));
	else if (c == 'u')
		return (ft_putunint(va_arg(*arguments, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthexa(va_arg(*arguments, unsigned int), c));
	return (ft_putchar('%') + ft_putchar(c));
}

int	ft_printf(const char *string, ...)
{
	int		i;
	int		count;
	va_list	arguments;

	if (!string)
		return (-1);
	i = 0;
	count = 0;
	va_start(arguments, string);
	while (string[i])
	{
		if (string[i] == '%' && string[i + 1] != '\0')
		{
			i++;
			if (string[i] == '%')
				count += ft_putchar('%');
			else
				count += ft_checktype(&arguments, string[i]);
		}
		else
			count += ft_putchar(string[i]);
		i++;
	}
	va_end(arguments);
	return (count);
}
