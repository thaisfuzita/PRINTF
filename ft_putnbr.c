/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjulya-c <tjulya-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:55:42 by tjulya-c          #+#    #+#             */
/*   Updated: 2026/06/11 18:09:08 by tjulya-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long int	nbr;
	char		x;
	int			i;

	i = 0;
	nbr = n;
	if (n < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
		i++;
	}
	if (nbr >= 10)
		i += ft_putnbr(nbr / 10);
	x = (nbr % 10) + '0';
	i++;
	write(1, &x, 1);
	return (i);
}

int	ft_putunint(unsigned int n)
{
	char	x;
	int		i;

	i = 0;
	if (n >= 10)
		i += ft_putunint(n / 10);
	x = (n % 10) + '0';
	i++;
	write(1, &x, 1);
	return (i);
}
