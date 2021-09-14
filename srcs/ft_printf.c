/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:25:35 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/09/14 18:13:37 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdint.h>

static int	ft_format(char c1, char c2, va_list args)
{
	int	pchar;

	pchar = -1;
	if (c1 == '%' && c2 == 'c')
	{
		pchar = ft_putchar_fd(va_arg(args, int), 1);
	}
	return (pchar);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	int		pchar;
	va_list	args;

	i = 0;
	count = 0;
	pchar = 0;
	va_start(args, str);
	while (str[i])
	{
		pchar = ft_format(str[i], str[i + 1], args);
		if (pchar >= 0)
		{
			count += pchar;
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			pchar = 0;
			count++;
			//i--;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	char	c;
	char	c1;
	char	c2;
	char	c3;
	int		count;

	c = 'q';
	c1 = 'w';
	c2 = 'E';
	c3 = 'R';
	count = ft_printf("%c hola %c caracola %c%c\n", 'h', 'o', 'l', 'a');
	printf("%c hola %c caracola %c%c\n", c, c1, c2, c3);
	printf("contador: %d", count);
}
