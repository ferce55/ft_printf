/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:33:17 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/09/18 16:06:07 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd, int *l)
{
	*l = *l + 1;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		*l = 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd, l);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd, l);
			ft_putchar(n % 10 + '0', fd);
		}
		else
			ft_putchar(n + '0', fd);
	}
}
