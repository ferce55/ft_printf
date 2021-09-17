/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:25:35 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/09/16 16:36:09 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdint.h>

static int	print_str(char *cad, int im)
{
	int		i;

	i = 0;
	while (cad[i])
	{
		write(1, &cad[i], 1);
		i++;
	}
	if (im)
		free(cad);
	if (!cad)
		return (6);
	return (i);
}

static int	ft_format(char c1, char c2, va_list args)
{
	int	pchar;

	pchar = -1;
	if (c1 == '%' && c2 == 'c')
		pchar = ft_putchar_fd(va_arg(args, int), 1);
	else if (c1 == '%' && c2 == 's')
		pchar = print_str(va_arg(args, char *), 0);
	else if (c1 == '%' && c2 == 'p')
		printf("implementar");
	else if (c1 == '%' && c2 == 'd' || c2 == 'i')
		ft_putnbr_fd(va_arg(args, int), 1, &pchar);
	else if (c1 == '%' && c2 == 'u')
		printf("implementar");
	else if (c1 == '%' && c2 == 'x')
		printf("implementar");
	else if (c1 == '%' && c2 == 'X')
		printf("implementar");
	else if (c1 == '%' && c2 == '%')
		pchar = ft_putchar_fd('%', 1);
	return (pchar);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	int		pchar;
	va_list	args;

	i = -1;
	count = 0;
	pchar = 0;
	va_start(args, str);
	while (str[++i])
	{
		pchar = ft_format(str[i], str[i + 1], args);
		if (pchar >= 0)
			count += pchar;
		else
		{
			write(1, &str[i], 1);
			pchar = 0;
			count++;
			i--;
		}
		i++;
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{
	int		count;
	int		c1;
	char	*str;

	str = "hola que tal";
	c1 = printf("%s hola\n", "a");
	count = ft_printf("%s hola\n", "a");
	printf("contador: %d | %d", count, c1);
}*/
