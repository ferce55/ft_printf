/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:33:17 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/09/16 13:13:50 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd, int *pchar)
{
	*pchar = *pchar + 1;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		*pchar = 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', fd);
		n *= -1;
	}
	if (n < 10)
	{
		ft_putchar(48 + n, fd);
		return ;
	}
	else
		ft_putnbr_fd(n / 10, fd, pchar);
	ft_putnbr_fd(n % 10, fd, pchar);
}
