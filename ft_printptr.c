/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:13:43 by ayarmaya          #+#    #+#             */
/*   Updated: 2023/12/05 21:58:29 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long nbr)
{
	int	i;

	i = 0;
	if (nbr >= 16)
	{
		i += ft_puthex(nbr / 16);
		i += ft_puthex(nbr % 16);
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

int	ft_printptr(void *ptr)
{
	unsigned long long	addr;
	int					ret;

	ret = 0;
	addr = (unsigned long long)ptr;
	if (addr == 0)
		ret += ft_printstr("(nil)");
	else
	{
		ret += ft_printstr("0x");
		ret += ft_puthex(addr);
	}
	return (ret);
}
