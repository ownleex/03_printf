/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:15:52 by ayarmaya          #+#    #+#             */
/*   Updated: 2023/12/05 16:44:41 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(int nbr)
{
	int		len;
	char	*str;

	str = ft_itoa(nbr);
	len = ft_printstr(str);
	free(str);
	return (len);
}
