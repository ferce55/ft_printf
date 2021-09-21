/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:25:56 by ricardo           #+#    #+#             */
/*   Updated: 2021/09/21 11:58:59 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	hex_lenght(unsigned long int n)
{
	int	count;

	count = 1;
	while (n / 16 > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static void	hex_conv(unsigned long int n, int i, char *hex, int caps)
{
	unsigned long int	aux;

	aux = 1;
	while (n != 0)
	{
		aux = n % 16;
		if (aux < 10)
			aux = aux + '0';
		else if (aux >= 10 && caps == 1)
			aux = aux + 55;
		else if (aux >= 10 && caps == 0)
			aux = aux + 87;
		hex[i--] = aux;
		n /= 16;
	}
}

char	*ft_itoh(unsigned long int n, int caps)
{
	size_t	len;
	char	*hex;

	len = hex_lenght(n);
	hex = malloc(len + 1);
	if (!hex)
		return (0);
	hex_conv(n, len - 1, hex, caps);
	if (n == 0)
		hex[len - 1] = '0';
	hex[len] = '\0';
	return (hex);
}
