/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:02:09 by ayarmaya          #+#    #+#             */
/*   Updated: 2023/12/04 19:26:27 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include ".libft/libft.h"
# include <stddef.h> // size_t
# include <string.h> // NULL
# include <unistd.h> // write
# include <stdlib.h> // malloc, free
# include <stdio.h> // printf
# include <stdarg.h> // va_list, va_start, va_arg, va_end

int		ft_printf(const char *input, ...);
int		ft_printstr(char *str);
int		ft_printptr(void *ptr);
int		ft_printint(int n);
int		ft_printuint(unsigned int n);
int		ft_printhex(unsigned int n, char c);

#endif