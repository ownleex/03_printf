/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:22:52 by ayarmaya          #+#    #+#             */
/*   Updated: 2023/12/04 19:02:00 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_format(va_list args, const char c)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret += ft_printchar(va_arg(args, int));
	else if (c == 's')
		ret += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		ret += ft_printptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		ret += ft_printint(va_arg(args, int));
	else if (c == 'u')
		ret += ft_printuint(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		ret += ft_printhex(va_arg(args, unsigned int), c);
	else if (c == '%')
		ret += ft_printchar('%');
	return (ret);
}

int	ft_printf(const char *input, ...)
{
	int		ret;
	va_list	args;

	ret = 0;
	va_start(args, input);
	while (*input)
	{
		if (*input == '%')
		{
			ret += ft_format(args, input[i + 1]);
			input++;
		}
		else
			ret += ft_printchar(*input);
		input++;
	}
	va_end(args);
	return (ret);
}
