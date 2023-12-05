/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:13:43 by ayarmaya          #+#    #+#             */
/*   Updated: 2023/12/05 20:36:41 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long nbr)
{
	int	i;

	i = 0;
	if (nbr >= 16)
	{
		ft_puthex(nbr / 16);
		ft_puthex(nbr % 16);
	}
	else
	{
		if (nbr < 10)
			ft_putchar_fd(nbr + '0', 1);
		else
			ft_putchar_fd(nbr - 10 + 'a', 1);
		i = 1;
	}
	return (i);
}

int	ft_printptr(unsigned long *ptr)
{
	unsigned long	addr;
	int				ret;

	ret = 0;
	addr = (unsigned long)ptr;
	ret += ft_printstr("0x");
	if (addr == 0)
		ret += ft_printstr("0");
	else
		ret += ft_puthex(addr);
	return (ret);
}
