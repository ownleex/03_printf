/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:22:52 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/23 13:05:38 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	ft_putchar_fd(c, 1);
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
			ret += ft_format(args, *(input + 1));
			input++;
		}
		else
			ret += ft_printchar(*input);
		input++;
	}
	va_end(args);
	return (ret);
}

/*
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char *str = "Test string";
	int num = 12345;
	int neg_num = -6789;
	unsigned int unum = 4294967295;
	unsigned int hexnum = 0xDEADBEEF;
	void *ptr = &num;
	
	ft_printf("Test caractere seul (c)\n");
	ft_printf("Mon printf : Hello les %c%c%c%c !\n", 'g', 'e', 'n', 's');
	printf("Vrai printf : Hello les %c%c%c%c !\n\n", 'g', 'e', 'n', 's');
	
	ft_printf("Test chaine de caracteres (s)\n");
	ft_printf("Mon printf : Hello %s gens ! %s ?\n", "les", "Comment ca va");
	printf("Vrai printf : Hello %s gens ! %s ?\n\n", "les", "Comment ca va");
	
	ft_printf("Test argument pointeur hexadecimal (p)\n");
	ft_printf("avec une string\n");
	ft_printf("Mon printf : Adresse de str : %p\n", (void *)str);
	printf("Vrai printf : Adresse de str : %p\n", (void *)str);
	ft_printf("avec un nombre\n");
	ft_printf("Mon printf : Adresse de num : %p\n", ptr);
	printf("Vrai printf : Adresse de num : %p\n\n", ptr);
	
	ft_printf("Test nombre decimal (d)\n");
	ft_printf("Mon printf : Numéro positif : %d\n", num);
	printf("Vrai printf : Numéro positif : %d\n", num);
	
	ft_printf("Test nombre decimal (i)\n");
	ft_printf("Mon printf : Numéro positif : %i\n", num);
	printf("Vrai printf : Numéro positif : %i\n", num);
	
	ft_printf("Test nombre decimal negatif (d)\n");
	ft_printf("Mon printf : Numéro négatif : %d\n", neg_num);
	printf("Vrai printf : Numéro négatif : %d\n", neg_num);
	
	ft_printf("Test nombre decimal negatif (i)\n");
	ft_printf("Mon printf : Numéro négatif : %i\n", neg_num);
	printf("Vrai printf : Numéro négatif : %i\n\n", neg_num);
	
	ft_printf("Test nombre non signé (u)\n");
	ft_printf("Mon printf : Entier non signé : %u\n", unum);
	printf("Vrai printf : Entier non signé : %u\n\n", unum);
	
	ft_printf("Test nombre hexadecimal minuscules (x)\n");
	ft_printf("Mon printf : Hexadécimal (minuscules): %x\n", hexnum);
	printf("Vrai printf : Hexadécimal (minuscules): %x\n\n", hexnum);
	
	ft_printf("Test nombre hexadecimal majuscules (X)\n");
	ft_printf("Mon printf : Hexadécimal (majuscules): %X\n", hexnum);
	printf("Vrai printf : Hexadécimal (majuscules): %X\n", hexnum);
	
	ft_printf("Test pourcentage (%%)\n");
	ft_printf("Mon printf : Pourcentage %%\n");
	printf("Vrai printf : Pourcentage %%\n");
	
	ft_printf("\n\n===== TESTS BONUS =====\n\n");
	
	ft_printf("Test flag '-' (justification gauche)\n");
	ft_printf("Mon printf : [%-10d]\n", 42);
	printf("Vrai printf : [%-10d]\n", 42);
	ft_printf("Mon printf : [%-10s]\n", "test");
	printf("Vrai printf : [%-10s]\n\n", "test");
	
	ft_printf("Test flag '0' (remplissage zeros)\n");
	ft_printf("Mon printf : [%010d]\n", 42);
	printf("Vrai printf : [%010d]\n", 42);
	ft_printf("Mon printf : [%010x]\n", 42);
	printf("Vrai printf : [%010x]\n\n", 42);
	
	ft_printf("Test flag '.' (precision)\n");
	ft_printf("Mon printf : [%.5d]\n", 42);
	printf("Vrai printf : [%.5d]\n", 42);
	ft_printf("Mon printf : [%.2s]\n", "hello");
	printf("Vrai printf : [%.2s]\n", "hello");
	ft_printf("Mon printf : [%.10d]\n", -42);
	printf("Vrai printf : [%.10d]\n\n", -42);
	
	ft_printf("Test flag '#'\n");
	ft_printf("Mon printf : [%#x]\n", 42);
	printf("Vrai printf : [%#x]\n", 42);
	ft_printf("Mon printf : [%#X]\n", 42);
	printf("Vrai printf : [%#X]\n\n", 42);
	
	ft_printf("Test flag '+'\n");
	ft_printf("Mon printf : [%+d]\n", 42);
	printf("Vrai printf : [%+d]\n", 42);
	ft_printf("Mon printf : [%+d]\n", -42);
	printf("Vrai printf : [%+d]\n\n", -42);
	
	ft_printf("Test flag ' ' (espace)\n");
	ft_printf("Mon printf : [% d]\n", 42);
	printf("Vrai printf : [% d]\n", 42);
	ft_printf("Mon printf : [% d]\n", -42);
	printf("Vrai printf : [% d]\n\n", -42);
	
	ft_printf("Test combinaisons de flags\n");
	ft_printf("Mon printf : [%#-10x]\n", 42);
	printf("Vrai printf : [%#-10x]\n", 42);
	ft_printf("Mon printf : [%+10.5d]\n", 42);
	printf("Vrai printf : [%+10.5d]\n", 42);
	ft_printf("Mon printf : [% 10.5d]\n", 42);
	printf("Vrai printf : [% 10.5d]\n", 42);
	
	ft_printf("\nTest cas speciaux bonus\n");
	ft_printf("Mon printf : [%-d] avec INT_MIN\n", -2147483647 - 1);
	printf("Vrai printf : [%-d] avec INT_MIN\n", -2147483647 - 1);
	
	return (0);
}

gcc -Wall -Wextra -Werror main.c libftprintf.a
*/
