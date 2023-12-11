/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:16:54 by ayarmaya          #+#    #+#             */
/*   Updated: 2023/12/11 16:49:46 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned int nbr, char c)
{
	if (nbr >= 16)
	{
		ft_puthexa(nbr / 16, c);
		ft_puthexa(nbr % 16, c);
	}
	else if (nbr < 10)
		ft_putchar_fd(nbr + '0', 1);
	else
	{
		if (c == 'x')
			ft_putchar_fd(nbr - 10 + 'a', 1);
		if (c == 'X')
			ft_putchar_fd(nbr - 10 + 'A', 1);
	}
}

int	ft_printhex(unsigned int nbr, char c)
{
	int	len;

	len = 1;
	ft_puthexa(nbr, c);
	while (nbr >= 16)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}
