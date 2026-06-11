/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:55:38 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/06/11 18:38:37 by tjulya-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int nbr, char c)
{
	int		i;
	char	*base;

	i = 0;
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr >= 16)
		i += ft_puthexa(nbr / 16, c);
	i++;
	write(1, &base[nbr % 16], 1);
	return (i);
}

int	ft_putlonghexa(unsigned long nbr)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
		i += ft_putlonghexa(nbr / 16);
	i++;
	write(1, &base[nbr % 16], 1);
	return (i);
}

int	ft_putptr(void *ptr)
{
	unsigned long	p;
	int				i;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	p = (unsigned long)ptr;
	write(1, "0x", 2);
	i = 2;
	i += ft_putlonghexa(p);
	return (i);
}
