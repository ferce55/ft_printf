/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:25:35 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/09/21 12:03:59 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_str(char *cad, int im)
{
	int		i;

	i = 0;
	if (!cad)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (cad[i])
	{
		write(1, &cad[i], 1);
		i++;
	}
	if (im)
		free(cad);
	return (i);
}

static char	*ft_itop(void *ptr)
{
	char	*hex;
	char	*pointer;
	size_t	len;
	size_t	i;
	size_t	j;

	hex = ft_itoh((uintptr_t)ptr, 0);
	len = ft_strlen(hex);
	pointer = malloc(len + 3);
	if (!pointer)
		return (0);
	i = 0;
	j = 0;
	ft_strlcpy(pointer, "0x", 3);
	while (pointer[i])
		i++;
	while (hex[j])
		pointer[i++] = hex[j++];
	pointer[i] = '\0';
	free(hex);
	return (pointer);
}

static int	ft_format(char c1, char c2, va_list args)
{
	int	pchar;

	pchar = 0;
	if (c1 == '%' && c2 == 'c')
		pchar = ft_putchar_fd(va_arg(args, int), 1);
	else if (c1 == '%' && c2 == 's')
		pchar = print_str(va_arg(args, char *), 0);
	else if (c1 == '%' && c2 == 'p')
		pchar = print_str(ft_itop(va_arg(args, unsigned int *)), 1);
	else if (c1 == '%' && (c2 == 'd' || c2 == 'i'))
		ft_putnbr_fd(va_arg(args, int), 1, &pchar);
	else if (c1 == '%' && c2 == 'u')
		ft_putunbr(va_arg(args, long), &pchar);
	else if (c1 == '%' && c2 == 'x')
		pchar = print_str(ft_itoh(va_arg(args, unsigned int), 0), 1);
	else if (c1 == '%' && c2 == 'X')
		pchar = print_str(ft_itoh(va_arg(args, unsigned int), 1), 1);
	else if (c1 == '%' && c2 == '%')
		pchar = ft_putchar_fd('%', 1);
	else
		pchar = -1;
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

/*void bye()
{
	system("leaks -q a.out");
}
int	main(void)
{
	int		count;
	int		c1;
	char	*str;

	str = "hola que tal";
	c1 = printf("%s hola %p\n", "  ", &c1);
	count = ft_printf("%s hola %p\n", "  ", &c1);
	printf("contador: %d | %d", count, c1);
	atexit(bye);
}*/